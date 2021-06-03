/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/

public class Solution {
    public int LongestIncreasingPath(int[][] matrix) {
        int m = matrix.Length;
        int n = matrix[0].Length;
        var directions = new int[4, 2] {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        var result = 1;
        var cache = new int[m][];
        for(var i = 0; i < m; i++)
        {
            cache[i] = new int[n];
            for (var j = 0; j < n; j++)
            {
                cache[i][j] = -1;
            }
        }
        for(var i = 0; i < m; i++)
        {
            for(var j = 0; j < n; j++)
            {
                result = Math.Max(result, DFS(matrix, m, n, i, j, cache, directions));
            }
        }
        
        return result;
    }
    
    private int DFS(int[][] matrix, int m, int n, int i, int j, int[][] cache, int[,] directions)
    {
        if(cache[i][j] != -1)
        {
            return cache[i][j];
        }
        
        var result = 1;
        for(var dir = 0; dir < 4; dir++)
        {
            var new_i = i + directions[dir, 0];
            var new_j = j + directions[dir, 1];
            if(new_i < m && new_i >= 0 && new_j >= 0 && new_j < n && matrix[new_i][new_j] > matrix[i][j])
            {
                result = Math.Max(result, 1 + DFS(matrix, m, n, new_i, new_j, cache, directions));
            }
        }
        
        cache[i][j] = result;
        return result;
    }
}