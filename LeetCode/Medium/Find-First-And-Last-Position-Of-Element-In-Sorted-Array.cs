/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
Accepted
*/

public class Solution {
    public int[] SearchRange(int[] nums, int target) {
        return new int[2] {FindFirstIndex(nums, target, true), FindFirstIndex(nums, target, false)};
    }
    
    private int FindFirstIndex(int[] nums, int target, bool atFront)
    {
        var i = 0;
        var j = nums.Length - 1;
        int result = -1;
        while(i <= j)
        {
            var mid = i + (j - i)/2;
            if(nums[mid] > target)
            {
                j = mid - 1;
            }
            else if(nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                result = mid;
                if(atFront)
                {
                    j = mid - 1;
                }
                else
                {
                    i = mid + 1;
                }
            }
        }
        
        return result;
    }
}