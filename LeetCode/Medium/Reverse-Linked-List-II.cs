/*
https://leetcode.com/problems/reverse-linked-list-ii/discuss/1316155/C-Recursive-Solution
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
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
    public ListNode ReverseBetween(ListNode head, int left, int right) {
        var start = head;
        ListNode pre = null;
        var i = 0;
        while(start != null && i < left - 1)
        {
            pre = start;
            start = start.next;
            i++;
        }
        
        var (newHead, n) = ReverseListRecursive(start, null, right - left);
        start.next = n;
        if(pre != null)
        {
            pre.next = newHead;
            return head;
        }
        
        return newHead;
        
    }
    
    private (ListNode, ListNode) ReverseListRecursive(ListNode head, ListNode prev, int count) {
        if(head.next == null || count == 0)
        {
            var nxt = head.next;
            head.next = prev;
            return (head, nxt);
        }

        var (newHead, n) = ReverseListRecursive(head.next, head, count - 1);
        head.next = prev;
        return (newHead, n);
    }
}