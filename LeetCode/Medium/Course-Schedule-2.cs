/*
https://leetcode.com/problems/course-schedule-ii/
There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/

public class Solution {
    public int[] FindOrder(int numCourses, int[][] prerequisites) {
        var courseGraph = new Dictionary<int, List<int>>();
        var inDegree = new int[numCourses];
        for(var i = 0; i < prerequisites.Length; i++)
        {
            var pre = prerequisites[i][1];
            var course = prerequisites[i][0];
            if(!courseGraph.ContainsKey(pre))
            {
                courseGraph[pre] = new List<int> {course};
            }
            else
            {
                courseGraph[pre].Add(course);
            }
            
            inDegree[course] += 1;
        }
        
        var q = new Queue<int>();
        var result = new List<int>();
        for (var i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
            {
                q.Enqueue(i);
                result.Add(i);
            }
        }
        
        var n = numCourses;
        while(q.Count > 0)
        {
            var c = q.Dequeue();
            n -= 1;
            if(courseGraph.ContainsKey(c))
            {
                foreach(var d in courseGraph[c])
                {
                    inDegree[d] -= 1;
                    if (inDegree[d] == 0)
                    {
                        q.Enqueue(d);
                        result.Add(d);
                    }
                }
            }
        }
        
        if (n == 0)
        {
            return result.ToArray();
        }
        
        return new int[0];
    }
}