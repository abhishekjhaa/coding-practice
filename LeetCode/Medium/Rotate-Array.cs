/*
https://leetcode.com/problems/rotate-array/
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

public class Solution {
    public void Rotate(int[] nums, int k) 
    {
        RotateOneNumberAtATime(nums, k);
        
        //RotateViaReverse(nums, k);
        
        //RotateCopyArray(nums, k);
    }
    
    private void RotateOneNumberAtATime(int[] nums, int k) 
    {
        k = k%nums.Length;
        var start = 0;
        var previous = nums[start];
        var count = 0;
        while(count < nums.Length)
        {
            var nextIndex = (start+k)%nums.Length;
            while(start!=nextIndex)
            {
                var temp = nums[nextIndex];
                nums[nextIndex] = previous;
                previous = temp;
                nextIndex = (nextIndex+k)%nums.Length;
                count++;
            }
            nums[nextIndex] = previous;
            start++;
            previous = nums[start%nums.Length];
            count++;
        }
    }
    
    private void RotateViaReverse(int[] nums, int k) 
    {
        Reverse(nums, 0, nums.Length - 1);
        Reverse(nums, 0, k-1);
        Reverse(nums, k, nums.Length - 1);
    }
    
     private void Reverse(int[] nums, int start, int end) 
     {
         while (start < end)
         {
             var temp = nums[start];
             nums[start] = nums[end];
             nums[end] = temp;
             start++;
             end--;
         }
         
     }
    
    private void RotateCopyArray(int[] nums, int k) {
        var newNums = new int[nums.Length];
        for(var i = 0; i < nums.Length;i++)
        {
            newNums[(i+k)%nums.Length] = nums[i]; 
        }
        
        for(var i = 0; i < nums.Length;i++)
        {
            nums[i] = newNums[i]; 
        }
        
        return;
    }
}