'''
https://leetcode.com/problems/rotate-image/
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Example 3:

Input: matrix = [[1]]
Output: [[1]]
Example 4:

Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]

Constraints:
matrix.length == n
matrix[i].length == n
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
'''

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        """
        Idea is to target the outer loop first and then the inner loops.
        First take loop with starting at 0,0 and having length as n
        then move to loop starting at 1,1 and having length as n - 2
        
        While looping too the outer loop will go from starting index till len - 2 index
        
        0,0 -> 0,2 -> 2,2 -> 2,0 -> 0,0
        0,1 -> 1,2 -> 2,1 -> 1,2 -> 0,1
        
        """
        row = len(matrix)
        col = len(matrix[0])
        
        if row != col:
            return None
        
        N = row
        start = 0
        while N > 0:
            boundary = start + N - 1
            i, j = start, start
            count = 0 # initializing this count and using it is important.
            while  j < boundary:
                temp = matrix[j][boundary]
                matrix[j][boundary] = matrix[i][j]
                
                temp2 = matrix[boundary][boundary - count]
                matrix[boundary][boundary - count] = temp
                
                temp = matrix[boundary-count][i]
                matrix[boundary-count][i] = temp2
                
                matrix[i][j] = temp
                
                j = j + 1
                count = count + 1
                
            start = start + 1
            N = N - 2