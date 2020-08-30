'''
https://leetcode.com/problems/merge-intervals/
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
'''

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        '''
        Recursive way:
        Make recursive calls by truncating 1st list on 0th index
        Base case is when intervals length will be less than equal to 1 where we return the intervals
        Compare the last index number of left truncated list to the 1st number of return intervals list
        merge if it overlaps and then return the result
        '''
        
        if len(intervals) <= 1:
            return intervals
        i = 1
        intervals.sort()
        print intervals
        while i < len(intervals):
            f00 = intervals[i-1][0]
            f01 = intervals[i-1][1]
            s00 = intervals[i][0]
            s01 = intervals[i][1]
            if f01 >= s00 and f00 <= s00 and f01 >= s01:
                intervals.pop(i)
                #if i <= len(intervals) and i > 1: #If  we are not using sort then we have to uncomment the if from all the conditions
                 #   i = i - 1
                continue
            if f01 >= s00 and f00 <= s00 and f01 <= s01:
                intervals.pop(i-1)
                intervals[i-1][0] = f00
                #if i <= len(intervals)  and i > 1:
                 #   i = i - 1
                continue
            if s01 >= f00 and s00 <= f00 and s01 <= f01:
                intervals.pop(i)
                intervals[i-1][0] = s00
                #if i <= len(intervals) and i > 1:
                 #   i = i - 1
                continue
            if s01 >= f00 and s00 <= f00 and s01 >= f01:
                intervals.pop(i-1)
                #if i <= len(intervals) and i > 1:
                 #   i = i - 1
                continue
            if s00 < f00:
                intervals[i-1], intervals[i] = intervals[i], intervals[i-1]
                #if i > 1:
                 #   i = i - 1
                continue
            i = i + 1
        return intervals
            
        '''
        #Recursive Way
        firstInterval = intervals[0]
        result = self.merge(intervals[1:]) # I forgot to add "self."
        resultFirstInterval = result[0]
        if firstInterval[0] >= resultFirstInterval[1]:
            result[0] = firstInterval
            firstInterval, resultFirstInterval = resultFirstInterval, firstInterval
            result = self.merge(result) # Didn't add this step at first
        if firstInterval[1] >= resultFirstInterval[0]:
            result[0][0] = min(firstInterval[0], result[0][0])
            result[0][1] = max(firstInterval[1], result[0][1])
            result = self.merge(result) # Didn't add this step at first
            return result
        else:
            result.insert(0, firstInterval)
            return result
        '''
        
        