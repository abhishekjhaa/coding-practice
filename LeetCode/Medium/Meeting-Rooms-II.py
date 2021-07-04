# https://leetcode.com/problems/meeting-rooms-ii/
# https://www.lintcode.com/problem/919/description
# Description
# Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

# Example
# Example1

# Input: intervals = [(0,30),(5,10),(15,20)]
# Output: 2
# Explanation:
# We need two meeting rooms
# room1: (0,30)
# room2: (5,10),(15,20)
# Example2

# Input: intervals = [(2,7)]
# Output: 1
# Explanation: 
# Only need one meeting room

import heapq
"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param intervals: an array of meeting time intervals
    @return: the minimum number of conference rooms required
    """
    def minMeetingRooms(self, intervals):
        if not intervals:
            return 0
        intervals.sort(key=lambda interval: interval.start)
        min_heap = [intervals[0].end] # stores only end_time
        
        for i in range(1, len(intervals)):
            interval = intervals[i]
            if interval.start >= min_heap[0]:
                heapq.heappop(min_heap)
            heapq.heappush(min_heap, interval.end)
        return len(min_heap)

