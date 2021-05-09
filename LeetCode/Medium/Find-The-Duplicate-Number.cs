/*
https://leetcode.com/problems/find-the-duplicate-number/
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

2 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
*/

public class Solution {
    public int FindDuplicate(int[] nums) {
        var slow = nums[0];
        var fast = nums[slow];
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = 0;
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
    
    private int FindDuplicateModiyArray(int[] nums)
    {
        var count = 0;
        var i = 0;
        var numIndex = nums[i];
        while(count < nums.Length)
        {
            var temp = nums[numIndex];
            if(temp ==  numIndex)
            {
                return temp;
            }
            
            nums[numIndex] = numIndex;
            numIndex = temp;
            count++;
        }
        
        return 0;
    }
    
    private int FindDuplicateHashMap(int[] nums)
    {
        var visited = new bool[nums.Length];
        foreach(var num in nums)
        {
            if(!visited[num])
            {
                visited[num] = true;
            }
            else
            {
                return num;
            }
        }
        
        return 0;
    }
}