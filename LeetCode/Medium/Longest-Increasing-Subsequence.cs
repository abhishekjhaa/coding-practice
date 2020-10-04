/*
https://leetcode.com/problems/longest-increasing-subsequence/
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/
public class Solution {
    private static int maxCount = 1;
    public int LengthOfLIS(int[] nums) {
        if(nums.Length == 0)
        {
            return 0;
        }
        int[] dp = Enumerable.Repeat(1, nums.Length).ToArray();
        var max = 1;
        for (var i = 1; i < nums.Length; i++)
        {
            for(var j = 0; j < i; j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i] = Math.Max(dp[i], dp[j]+1);
                    max = Math.Max(max, dp[i]);
                }
            }
        }
        
        return max;
        /*
        maxCount = 1;
        for(var i = 0; i < nums.Length; i++)
        {
            LISHelper(nums, i, i, 1);
        }
        
        return maxCount;
        */
    }
    
    private void LISHelper(int[]nums, int startIndex, int lastIndex, int count)
    {
        
        for(var i = lastIndex+1; i < nums.Length; i++)
        {
            if(nums[i]>nums[startIndex] && nums[i]>nums[lastIndex])
            {
                count++;
                LISHelper(nums, startIndex, i, count);
                maxCount = Math.Max(maxCount, count);
                count--;
            }
            
        }
    }
}