# https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
# https://www.lintcode.com/problem/386/description
# Description
# Given a string S, find the length of the longest substring T that contains at most k distinct characters.

# Example
# Example 1:

# Input: S = "eceba" and k = 3
# Output: 4
# Explanation: T = "eceb"
# Example 2:

# Input: S = "WORLD" and k = 4
# Output: 4
# Explanation: T = "WORL" or "ORLD"
# Challenge
# O(n) time

class Solution:
    """
    @param s: A string
    @param k: An integer
    @return: An integer
    """
    def lengthOfLongestSubstringKDistinct(self, s, k):
        # write your code here
        freq = {}
        i, j = 0, 0
        maxx = 0
        while j < len(s):
            if s[j] not in freq:
                freq[s[j]] = 1
            else:
                freq[s[j]] = freq[s[j]] + 1
            if len(freq) <= k:
                maxx = max(maxx, j - i + 1)
            if len(freq) > k:
                freq[s[i]] = freq[s[i]] - 1
                if freq[s[i]] == 0:
                    del freq[s[i]]
                i = i + 1
            j = j + 1
        return maxx