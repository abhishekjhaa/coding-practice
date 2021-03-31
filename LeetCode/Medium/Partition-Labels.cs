/*
https://leetcode.com/problems/partition-labels/

A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
 

Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.
*/

public class Solution {
    public IList<int> PartitionLabels(string S) {
        var charS = S.ToCharArray();
        List<int>[] map = new List<int>[26];
        for(var i = 0; i < S.Length ; i++)
        {
            if(map[charS[i]-'a'] == null)
            {
                map[charS[i]-'a'] = new List<int>{i, -1};
            }
            else
            {
                map[charS[i]-'a'][1] = i;
            }
        }
        
        var result =  new List<int>();
        
        for(var i= 0; i < S.Length; i++)
        {
            var right = map[charS[i]-'a'][1];
            if(right == -1)
            {
                result.Add(1);
                continue;
            }
            else
            {
                var j = i+1;
                while(j < S.Length && j <= right)
                {
                    if(map[charS[j]-'a'][1] > right)
                    {
                        right = map[charS[j]-'a'][1];
                    }
                    
                    j++;
                }
                
                result.Add(j-i);
                i = j-1;
            }
        }
        
        return result;
    }
}