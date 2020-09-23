'''
https://leetcode.com/problems/fraction-to-recurring-decimal/
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

 

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
Example 4:

Input: numerator = 4, denominator = 333
Output: "0.(012)"
Example 5:

Input: numerator = 1, denominator = 5
Output: "0.2"
'''
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        '''
        Fractional value after decimal can be calculated by
        (remainder * 10) / denominator
        till remainder becomes 0 or it starts recurring
        This is more of a math question or trick question
        E.g., 1/4 
        remainder = 1 and denominator = 4
        1st fractional digit after decimal will be (1 * 10) // 4 that is 2
        next now, reaminder changes to (1 * 10) % 4 that is 2
        remainder = 2 and denominator = 4
        2nd fractional digit after decimal will be (2 * 10) // 4 that is 5
        next now, reaminder changes to (2 * 10) % 4 that is 0
        
        since remainder becomes 0 we can exit the loop and return the fractional value
        if it starts recurring then we can flag it appropriately.
        '''
        if numerator % denominator == 0:
            return str(numerator//denominator)
        result = []
        if numerator / denominator < 0:
            result.append("-")
        num, den = abs(numerator), abs(denominator)
        result.append(str(num//den))
        result.append('.')
        rem = num % den
        dicti = {}
        while rem != 0:
            if rem in dicti:
                result.insert(dicti[rem], "(")
                result.append(")")
                return ''.join(result)
            elif rem not in dicti:
                dicti[rem] = len(result)
            divisor = rem * 10
            result.append(str((divisor) // den))
            rem = divisor % den
        return ''.join(result)