# https://leetcode.com/problems/merge-k-sorted-lists/
# You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

# Merge all the linked-lists into one sorted linked-list and return it.

 

# Example 1:

# Input: lists = [[1,4,5],[1,3,4],[2,6]]
# Output: [1,1,2,3,4,4,5,6]
# Explanation: The linked-lists are:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# merging them into one sorted list:
# 1->1->2->3->4->4->5->6
# Example 2:

# Input: lists = []
# Output: []
# Example 3:

# Input: lists = [[]]
# Output: []
 

# Constraints:

# k == lists.length
# 0 <= k <= 10^4
# 0 <= lists[i].length <= 500
# -10^4 <= lists[i][j] <= 10^4
# lists[i] is sorted in ascending order.
# The sum of lists[i].length won't exceed 10^4.

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) < 1:
            return None
        hp = []
        for i in range(0, len(lists)):
            if lists[i] is not None:
                heapq.heappush(hp, (lists[i].val, lists[i]))
        if len(hp) < 1:
            return None
        t = heapq.heappop(hp)
        result = t[1]
        if result.next is not None:
            heapq.heappush(hp, (result.next.val, result.next));
            result.next = None
        print(result.val)
        head = result
        while len(hp) > 0:
            t = heapq.heappop(hp)
            node = t[1]
            print(node.val)
            if node.next is not None:
                heapq.heappush(hp, (node.next.val, node.next));
                node.next = None
            result.next = node
            result = node
        return head