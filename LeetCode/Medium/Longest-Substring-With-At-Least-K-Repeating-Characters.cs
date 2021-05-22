/*
https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/submissions/
Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105
*/

public class Solution {
    public int LongestSubstring(string s, int k) {
        if(s.Length < k)
        {
            return 0;
        }
        int[] freq = new int[26];
        var c = s.ToCharArray();
        for(var l = 0; l < s.Length; l++)
        {
            freq[c[l] - 'a'] += 1;
        }
        
        int i = 0;
        while(i < s.Length)
        {
            if(freq[c[i] - 'a'] >= k)
            {
                i++;
                continue;
            }
            var j = i + 1;
            while(j < s.Length && freq[c[j] - 'a'] < k)
            {
                j++;
            }
            
            return Math.Max(LongestSubstring(s.Substring(0, i), k), LongestSubstring(s.Substring(j), k));
        }
        
        return s.Length;
    }
}