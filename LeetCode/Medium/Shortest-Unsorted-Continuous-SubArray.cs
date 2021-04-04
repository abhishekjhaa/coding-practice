/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103067/Python-O(N)-with-O(1)-space-complexity.-No-sorting

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?
*/

public class Solution {
    public int FindUnsortedSubarray(int[] nums) {
        if(nums.Length < 2)
        {
            return 0;
        }
        
        int left = 0, right = nums.Length - 1;
        while(left < nums.Length - 1 && nums[left] <= nums[left+1])
        {   
            left++;
        }
        while(right > 0 && nums[right] >= nums[right-1])
        {
            right--;
        }
        
        if(left > right)
            return 0;
        
        int min = Int32.MaxValue, max = Int32.MinValue, l = left, r = right + 1;
        while(l <= r && l < nums.Length)
        {
            //Console.WriteLine(l.ToString() + " " + r.ToString());
            min = Math.Min(nums[l], min);
            max = Math.Max(nums[l], max);
            l++;
        }
        
        while(left > 0 && nums[left-1] > min)
        {
            left--;
        }
        while(right < nums.Length - 1 && nums[right+1] < max)
        {
            right++;
        }
        
        return right - left + 1;
    }
}