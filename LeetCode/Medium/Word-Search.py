'''
https://leetcode.com/problems/word-search/
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
'''

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        '''
        Idea is to save indexes of the board for the First Character of the word.
        Then for each index saved
        For all of the adjacent cells that has subsequent character, iterate one by one
        mark the index as visited
        Do a DFS. 
        If the result of DFS returns true then word is found
        Else mark the cell as unvisited and go to next cell which has subsequent character 
        
        We need an extra visited boolean matrix
        '''
        rows = len(board)
        if rows < 1:
            return True
        cols = len(board[0])
        if cols < 0:
            return True
        if len(word) < 1:
            return True
        visited = [[False]*cols for i in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    result = self.exists(board, word, visited, i, j)
                    if result:
                        return True
        
    def exists(self, board, word, visited, i, j):
        rows = len(board)
        if rows < 1:
            return True
        cols = len(board[0])
        if cols < 0:
            return True
        if len(word) < 1:
            return True
        if i < 0 or i >= rows or j < 0 or j >= cols:
            return False
        
        if board[i][j] == word[0] and not visited[i][j]:
            visited[i][j] = True
            if len(word) == 1:
                return True
            result = False
            directions = [1, -1]
            for d in directions:
                result = self.exists(board, word[1:], visited, i+d, j)
                if result:
                    return True
                result = self.exists(board, word[1:], visited, i, j+d)
                if result:
                    return True
            visited[i][j] = False
        return False
            
        