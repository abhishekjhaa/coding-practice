'''
https://leetcode.com/problems/unique-paths/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.
'''

class Solution(object):
    visited = []
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        '''
        This looks like a classic DP problem
        I think this can be solved by bottom up as well as top down approach
        For Bottom up we need a base case 
        Base case can be represented by:
        Let d[i][j] be another matrix where i,j represents a cell for which path count is known, so:
        d[0][0] = 1
        d[1][0] = 1
        d[0][1] = 1
        
        any for any other cell path can be counted as:
        d[i][j] = d[i-1][j] + d[i][j-1]
        '''

        #Iterative way in n^2
        matrix = [[0]*m for i in range(n)]
        matrix[0][0] = 1
        for i in range(n):
            for j in range(m):
                if i - 1 >= 0:
                    matrix[i][j] = matrix[i][j] + matrix[i-1][j]
                if j - 1 >= 0:
                    matrix[i][j] = matrix[i][j] + matrix[i][j-1]
        return matrix[n-1][m-1]