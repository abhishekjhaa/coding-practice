/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
public class Solution {
    public int[][] Merge(int[][] intervals) {
        var result = new List<List<int>>();
        var i = 0;
        Array.Sort(intervals, (a, b) => { return a[0] - b[0]; });
        while(i < intervals.Length)
        {
            if(result.Count == 0)
            {
                result.Add(new List<int> {intervals[i][0], intervals[i][1]});
            }
            else
            {
                if(result[result.Count - 1][1] >= intervals[i][0] && result[result.Count - 1][0] <= intervals[i][1])
                {
                    result[result.Count - 1][0] = Math.Min(result[result.Count - 1][0], intervals[i][0]);
                    result[result.Count - 1][1] = Math.Max(result[result.Count - 1][1], intervals[i][1]);
                }
                else
                {
                    result.Add(new List<int> {intervals[i][0], intervals[i][1]});
                }
            }
            
            i++;
        }
        
        var r = new int[result.Count][];
        for(var j = 0; j < result.Count; j++)
        {
            r[j] = new int[2];
            r[j][0] = result[j][0];
            r[j][1] = result[j][1];
        }
        
        return r;
    }
}