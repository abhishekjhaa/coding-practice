'''
https://leetcode.com/problems/course-schedule/
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
'''
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        '''
        Idea is to first finish all the pre-requisites
        and if a course's pre-requisites are done then finish that course too 
        
        We can do this my making a graph of courses where we connect each course with its prerequisite
        we can mark the number of pre-requisites in a course by inDegree
        As soon as we finish the pre-requisite we can remove it dependency from its dependant courses
        by decrementing the the inDegree count of that course.
        As soon as we get inDegree count of 0 for a course we can mark it finished.
        
        If there is a cycle in the graph the nodes inDegree won't reduce to 0
        hence that node won't be traversed.
        '''
        if len(prerequisites) == 0:
            return True
        dicti = {}
        inDegree = [0]*numCourses
        for item in prerequisites:
            if item[1] not in dicti:
                dicti[item[1]] = [item[0]]
            else:
                (dicti[item[1]]).append(item[0])
            inDegree[item[0]] = inDegree[item[0]] + 1
        q = []
        i = 0
        while i < numCourses:
            if inDegree[i] == 0:
                q.append(i)
            i = i + 1
        n = numCourses
        while q:
            course = q.pop(0)
            n = n - 1
            if course in dicti:
                for dc in dicti[course]:
                    inDegree[dc] = inDegree[dc] - 1
                    if inDegree[dc] == 0:
                        q.append(dc)
        return n == 0;