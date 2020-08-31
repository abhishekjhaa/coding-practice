'''
https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
'''
class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        '''
        Idea is to use 2 pointer at the left and right side of array
        compare the numbers at left & right and 
        if number at left is greater than number at right swap
        if number is 2 move the right pointer till it encounters a smaller number
        
        Above is a wrong approach. Two pointer approach is not suitable for this, where both the pointers are moving.
        
        Iterating the array once is required. Keep indexs of 0 & 2
        push elements if they are either 0 or 2 on far left or right respectively.
        '''
        
        if len(nums) < 1:
            return None
        lastNonZero = 0
        firstNonTwo = len(nums) - 1
        i = 0
        while i <= firstNonTwo:
            if nums[i] == 0 and lastNonZero <= i:
                nums[lastNonZero], nums[i] = nums[i], nums[lastNonZero]
                lastNonZero = lastNonZero + 1
                #continue #Not required since numbers before this will already be sorted
            if nums[i] == 2 and i <= firstNonTwo:
                nums[firstNonTwo], nums[i] = nums[i], nums[firstNonTwo]
                firstNonTwo = firstNonTwo - 1
                continue
            i = i + 1
        return None
        
