# -*- coding: utf-8 -*-
"""
Created on Wed Dec 13 17:18:12 2017

@author: Accolite
CTCT 8:12
"""

def NQueens():
    sizeOfBoard = int(input("Enter a board size in integer :"))
    board = [[0]*sizeOfBoard for i in range(sizeOfBoard)]
    print(totalWaysToPlaceQueens(board, sizeOfBoard, 0))

def totalWaysToPlaceQueens(board, sizeOfBoard, startrow):
    if startrow == sizeOfBoard:
        return 1;
    count = 0
    for column in range(0, sizeOfBoard):
        board[startrow][column] = 1
        if validPlacement(board, startrow, column, sizeOfBoard):
            count += totalWaysToPlaceQueens(board, sizeOfBoard, startrow + 1)
        board[startrow][column] = 0
                
    return count

def validPlacement(board, row, column, sizeOfBoard):
        #check in column
        for rowCell in range(row):
            if board[rowCell][column] == 1:
                return False
            
        #check in diagonal
        for i in range(1, row + 1):
            if column - i > -1 and board[row - i][column - i] == 1:
                return False
            if column + i < sizeOfBoard and board[row - i][column + i] == 1:
                return False
        return True
    
            #NO NEED check in row
        #for columnCell in range(column):
         #   if board[row][columnCell] == 1:
          #      return False
            
    
        
