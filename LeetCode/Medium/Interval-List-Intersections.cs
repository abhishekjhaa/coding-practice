/*
https://leetcode.com/problems/interval-list-intersections/

You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a < b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
Example 3:

Input: firstList = [], secondList = [[4,8],[10,12]]
Output: []
Example 4:

Input: firstList = [[1,7]], secondList = [[3,10]]
Output: [[3,7]]
 

Constraints:

0 <= firstList.length, secondList.length <= 1000
firstList.length + secondList.length >= 1
0 <= starti < endi <= 109
endi < starti+1
0 <= startj < endj <= 109
endj < startj+1
*/
public class Solution {
    public int[][] IntervalIntersection(int[][] firstList, int[][] secondList) {
        var m = firstList.Length;
        var n = secondList.Length;
        var result = new List<List<int>>();
        int i = 0;
        int j = 0;
        while(i < m && j < n)
        {
            var f_start = firstList[i][0];
            var f_end = firstList[i][1];
            var s_start = secondList[j][0];
            var s_end = secondList[j][1];
            
            if(f_start <= s_end && s_start <= f_end)
            {
                result.Add(new List<int> {Math.Max(f_start, s_start), Math.Min(f_end, s_end)});
            }
            
            if(f_end <= s_end)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        var arr =  new int[result.Count][];
        i = 0;
        foreach(var item in result)
        {
            arr[i] = new int[2];
            arr[i][0] = item[0];
            arr[i][1] = item[1];
            i++;
        }
        
        return arr;
        //return AnotherWay(firstList, secondList);
    }
    
    private int[][] AnotherWay(int[][] firstList, int[][] secondList)
    {
        var m = firstList.Length;
        var n = secondList.Length;
        var result = new List<List<int>>();
        int i = 0;
        int j = 0;
        while(i < m && j < n)
        {
            if(firstList[i][0] < secondList[j][0] && firstList[i][1] > secondList[j][0] && firstList[i][1] < secondList[j][1])
            {
                result.Add(new List<int> {secondList[j][0], firstList[i][1]});
                i++;
            }
            else if(secondList[j][0] < firstList[i][0] && secondList[j][1] > firstList[i][0] && secondList[j][1] < firstList[i][1])
            {
                result.Add(new List<int> {firstList[i][0], secondList[j][1]});
                j++;
            }
            else if(firstList[i][0] <= secondList[j][0] && firstList[i][1] >= secondList[j][1])
            {
                result.Add(new List<int> {secondList[j][0], secondList[j][1]});
                j++;
            }
            else if(secondList[j][0] <= firstList[i][0] && secondList[j][1] >= firstList[i][1])
            {
                result.Add(new List<int> {firstList[i][0], firstList[i][1]});
                i++;
            }
            else if(firstList[i][0] == secondList[j][1])
            {
                result.Add(new List<int> {firstList[i][0], secondList[j][1]});
                j++;
            }
            else if(firstList[i][1] == secondList[j][0])
            {
                result.Add(new List<int> {firstList[i][1], secondList[j][0]});
                i++;
            }
            else if(firstList[i][0] > secondList[j][1])
            {
                j++;
            }
            else if(secondList[j][0] > firstList[i][1])
            {
                i++;
            }
        }
        
        var arr =  new int[result.Count][];
        i = 0;
        foreach(var item in result)
        {
            arr[i] = new int[2];
            arr[i][0] = item[0];
            arr[i][1] = item[1];
            i++;
        }
        
        return arr;
    }
}