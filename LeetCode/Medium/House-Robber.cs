/*
https://leetcode.com/problems/house-robber/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

public class Solution {
    private Dictionary<int, int> dict;
    public int Rob(int[] nums) {
        if (nums.Length < 1)
            return 0;
        if (nums.Length == 1)
            return nums[0];
        
        return RobLocalDP(nums);
        //dict = new Dictionary<int, int>();
        //return RobLocal(nums, 0);
    }
    
    private int RobLocal(int[] nums, int start) 
    {
        if (start >= nums.Length)
        {
            return 0;
        }
        
        if(dict.ContainsKey(start))
        {
            return dict[start];
        }
        
        var robAdjacent = RobLocal(nums, start+1);
        var robNextToNext = RobLocal(nums, start+2);
        var robbed = Math.Max(nums[start] + robNextToNext, robAdjacent);
        if(!dict.ContainsKey(start))
        {
            dict[start] = robbed;
        }
        
        return robbed;
    }
    
    private int RobLocalDP(int[] nums) 
    {
        var dp = new int[nums.Length];
        dp[0] = nums[0];
        dp[1] = Math.Max(nums[1], dp[0]);
        for(var i = 2; i < nums.Length; i++)
        {
            dp[i] = Math.Max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        return dp[nums.Length-1];
    }
}