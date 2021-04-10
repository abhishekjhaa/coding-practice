/*
https://leetcode.com/problems/decode-ways/
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0.
The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
Hence, there are no valid ways to decode this since all digits need to be mapped.
Example 4:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/

/*
Lets start with recursive solution:

We'll recurse after:

taking a single character OR
taking 2 characters which when combined falls in the range of 10 to 26. (01 to 09 is not valid similarly 27 to 99 is not valid)
Our termination condtions are:

If we have reached beyond string length, in that case we'll return 0.
If we encounter '0', we know it is not valid nor any combination which starts with '0' is valid, so we return 0.
If we have reached last "valid" character in the string, it means we have found a valid way from begining to end, we add 1 to the result.
If we have reached 2nd last character where 2nd Last and last character combined are in the range of 10 to 26, it means we have found a valid way from begining to end, we add 1 to the result.
When we recurse back:
We add the count of valid paths found for both the recursion calls at each index of string.

For memoization, we have added a dictionary to remember the number of ways from a particular index of the string. If key is found in dictionary we return the result and don't recurse subsequently.

Thats for the recursive solution.


For iterative solution:

Lets think for a moment if we have to finds ways for "1". Now this is a single character string, which falls between 1 to 9 hence a valid one, we can say there is 1 way to decode it.

Lets prefix "2" to above string, the new string is "21". Now, "2" is a valid character and after it only "1" remains for which we have already counted the way/s. So there is one way if we go for ("2", "1"). Another case is, when we select "21" combined, which is valid since it is between "10" & "26". So this is another way. Hence is total we have 2 ways to decode the string: ("2", "1") & ("21"). To get ("2", "1") we had used the previous result stored.

Lets prefix "1" to the above string, the new string is "121". Since "1" is a valid character, after which only "21" remains, results of which we have already calculated, that is 2 ways. Now we can combine "12", after which only "1" remains, results of which we have already calculated, that is 1way/s. So in total we can decode in 2 + 1 = 3 ways. And to get to this result we have used previously stored results.

So in Summary,

Decode[kth-index] = ValidK(Decode[(k+1)th-index]) + ValidK&KNext(Decode[(k+2)th-index])

Return Decode[0] for right answer

Now if you look closely we are only using 2 previous states to derive at the current state, so that can be done using variables also.
*/

public class Solution {
    public int NumDecodings(string s) {
        var c = s.ToCharArray();
        var mem = new Dictionary<int, int>();
        return NumDecodingsDPWithLocalVariables(c, s.Length);
        // return NumDecodingsRecursive(c, 0, s.Length, mem);
        // return NumDecodingsDPWith1DArray(c, s.Length);
    }
    
    public int NumDecodingsDPWithLocalVariables(char[] s, int n) 
    {
        var nextToNext = 1;
        var next = 0;
        if(s[n-1] > '0')
        {
            next = 1;
        }
        
        var current = 0;
        for(var i = n - 2; i>=0; i--)
        {
            if(s[i] > '0')
            {
                current += next;
            }
            if(s[i] == '1' || s[i] == '2' && s[i+1] < '7')
            {
                current += nextToNext;
            }
            
            nextToNext = next;
            next = current;
            current = 0;
        }
        
        return next;
    }
    
    public int NumDecodingsDPWith1DArray(char[] s, int n) 
    {
        var dp = new int[n+1];
        dp[n] = 1;
        if(s[n-1] > '0')
        {
            dp[n-1] = 1;
        }
        
        for(var i = n - 2; i>=0; i--)
        {
            if(s[i] > '0')
            {
                dp[i] += dp[i+1];
            }
            if(s[i] == '1' || s[i] == '2' && s[i+1] < '7')
            {
                dp[i] += dp[i+2];
            }
        }
        
        return dp[0];
    }
    
    public int NumDecodingsRecursive(char[] s, int start, int length, Dictionary<int, int> mem) {
        if(start >= length)
        {
            return 0;
        }
        
        if(s[start] == '0')
        {
            return 0;
        }
        
        if(mem.TryGetValue(start, out var result))
        {
            return result;
        }
        
        var count = 0;
        if(start == length - 1 && s[start] >= '1' && s[start] <= '9')
        {
            count = 1;
        }
        
        count += NumDecodingsRecursive(s, start + 1, length, mem);        
        
        
        if(start < length - 1 && (s[start] == '1' || (s[start] == '2' && (s[start+1] >= '0' && s[start+1] <= '6'))))
        {
            if(start == length - 2)
            { 
                count += 1; 
            }
            else
            {
                count += NumDecodingsRecursive(s, start + 2, length, mem);
            }
        }

        mem.Add(start, count);
        return count;
        
    }
}