/*
https://leetcode.com/problems/trapping-rain-water/submissions/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

*/
public class Solution {
    public int Trap(int[] height) {
        var n = height.Length;
        var leftMax = new int[n];
        var rightMax = new int[n];
        
        var max = 0;
        for(var i = 0; i < n; i++)
        {
            leftMax[i] = Math.Max(max, height[i]);
            max = Math.Max(max, height[i]);
        }
        
        max = 0;
        for(var i = n - 1; i >= 0 ; i--)
        {
            rightMax[i] = Math.Max(max, height[i]);
            max = Math.Max(max, height[i]);
        }
        
        var trappedWater = 0;
        for(var i = 1; i < n - 1; i++)
        {
            trappedWater += Math.Min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return trappedWater;
    }
}