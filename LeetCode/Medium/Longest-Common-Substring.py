# https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
# Given two strings. The task is to find the length of the longest common substring.


# Example 1:

# Input: S1 = "ABCDGH", S2 = "ACDGHR"
# Output: 4
# Explanation: The longest common substring
# is "CDGH" which has length 4.
# Example 2:

# Input: S1 = "ABC", S2 "ACB"
# Output: 1
# Explanation: The longest common substrings
# are "A", "B", "C" all having length 1.

# Your Task:
# You don't need to read input or print anything. Your task is to complete the function longestCommonSubstr() which takes the string S1, string S2 and their length n and m as inputs and returns the length of the longest common substring in S1 and S2.


# Expected Time Complexity: O(n*m).
# Expected Auxiliary Space: O(n*m).


# Constraints:
# 1<=n, m<=1000

class Solution:
    def longestCommonSubstr(self, S1, S2, n, m):
        array = [[0]*(len(S2)) for i in range(len(S1))]
        i, j, maxN = 0, 0, 0
        for i in range(len(S1)):
            for j in range(len(S2)):
                try:
                    if (i == 0 or j == 0 ) and S1[i] == S2[j]:
                        array[i][j] = 1;
                    if i > 0 and j > 0 and S1[i] == S2[j]:
                        array[i][j] = array[i-1][j-1] + 1;
                    maxN = max(maxN, array[i][j])
                except:
                    print("i = " + str(i) + " & j = " + str(j))
        return maxN;
#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n,m = input().strip().split(" ")
        n,m = int(n), int(m)
        S1 = input().strip()
        S2 = input().strip()
        
        
        ob=Solution()
        print(ob.longestCommonSubstr(S1, S2, n, m))
# }