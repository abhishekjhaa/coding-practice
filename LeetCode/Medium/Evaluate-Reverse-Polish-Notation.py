'''
https://leetcode.com/problems/evaluate-reverse-polish-notation/
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
'''
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        '''
        Idea is to put every number we encounter to a stack
        and if a operator is encounterd then pop 2 numbers from the stack and apply the operator.
        '''
        i = 0
        stack = []
        while i < len(tokens):
            if tokens[i] == '+':
                stack.append(stack.pop()+stack.pop())
            elif tokens[i] == '-':
                stack.append(-stack.pop()+stack.pop())
            elif tokens[i] == '*':
                stack.append(stack.pop()*stack.pop())
            elif tokens[i] == '/':
                num2 = stack.pop()
                num1 = stack.pop()
                result = num1//num2
                if num1 % num2 == 0 or result >= 0:
                    stack.append(result)
                else:
                    stack.append(result+1)
            else:
                stack.append(int(tokens[i]))
            i = i + 1
        return stack.pop()
        