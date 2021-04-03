/*
https://leetcode.com/problems/palindromic-substrings/

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note:

The input string length won't exceed 1000.
*/

public class Solution {
    public int CountSubstrings(string s) {
        var c = s.ToCharArray();
        var a = new int[s.Length, s.Length];
        for(var i = 0; i < s.Length; i++)
        {
            for(var j = 0; j < s.Length; j++)
            {
                if(c[i] == c[j])
                {
                    a[i,j] = 1;
                }
            }
        }
        
        var odd = true;
        var row = 0;
        var col  = 0;
        var count = 0;
        while (row < s.Length && col < s.Length)
        {
            if(odd)
            {
                if(a[row,col] == 1)
                {
                    var leftRow = row;
                    var leftCol = col;
                    var rightRow = row;
                    var rightCol = col;
                    var index = 1;
                    
                    while (leftRow < s.Length && leftCol >= 0 && rightRow >= 0 && rightCol < s.Length)
                    {
                        if(a[leftRow,leftCol] > 0 && a[rightRow,rightCol] > 0)
                        {
                            count++;
                            // Console.WriteLine("Odd (" +leftRow.ToString() + ", "+ leftCol.ToString() +") & ("+ rightRow.ToString() +", "+ rightCol.ToString() + ")");
                            leftRow = row+index;
                            leftCol = col-index;
                            rightRow = row-index;
                            rightCol = col+index;
                            index++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                    var leftRow = row+1;
                    var leftCol = col;
                    var rightRow = row;
                    var rightCol = col+1;
                    var index = 1;
                    
                    while (leftRow < s.Length && leftCol >= 0 && rightRow >= 0 && rightCol < s.Length)
                    {
                        if(a[leftRow,leftCol] > 0 && a[rightRow,rightCol] > 0)
                        {
                            count++;
                            // Console.WriteLine("Even (" +leftRow.ToString() + ", "+ leftCol.ToString() +") & ("+ rightRow.ToString() +", "+ rightCol.ToString() + ")");
                            leftRow = row+1+index;
                            leftCol = col-index;
                            rightRow = row-index;
                            rightCol = col+1+index;
                            // Console.WriteLine("====> (" +leftRow.ToString() + ", "+ leftCol.ToString() +") & ("+ rightRow.ToString() +", "+ rightCol.ToString() + ")");
                            index++;
                        }
                        else
                        {
                            break;
                        }
                    }
                
                row = row+1;
                col = col+1;
            }
            
            odd = !odd;
        }
        
        
        return count;
        
    }
}