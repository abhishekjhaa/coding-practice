'''
https://leetcode.com/problems/powx-n/
Implement pow(x, n), which calculates x raised to the power n (i.e. xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
'''

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        """
        Loop through n
        
        101 - 5
        010 - 2
      11001 - 25
      
      5**2 = 5 * 5 = 5 * (4 + 1) = 5*4 + 5*1 = 25
                                 10100 + 101 = 11001
      
        11 - 3
        10 - 2
      1001 - 9
        
        100 - 4
         10 - 2
      10000 - 16
        """
        
        if x == 1:
            return x
        if x == -1 and n % 2 == 0:
            return 1
        if x == -1 and n % 2 == 1:
            return -1
        if n == 0:
            return 1
        isPositive = True
        power = 1.0000
        if n < 0:
            isPositive = False
            n = -n
        while n > 0: # These series of steps are important
            if n & 1 != 0:
                power = power * x
            x = x * x
            n = n >> 1
        
        if isPositive:
            return power
        else:
            return 1/power