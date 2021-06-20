/*
https://leetcode.com/problems/palindrome-linked-list/
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
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
    public bool IsPalindrome(ListNode head) {
        var mid = head;
        var fast = head;
        var midCount = 0;
        var pre = head;
        var c = head;
        var tc = 0;
        while(c != null)
        {
            c = c.next;
            tc++;
        }
        
        while(fast != null && fast.next != null)
        {
            pre = mid;
            mid = mid.next;
            fast = fast.next.next;
            midCount++;
        }
        
        if(tc%2 == 1)
        {
            mid = mid.next;
        }
        
        pre.next = null;
        pre = pre.next;
        
        while(mid != null)
        {
            var next = mid.next;
            mid.next = pre;
            pre = mid;
            mid = next;
        }
        
        while(head != null && pre != null)
        {
            if(head.val != pre.val)
            {
                return false;
            }
            
            head = head.next;
            pre = pre.next;
        }
        
        return true;
    }
    
}