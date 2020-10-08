/*
https://leetcode.com/problems/top-k-frequent-elements/
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        var dict = new Dictionary<int, int>();
        foreach(var num in nums)
        {
            if(dict.ContainsKey(num))
            {
                dict[num]++;
            }
            else
            {
                dict[num] = 1;
            }
        }
        
        var freq = new List<int>[nums.Length+1];
        foreach(var entry in dict)
        {
            if(freq[entry.Value] == null)
            {
                freq[entry.Value] = new List<int> {entry.Key};
            }
            else
            {
                freq[entry.Value].Add(entry.Key);
            }
        }
        
        int[] result = new int[k];
        int count = 0;
        for(var i = freq.Length - 1; count < k && i >= 0; i--)
        {
            if(freq[i]!=null && count < k)
            {
                var j = 0;
                while(j < freq[i].Count && count < k)
                {
                    result[count++] = freq[i][j++];
                }
            }
        }
        
        return result;
        
    }
}