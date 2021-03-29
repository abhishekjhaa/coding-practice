/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        //return MySolution(s, p);        
        
        return MySlidingWindow(s, p);

    }
    
    private IList<int> MySlidingWindow(string s, string p) {
        int[] frequency = new int[26];
        var pc = p.ToCharArray();
        var sc = s.ToCharArray();
        
        for(var i=0; i < pc.Length; i++)
        {
            frequency[pc[i]-'a'] += 1;
        }
        
        var result = new List<int>();
        var left = 0;
        var right = 0;
        while(right < sc.Length)
        {
            if(frequency[sc[right]-'a'] > 0)
            {
                frequency[sc[right]-'a'] -= 1;
                right++;
                if(right - left == pc.Length)
                {
                    result.Add(left);
                    frequency[sc[left]-'a'] += 1;
                    left += 1;
                }
            }
            else
            {
                if(sc[left] == sc[right])
                {
                    frequency[sc[left]-'a'] += 1;
                    left++;
                    continue;
                }
                
                while(left < right)
                {
                    frequency[sc[left]-'a'] += 1;
                    left++;
                }
                
                if(frequency[sc[left]-'a'] < 1)
                {
                    left++;
                    right++;
                }
            }
        }
        
        return result;
    }
    
    private IList<int> MySolution(string s, string p) {
        var pc = p.ToCharArray();
        var sc = s.ToCharArray();
        var result = new List<int>();
        for(var i = 0; i <= sc.Length-pc.Length; i++)
        {
            var dict = GetMeNewDictionary(pc);
            if(dict.ContainsKey(sc[i]))
            {
                var j = i;
                for(j = i; j < i + pc.Length; )
                {
                    if(dict.ContainsKey(sc[j]))
                    {
                        dict[sc[j]] -= 1;
                        if(dict[sc[j]] == 0)
                        {
                            dict.Remove(sc[j]);
                        }
                        
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(j <= sc.Length && j == (i + pc.Length))
                {
                    result.Add(i);
                    while(j < sc.Length)
                    {
                        if(sc[i] == sc[j])
                        {
                            result.Add(i+1);
                            i++;
                            j++;
                        }
                        else
                        {
                            if(!pc.Contains(sc[j]))
                            {
                                i = j;
                            }
                            break;
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    private Dictionary<char, int> GetMeNewDictionary(char[] pc)
    {
        var visitedp = new Dictionary<char, int>();
        for(var i = 0; i < pc.Length; i++)
        {
            visitedp[pc[i]] = visitedp.GetValueOrDefault(pc[i], 0) + 1;
        }
        
        return visitedp;
    }
}