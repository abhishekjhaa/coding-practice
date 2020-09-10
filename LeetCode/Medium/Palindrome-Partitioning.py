'''
https://leetcode.com/problems/palindrome-partitioning/
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
'''
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        '''
        Idea is to check for each left partition of string whether the next partition is also a palindrome
        '''
        def isPalindrome(s, left, right):
            while left <= right:
                if s[left] != s[right]:
                    return False
                left = left + 1
                right = right - 1
            return True
        
        def palindromePartition(s, currentList, resultList, start):
            if start == len(s):
                resultList.append(currentList[:])
                return
            for i in range(start, len(s)):
                if (isPalindrome(s, start, i)):
                    currentList.append(s[start:i+1])
                    palindromePartition(s, currentList, resultList, i+1)
                    currentList.pop()
        
        if len(s) < 1:
            return [[]]
        if len(s) == 1:
            return [[s]] 
        currentList = []
        resultList = []
        palindromePartition(s, currentList, resultList, 0)
        return resultList