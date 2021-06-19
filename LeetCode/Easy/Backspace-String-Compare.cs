/*
https://leetcode.com/problems/backspace-string-compare/
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".
Example 4:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:

1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
 

Follow up: Can you solve it in O(n) time and O(1) space?
*/

public class Solution {
    public bool BackspaceCompare(string s, string t) {
        var i = s.Length - 1;
        var j = t.Length - 1;
        var sc = 0;
        var tc = 0;
        while(i >= 0 || j >= 0)
        {
            if(i >= 0 && s[i] == '#')
            {
                sc++;
                i--;
            }
            else if(sc > 0)
            {
                sc--;
                i--;
            }
            else if(j >= 0 && t[j] == '#')
            {
                tc++;
                j--;
            }
            else if(tc > 0)
            {
                tc--;
                j--;
            }
            else if(i < 0 || j < 0 || s[i] != t[j])
            {
                return false;
            }
            else
            {
                i--;
                j--;
            }
        }
        
        return true;
    }
}