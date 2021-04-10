/*
https://leetcode.com/problems/basic-calculator-ii/
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.
*/

public class Solution {
    public int Calculate(string s) {
        s = s.Replace(" ", "");
        var c = s.ToCharArray();
        var stack = new Stack<int>();
        var index = 0;
        var sign = '+';
        while(index < s.Length)
        {
            var result = 0;
            var start = index;
            var exponent = 10;
            while(start < s.Length && Char.IsDigit(c[start]))
            {
                result = result*exponent + (int)(c[start] - '0');
                start++;
            }
            index = start;
            if(sign == '+')
            {
                stack.Push(result);
            }
            else if(sign == '-')
            {
                stack.Push((-1*result));
            }
            else if(sign == '*')
            {
                result *= stack.Pop();
                stack.Push(result);  
            }
            else if(sign == '/')
            { 
                result = (int)Math.Round((double)(stack.Pop()/result));
                stack.Push(result); 
            }
            
            if(index < s.Length - 1)
            {
                sign = c[index];
                index++;
            }
        }
        

        var ret = 0;
        while(stack.Count > 0)
        {
            ret += stack.Pop();
        }
        
        return ret;
    }
}