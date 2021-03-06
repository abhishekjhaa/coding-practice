/*
https://leetcode.com/problems/shuffle-an-array/
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls will be made to reset and shuffle.
*/

public class Solution {

    int[] fixNums;
    Random r;
    public Solution(int[] nums) {
        fixNums = nums;
        r = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] Reset() {
        return fixNums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] Shuffle() {
        var i = 1;
        var newNums = new int[fixNums.Length];
        Array.Copy(fixNums, newNums, fixNums.Length);
        while(i < fixNums.Length)
        {
            var index = r.Next(i+1);
            Swap(newNums, i, index);
            i++;
        }
        
        return newNums;
    }
    
    private void Swap(int[] nums, int i, int j)
    {
        var temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.Reset();
 * int[] param_2 = obj.Shuffle();
 */