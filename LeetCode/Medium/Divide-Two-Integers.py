'''
https://leetcode.com/problems/divide-two-integers/
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
'''
class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        '''
        1st approach:
        strip the sign of dividend and divisor before hand and keep it in a flag
        Keep adding the divisor by itself till it is more than dividend, keep the count
        
        It gives time limit exceeded
        
        1010 -> 10
        0011 -> 3
        
        2nd approach:
        10/3 = 6/3 + 3/3 + 1/3 = 2 + 1 + 1/3
        Any number shifted left by a bit gets multiplied by 2. So in above example:
        Shifting 3 to right right makes it 3*2 = 6  
        Shift the bits of divisor till it is more than equal to dividend
        capture the number of bits shifted and add it to existing count
        substract the dividend from shifted divisor number
        repeate the process till dividend becomes 0

        Time complexity will be Log(n)*Log(n)
        '''
        isPositive = 1
        if dividend < 0:
            isPositive = -isPositive
            dividend = -dividend
        if divisor < 0:
            isPositive = -isPositive
            divisor = -divisor
        quotient = 0
        while dividend > 0:
            shift = 0
            while (divisor << shift) <= dividend:
                shift = shift + 1
            if shift > 0:
                quotient = quotient + 2**(shift - 1)
                dividend = dividend - (divisor << (shift - 1))
            else:
                break
        result = isPositive*quotient
        if result >= 2**31:
            return 2**31 - 1
        elif result < -2**31:
            return -2**31
        else:
            return result
        
