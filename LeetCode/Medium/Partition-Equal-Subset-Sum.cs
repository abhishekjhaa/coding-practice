/*
https://leetcode.com/problems/partition-equal-subset-sum/submissions/
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

public class Solution {
    public bool CanPartition(int[] nums) {
        /* This looks like a combination problem
        sum should be equal in both the subsets
        this means sum of all the numbers in the set should be divisible by 2
        hence each set will have sum of sumOfSet/2
        if we find a combination of numbers which gets us this result then we can return true
        this selection can be made by choosing a number of leaving number and 
        then iterate over the next set of numbers
        */
        var sum = 0;
        foreach(var num in nums)
        {
            sum += num;
        }
        
        var target = sum/2;
        //Console.WriteLine(target);
        if(sum%2==1)
        {
            return false;
        }
        
        var dp = new bool[nums.Length+1, target+1];
        //dp[0,0] = true;
        for(var i = 0; i < nums.Length+1; i++)
        {
            dp[i,0] = true;
        }
        for(var i = 1; i < nums.Length+1; i++)
        {
            for(var j = 1; j < target+1; j++)
            {
                dp[i,j] = dp[i-1,j];
                if(j - nums[i-1] >= 0)
                {
                    dp[i,j] = dp[i-1,j - nums[i-1]] || dp[i-1,j];
                }
            }
        }
        
        return dp[nums.Length,target];
        //return CanWeRecursive(nums, 0, target);
    }
    
    private bool CanWeRecursive(int[] nums, int index, int target)
    {
        //Console.WriteLine(target);
        if(index >= nums.Length)
        {
            return false;
        }
        
        if(target - nums[index] == 0)
        {
            return true;
        }
        
        var result = CanWeRecursive(nums, index+1, target);
        
        if(target - nums[index] < 0)
        {
            return result || false;
        }
        
        return CanWeRecursive(nums, index+1, target - nums[index])||result;
    }
}

