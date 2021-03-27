/*
https://leetcode.com/problems/decode-string/
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

public class Solution {
    public string DecodeString(string s) {
        var sArray = s.ToCharArray();
        var stack = new Stack<char>();
        for(var i=0; i < sArray.Length; i++)
        {
            
            if(sArray[i]==']')
            {
                var sb = new StringBuilder();
                while(stack.Peek() != '[')
                {
                    sb.Insert(0,stack.Pop());
                }
                
                var t = sb.ToString().ToCharArray();
                stack.Pop();
                sb = new StringBuilder();
                while(stack.Count > 0 && Char.IsDigit(stack.Peek()))
                {
                    sb.Insert(0,stack.Pop());
                }
                
                Int32.TryParse(sb.ToString(), out var snum);
                
                while(snum > 0)
                {
                    for (var j = 0; j < t.Length; j++)
                    {
                        stack.Push(t[j]);
                    }
                    
                    snum--;
                }  
            }
            else
            {
                stack.Push(sArray[i]);
            }
        }
        
        var sbr = new StringBuilder();
        while(stack.Count > 0)
        {
            sbr.Insert(0, stack.Pop());
        }
        return new string(sbr.ToString());
        
    }
}

public class AnotherSolution {
    public string DecodeString(string s) {
        var sArray = s.ToCharArray();
        var stack = new Stack<char>();
        for(var i=0; i < sArray.Length; i++)
        {
            
            if(sArray[i]==']')
            {
                var temp = "";
                while(stack.Peek() != '[')
                {
                    temp = stack.Pop()+temp;
                }
                
                stack.Pop();
                var snum = 0;
                var count = 1;
                var num = 0;
                while(stack.Count > 0 && Int32.TryParse(stack.Peek().ToString(), out num))
                {
                    stack.Pop();
                    snum = count*num + snum;
                    count *= 10;
                }
                
                var t = temp.ToCharArray();
                while(snum > 0)
                {
                    for (var j = 0; j < t.Length; j++)
                    {
                        stack.Push(t[j]);
                    }
                    
                    snum--;
                }  
            }
            else
            {
                stack.Push(sArray[i]);
            }
        }
        
        var rev = stack.ToArray();
        Array.Reverse(rev); 
        return new string(rev);
        
    }
}