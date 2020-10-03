/*
https://leetcode.com/problems/perfect-squares/
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

//using System.Linq;
public class Solution {
    private static List<int> memo = new List<int>();
    public int NumSquares(int n) {
        /*
        Every Number can be represented can be represented as a square of numbers.
        This looks like a classic DP problem where we can build up from bottom.
        Base case can be for 0 there is 0 number of ways
        */
        
        //int[] result = Enumerable.Repeat(Int32.MaxValue, n+1).ToArray();
        if(memo.Count >= n+1)
        {
            Console.WriteLine("Hit " + n.ToString());
            return memo[n];
        }
        memo.AddRange(Enumerable.Repeat(Int32.MaxValue, n+1-memo.Count));
        memo[0] = 0;
        //result[0] = 0;

        for (var i = 1; i <= n; i++)
        {
            for (var j = 1; j*j <= i; j++)
            {
                //result[i] = Math.Min(result[i], result[i - j*j] + 1);
                memo[i] = Math.Min(memo[i], memo[i - j*j] + 1);
            }
        }
        
        //return result[n];
        return memo[n];
    }
}