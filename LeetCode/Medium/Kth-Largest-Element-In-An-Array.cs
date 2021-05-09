/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/

public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        RandomizeNums(nums);
        return QuickSelect(nums, 0, nums.Length - 1, k);
    }
    
    private void RandomizeNums(int[] nums)
    {
        var r = new Random();
        var n = nums.Length;
        for(var i = n - 1; i >= 0; i--)
        {
            var ri = r.Next(i, n);
            var temp = nums[ri];
            nums[ri] = nums[i];
            nums[i] = temp;
        }
    }
    
    private int QuickSelect(int[] nums, int start, int end, int k)
    {
        while (start < end)
        {
            var pivot = nums[end];
            var i = start;
            for(var j = i; j < end; j++)
            {
                if(nums[j] > pivot)
                {
                    var temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    i++;
                }
            }
            
            nums[end] = nums[i];
            nums[i] = pivot;
            
            if(k == i + 1)
            {
                return pivot;
            }

            if(i > k - 1)
            {
                end = i - 1;
            }
            else
            {
                start = i + 1;
            }
        }
        
        return nums[start];
    }
}