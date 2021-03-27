/*
https://leetcode.com/problems/jump-game-ii/
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 105
*/

/*
Lets have one jump array to keep track of what is the minimum jump required by each index element to reach last.

    Given Array = [2,3,1,1,4]
     Jump Array = [2,1,2,1,0]
Now lets iterate from last index:
Jump required by last element to reach last element is 0
Any index before last index can reach last index either the (index value + index) >= (last index) OR scouting for (minimum jump) in the range it can jump (which is the (index value)).
Return the first element of Jump array.
*/

public class Solution {
    public int Jump(int[] nums) {
        if (nums.Length < 1)
        {
            return 0;
        }
        var len = nums.Length;
        var jump = new int[len];
        jump[len-1] = 0;
        var i = len - 2;
        while (i >= 0)
        {
            if(nums[i]+i >= len - 1)
            {
                jump[i] = 1;
            }
            else
            {
                var j = i+1;
                var minim = len+1;
                while (j <= (i + nums[i]) && j < len)
                {
                    minim = Math.Min(minim, jump[j]);
                    j++;
                }
                
                jump[i] = minim + 1;
            }
            
            i--;
        }
        
        return jump[0];
    }
}