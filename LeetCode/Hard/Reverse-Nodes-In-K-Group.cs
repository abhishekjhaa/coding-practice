/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode ReverseKGroup(ListNode head, int k) {
        var node = new ListNode();
        node.next = head;
        var dummy = node;
        var previous = dummy;
        node = node.next;
        while(node != null)
        {
            int right =  0;
            var curr = node;
            while(right < k && curr != null)
            {
                curr = curr.next;
                right++;
            }
            
            var pre = curr;
            curr = node;
            var preInNextIteration = node;
            if(right == k)
            {
                while(right > 0)
                {
                    var nxt = curr.next;
                    curr.next = pre;
                    pre = curr;
                    curr = nxt;
                    right--;
                }
                
                previous.next = pre;
                node = curr;
                previous = preInNextIteration;
            }
            else
            {
                break;
            }
            
        }
        
        return dummy.next;
    }
}
