/*
https://leetcode.com/problems/minimum-window-substring/
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

public class Solution {
    public string MinWindow(string s, string t) {
        var freq = new Dictionary<char, int>();
        for(var k = 0; k < t.Length; k++)
        {
            freq[t[k]] = freq.GetValueOrDefault(t[k], 0) + 1;
        }
        
        var i = 0;
        var j = 0;
        var maxIndex = -1;
        var minIndex = -1;
        var min = Int32.MaxValue;
        while(j < s.Length)
        {
            if(freq.ContainsKey(s[j]))
            {
                freq[s[j]]--;
            }
            while(CheckForAllZeros(freq))
            {
                if((j - i) < min)
                {
                    maxIndex = j;
                    minIndex = i;
                    min = j - i;
                }
                
                if(freq.ContainsKey(s[i]))
                {
                    freq[s[i]]++;
                }
                
                i++;
            }
            
            j++;
        }
        
        if(minIndex == -1)
        {
            return "";
        }
        
        return s.Substring(minIndex, maxIndex - minIndex + 1);
    }
    
    private bool CheckForAllZeros(Dictionary<char, int> freq)
    {
        foreach(var key in freq.Keys)
        {
            if(freq[key] > 0)
            {
                return false;
            }
        }
        
        return  true;
    }
}