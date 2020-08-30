'''
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-10^9 <= matrix[i][j] <= 10^9
'''

class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        '''
        In the 1st iteration, iterate through all the rows & columns of matrix
        If 0 is encountered then record the index in separate hashset of rows & cols
        Iterate again and if row index is zero then make all zeros for the row
        If column index is 0 then make all zeros for the column
        
        For constant space, while iterating the matrix if you encounter 0
        the hoist it to the top row & col to mark them as 0
        Iterate again and check the 1st Row & Column to mark the rows & cols as 0
        '''
        if len(matrix) < 1:
            return None
        if len(matrix[0]) < 1:
            return None
        firstColHasZero = False
        for i in range(len(matrix)):
            if matrix[i][0] == 0:
                firstColHasZero = True
            for j in range(1,len(matrix[0])):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        print matrix
        for i in range(len(matrix)-1, -1, -1):
            for j in range(len(matrix[0])-1, 0, -1):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if firstColHasZero:
                matrix[i][0] = 0
        return None
        '''
        #This uses O(m+n) additional space
        rowSet = set()
        colSet = set()
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    rowSet.add(i)
                    colSet.add(j)
        for i in rowSet:
            for j in range(len(matrix[0])):
                matrix[i][j] = 0
        for j in colSet:
            for i in range(len(matrix)):
                matrix[i][j] = 0
        return None
        '''
        