/*
https://leetcode.com/problems/pacific-atlantic-water-flow/
You are given an m x n integer matrix heights representing the height of each unit cell in a continent. The Pacific ocean touches the continent's left and top edges, and the Atlantic ocean touches the continent's right and bottom edges.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
 

Constraints:

m == heights.length
n == heights[i].length
1 <= m, n <= 200
1 <= heights[i][j] <= 105
*/

public class Solution {
    public IList<IList<int>> PacificAtlantic(int[][] heights) {
        var m = heights.Length;
        var n = heights[0].Length;
        IList<IList<int>> result = new List<IList<int>>();
        var pacific = new HashSet<(int Row, int Col)>();
        var atlantic = new HashSet<(int Row, int Col)>();
        var directions = new int[4, 2] {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(var j = 0; j < n; j++)
        {
            DFS(heights, m, n, 0 , j, pacific, directions);
            DFS(heights, m, n, m - 1 , j, atlantic, directions);
        }
        
        for(var i = 0; i < m; i++)
        {
            DFS(heights, m, n, i , 0, pacific, directions);
            DFS(heights, m, n, i , n - 1, atlantic, directions);
        }
        
        foreach (var val in pacific)
        {
            if(atlantic.Contains(val))
            {
                result.Add(new List<int> {val.Row, val.Col});
            }
        }
        
        //BruteForce(heights, m, n, result);
        return result;
    }
    
    private void DFS(int[][] heights, int m, int n, int i , int j, HashSet<(int Row, int Col)> visited, int[,] directions)
    {
        if(visited.Contains((i, j)))
        {
            return;
        }
        
        visited.Add((i, j));
        
        for(var dir = 0; dir < 4; dir++)
        {
            var next_i = i + directions[dir, 0];
            var next_j = j + directions[dir, 1];
            if(next_i < m && next_j < n && next_i >= 0 && next_j >= 0 && heights[next_i][next_j] >= heights[i][j])
            {
                DFS(heights, m, n, next_i , next_j, visited, directions);
            }
        }
    }
    
    private void BruteForce(int[][] heights, int m, int n, IList<IList<int>> result)
    {
        for(var i = 0; i < m; i++)
        {
            for(var j = 0; j < n; j++)
            {
                if(CanReachBothOceans(heights, m, n, i , j))
                {
                    result.Add(new List<int> {i, j});
                }
            }
        }
    }
    
    private bool CanReachBothOceans(int[][] heights, int m, int n, int i , int j)
    {
        var result = new bool[2];
        CanReachPacificAndAtlantic(heights, m, n, i , j, new bool[m,n], result);
        return result[0] && result[1];
    }
    
    private void CanReachPacificAndAtlantic(int[][] heights, int m, int n, int i , int j, bool[,] visited, bool[] result)
    {   
        if(j == 0 || i == 0)
        {
            result[0] = true;
        }
        
        if(j == n - 1 || i == m - 1)
        {
            result[1] = true;
        }
        
        if(result[0] && result[1])
        {
            return;
        }
        
        if(visited[i, j])
        {
            return;
        }
        
        visited[i, j] = true;
        if(i < m - 1 && heights[i][j] >= heights[i+1][j])
        {
            CanReachPacificAndAtlantic(heights, m, n, i + 1 , j, visited, result);
        }
        if(i > 0 && heights[i][j] >= heights[i-1][j])
        {
            CanReachPacificAndAtlantic(heights, m, n, i - 1 , j, visited, result);
        }
        if(j < n - 1 && heights[i][j] >= heights[i][j+1])
        {
            CanReachPacificAndAtlantic(heights, m, n, i , j + 1, visited, result);
        }
        if(j > 0 && heights[i][j] >= heights[i][j-1])
        {
            CanReachPacificAndAtlantic(heights, m, n, i , j - 1, visited, result);
        }
    }
}