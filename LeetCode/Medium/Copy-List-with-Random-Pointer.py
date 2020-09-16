'''
https://leetcode.com/problems/copy-list-with-random-pointer/
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.
'''
"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        '''
        Idea is to create a clone of each node
        and putting the new node as next of node
        traverse the list with added new node and
        for new nodes added point the random to the
        previous.random.next
        removed the links of cloned from original
        '''
        if head is None:
            return None
        
        start = head
        while start is not None:
            node = Node(start.val)
            temp = start.next
            start.next = node
            node.next = temp
            start = temp
        start = head
        while start is not None and start.next is not None:
            if start.random is not None:
                start.next.random = start.random.next
            start = start.next.next
        start = head
        result = head.next
        cloned = head.next
        while start is not None:
            start.next = cloned.next
            if cloned.next is not None:
                cloned.next = cloned.next.next
            else:
                cloned.next = None
            start = start.next
            cloned = cloned.next
        return result