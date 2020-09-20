'''
https://leetcode.com/problems/sort-list/
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
'''
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        '''
        The basic idea is to do a merge sort on the list.
        In merge sort you find the middle of the list and then recurse for each half
        and then merging the both half and returning the solution
        This will be in O(nLogn) time and 0(n) space
        
        
        Merge sort can also be done iteratively which will reduce the memory complexity to O(1)
        https://www.youtube.com/watch?v=WVl2QSe4R14&feature=youtu.be&list=PLRdD1c6QbAqJn0606RlOR6T3yUqFWKwmX
        http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/merge-sort5.html
        For iterative solution we need to divide the list of size 1 in 1st iteration and then merge the adjacent nodes
        in the 2nd iteration the list size will be 2 and we'll be merging 2 adjacent list of size 2.
        in the 3rd iteration the list size will be 4 and we'll be merging 2 adjacent list of size 4.
        '''
        
        def mergeRecursive(left, right):
            if not left and right:
                return None
            if not left:
                return right
            if not right:
                return left
            if left.val > right.val:
                left, right = right, left
            head = left
            current = left
            left = left.next
            while left and right:
                if left.val < right.val:
                    current.next = left
                    left = left.next
                else:
                    current.next = right
                    right = right.next
                current = current.next
            if left:
                current.next = left
            else:
                current.next = right
            return head
        
        def mergeIterative(left, right, head):
            current = head
            while(left and right):
                if left.val < right.val:
                    current.next, left = left, left.next
                else:
                    current.next, right = right, right.next
                current = current.next
            
            current.next = left if left is not None else right
            while current.next is not None: current = current.next
            return current
            
        
        def split(head, size):
            if not head:
                return None
            count = 0
            prev = head
            while count < size and head:
                prev = head
                head = head.next
                count = count + 1
            prev.next = None
            return head
                   
        if not head or not head.next:
            return head
        current = head
        length = 0
        while current:
            current = current.next
            length = length + 1
        size = 1
        left = head
        #created a dummy node to track the head of the list
        dummy = ListNode(0)
        dummy.next = head
        while size < length:
            current = dummy.next
            prev = dummy
            while current:
                left = current
                right = split(left, size)
                current = split(right, size)
                prev = mergeIterative(left, right, prev)
            size = size << 1
        return dummy.next
            
        '''
        #Recursive Solution:
        fast = head
        slow = head
        prev = ListNode(0)
        prev.next = head
        temp = prev
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            prev = prev.next
        prev.next = None
        temp.next = None
        return mergeRecursive(self.sortList(head), self.sortList(slow))
        '''
        
        