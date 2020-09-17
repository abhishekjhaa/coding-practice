'''
https://leetcode.com/problems/word-break/
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
'''

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        '''
        Loop through dictionary
        find the substring if present
        recurse on remaining substring
        else look to next word in dictionary
        '''
        def wordBreaks(s, wordDict, dicti):
            print s
            if s == "":
                return True
            for word in wordDict:
                result = s.find(word)
                if result >= 0:
                    res1 = False
                    res2 = False
                    if s[0:result] in dicti:
                        res1 = dicti[s[0:result]]
                    else:
                        res1 = wordBreaks(s[0:result], wordDict, dicti)
                        dicti[s[0:result]] = res1
                    if res1:
                        if s[result+len(word):] in dicti:
                            res2 = dicti[s[result+len(word):]]
                        else:
                            res2 = wordBreaks(s[result+len(word):], wordDict, dicti)
                            dicti[s[result+len(word):]] = res2
                    if res1 and res2:
                        return True
            return False
        dicti = {}
        return wordBreaks(s, wordDict, dicti)
        