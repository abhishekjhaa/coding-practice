'''
https://leetcode.com/problems/surrounded-regions/
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, 
which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border 
will be flipped to 'X'. Two cells are connected if they are adjacent cells 
connected horizontally or vertically.
'''

class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        '''
        Idea is to iterate for each element of the board row by row
        if O is encountered then put that index in a stack
        while stack is not empty
        if poped index is a border index 
        break the loop
        else if there are neighbouring indexes with value O 
        then put their indexes in stack and the current index in a different list
        
        if list has values then iterate over the list and make the index values as X
        
        '''
        if len(board) < 1 or len(board[0]) < 1:
            return None
        for i in range(len(board)):
            for j in range(len(board[0])):
                #print "i, j = " + str((i,j))
                if board[i][j] == 'O':
                    stack = [(i,j)]
                    result = []
                    visited = [[False]*len(board[0]) for x in range(len(board))]
                    while len(stack) > 0:
                        k, l = stack.pop()
                        #print "k, l = " + str((k,l))
                        if k == 0 or k == len(board) - 1 or l == 0 or l == len(board[0]) - 1:
                            result = []
                            stack = []
                            break
                        directions = [1,-1]
                        for d in directions:
                            if k+d >= 0 and k+d < len(board) and board[k+d][l] == 'O' and not visited[k+d][l]:
                                visited[k+d][l] = True
                                stack.append((k+d, l))
                            if l+d >= 0 and l+d < len(board[0]) and board[k][l+d] == 'O' and not visited[k][l+d]:
                                visited[k][l+d] = True
                                stack.append((k, l+d))
                        result.append((k,l))
                        #print result
                    while len(result) > 0:
                        k, l = result.pop()
                        board[k][l] = 'X'