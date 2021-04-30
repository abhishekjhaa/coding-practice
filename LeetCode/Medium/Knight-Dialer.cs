/*
https://leetcode.com/problems/knight-dialer/
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
Example 2:

Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
Example 3:

Input: n = 3
Output: 46
Example 4:

Input: n = 4
Output: 104
Example 5:

Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
 

Constraints:

1 <= n <= 5000
*/
public class Solution {
    private int mod = 1000000007;
    private int[,,] memo;
    private int[,] dir = new int[8,2] {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, 2}, {1, -2}, {2, -1}, {2, 1}};
    public int KnightDialer(int n) {
        int sum = 0;
        memo = new int[4,3,n+1];
        for(var i = 0; i < 4; i++)
        {
            for(var j = 0; j < 3; j++)
            {
                sum = (sum + Traverse(i, j, n)) % mod;
            }
        }
        
        memo = null;
        return sum;
    }
    
    private int Traverse(int i, int j, int n)
    {
        if(i < 0 || j < 0 || i > 3 || j > 2 || (i == 3 && j != 1))
        {
            return 0;
        }
        
        if(n == 1)
        {
            return 1;
        }
        
        if(memo[i,j,n] > 0)
        {
            return memo[i, j, n];
        }
        
        int sum = 0;
        for(var row = 0; row < 8; row++)
        {
            sum = (sum + Traverse(i + dir[row, 0], j + dir[row, 1], n - 1) % mod) % mod;
        }
        
        memo[i, j, n] = sum;
        
        //memo[i, j, n] = (Traverse(i - 2 , j - 1, n - 1) % mod + Traverse(i - 2 , j + 1, n - 1) % mod + Traverse(i - 1 , j - 2, n - 1) % mod + Traverse(i - 1 , j + 2, n - 1) % mod + Traverse(i + 1 , j + 2, n - 1) % mod + Traverse(i + 1 , j - 2, n - 1) % mod + Traverse(i + 2 , j - 1, n - 1) % mod + Traverse(i + 2 , j + 1, n - 1) % mod) % mod;
        
        return memo[i, j, n];
    }
}