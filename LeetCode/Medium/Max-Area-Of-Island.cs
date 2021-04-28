/*
https://leetcode.com/problems/max-area-of-island/
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

public class Solution {
    public int MaxAreaOfIsland(int[][] grid) {
        var maxArea = 0;
        var visited = new bool[grid.Length, grid[0].Length];
        for(var i = 0; i < grid.Length; i++)
        {
            for(var j = 0; j < grid[0].Length; j++)
            {
                if(grid[i][j] == 1 && !visited[i,j])
                {
                    maxArea = Math.Max(DFS(grid, i, j, visited), maxArea);
                }
            }
        }
        
        return maxArea;
    }
    
    private int DFS(int[][] grid, int i, int j, bool[,] visited) 
    {
        if(i >= 0 && j >= 0 && i < grid.Length && j < grid[0].Length && grid[i][j] == 1 && !visited[i,j])
        {
            visited[i,j] = true;
            return 1 + DFS(grid, i+1, j, visited) + DFS(grid, i-1, j, visited) + DFS(grid, i, j+1, visited) + DFS(grid, i, j-1, visited);
        }
        
        return 0;
    }
}