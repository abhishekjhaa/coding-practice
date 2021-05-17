/*
https://leetcode.com/problems/insert-interval/
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
Example 3:

Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
Example 4:

Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
Example 5:

Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 105
*/

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        i = 0
        firstOverlapIndex = -1
        while i < len(intervals):
            if newInterval[0] < intervals[i][0]:
                firstOverlapIndex = i
                break
            i = i + 1
        if firstOverlapIndex > -1:
            intervals.insert(i, newInterval)
        else:
            intervals.append(newInterval)
        i = 1
        result = [[intervals[0][0], intervals[0][1]]]
        while i < len(intervals):
            if result[len(result) - 1][1] >= intervals[i][0]:
                result[len(result) - 1][1] = max(result[len(result) - 1][1], intervals[i][1])
            elif result[len(result) - 1][0] <= intervals[i][1] and result[len(result) - 1][1] > intervals[i][0]:
                result[len(result) - 1][0] = min(result[len(result) - 1][0], intervals[i][0])
            else:
                result.append([intervals[i][0], intervals[i][1]])
            i = i + 1
        return result