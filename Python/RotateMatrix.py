# -*- coding: utf-8 -*-
"""
Created on Wed Jan 31 13:22:41 2018

@author: Accolite
"""

def rotate(A):
        print(A)
        startRow = 0
        endRow = len(A) - 1
        startCol = 0
        endCol = len(A[0]) - 1
        while startRow <= endRow and startCol <= endCol:
            j = 0
            i = 0
            while startCol + j < endCol and startRow + i < endRow:
                temp = A[startRow+i][endCol]
                A[startRow+i][endCol] = A[startRow][startCol+j]
                print(A)
                temp1 = A[endRow][endCol - j]
                A[endRow][endCol - j] = temp
                temp = A[endRow - i][startCol]
                A[endRow - i][startCol] = temp1
                A[startRow][startCol+j] = temp
                i += 1
                j += 1
            startRow += 1
            endRow -= 1
            startCol += 1
            endCol -= 1
        return A
def Test():
    arr = [[1, 2 ], [3, 4 ] ]
    print(rotate(arr))