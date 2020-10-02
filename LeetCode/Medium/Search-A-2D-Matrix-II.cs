/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
public class Solution {
    public bool SearchMatrix(int[,] matrix, int target) {
        /*
        If we sit at the top right then all the elements in the row are less than the element
        and the elements in the column are greater than the element
        In each iteration we can compare the target value and proceed based on that.
        */
        
        var row = matrix.GetLength(0);
        if (row == 0)
        {
            return false;
        }
        
        var col = matrix.GetLength(1);
        
        var i = 0;
        var j = col - 1;
        while (i<row && j >= 0)
        {
            if(matrix[i,j] > target)
            {
                
                j--;
            }
            else if(matrix[i,j] < target)
            {
                
                i++;
            }
            else
            {
                return true;
            }
        }
        
        return false;
    }
}