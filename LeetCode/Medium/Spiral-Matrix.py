'''
https://leetcode.com/problems/spiral-matrix/
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
'''

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        '''
        Keep it simple by taking four variables which represent 4 corners of the rectangle
        At each iteration check if the length of resultant order is less than row*cols of matrix
        '''
        rowLen =  len(matrix)
        if rowLen < 1:
            return []
        colLen =  len(matrix[0])
        start = 0
        result = []
        left, right = 0, colLen - 1
        up, down = 0, rowLen - 1
        while len(result) < rowLen*colLen:
            col = left
            while col <= right and len(result) < rowLen*colLen:
                result.append(matrix[up][col])
                col = col + 1
            row = up + 1
            while row <= down - 1 and len(result) < rowLen*colLen:
                result.append(matrix[row][right])
                row = row + 1
            col = right
            while col >= left and len(result) < rowLen*colLen:
                result.append(matrix[down][col])
                col = col - 1
            row = down - 1
            while row >= up + 1 and len(result) < rowLen*colLen:
                result.append(matrix[row][left])
                row = row - 1
            left = left + 1
            right = right - 1
            up = up + 1
            down = down -1
        return result
        