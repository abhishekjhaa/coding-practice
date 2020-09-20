'''
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
'''
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        '''
        If array has no odd number of negative numbers and no 0 then maxsubarray would be the array
        if array has a 0 then we need to check what is the max Product before that and compare it with 0
        and store the maxProduct and start from next index
        if array has negative number then we need to check for next negative number 
        so that thier multiplication becomes positive
        if no next negative number found then store the maxProduct and start again from negative numbers next index
        
        Good Idea: https://leetcode.com/problems/maximum-product-subarray/discuss/48302/2-Passes-scan-beats-99
        '''
        if len(nums) < 1:
            return 0
        maxProduct = -sys.maxint - 1
        i = 0
        product =  1
        
        while i < len(nums):
            product = product*nums[i]
            maxProduct = max(maxProduct, product)
            if nums[i] == 0:
                product = 1
            i = i + 1
        product = 1
        i = len(nums) - 1
        while i >= 0:
            product = product*nums[i]
            maxProduct = max(maxProduct, product)
            if nums[i] == 0:
                product = 1
            i = i - 1
        return maxProduct