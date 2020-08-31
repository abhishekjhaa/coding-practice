'''
https://leetcode.com/problems/subsets/

https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

'''
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        '''
        I remember this problem from CTCI where we can represent the powerset based on the bits of the number
        '''
        if len(nums) < 1:
            return [[]]
        powerSet = 2**len(nums) - 1 #important step
        result = []
        while powerSet >= 0:
            num = powerSet
            temp = []
            i = 0
            while num > 0 and i < len(nums):
                if num & 1:
                    temp.append(nums[i])
                i = i + 1
                num = num >> 1
            result.append(temp)
            powerSet = powerSet - 1
        return result
                    
        
