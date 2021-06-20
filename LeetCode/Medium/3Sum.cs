/*
https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var result = new List<IList<int>>();
        Array.Sort(nums);
        for(var k = nums.Length - 1; k >= 0; k--)
        {
            if(k < nums.Length - 1 && nums[k] == nums[k + 1])
            {
                continue;
            }
            var i = 0;
            var j = k - 1;
            while(j > i)
            {
                var target = nums[i] + nums[j] + nums[k];
                if(target > 0)
                {
                    j--;
                }
                else if(target < 0)
                {
                    i++;
                }
                else
                {
                    result.Add(new List<int>{nums[i],nums[k],nums[j]});
                    while(i + 1 < j && nums[i] == nums[i + 1])
                    {
                        i++;
                    }
                    while(j - 1 > i && nums[j] == nums[j - 1])
                    {
                        j--;
                    }
                    i++;
                    j--;
                }
            }
        }
        
        return result;
        
    }
}