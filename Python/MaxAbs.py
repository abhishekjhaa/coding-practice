# -*- coding: utf-8 -*-
"""
Created on Mon Jan 22 22:53:20 2018

@author: Accolite
"""

def maxArr(A):
    maxSum = -1
    maxCurr = 0
    left = 0
    prevLeft = 0
    right = 0
    for i in range(len(A)):
        maxCurr = abs(A[left] - A[i]) + abs(left - i)
        print(str(abs(A[left] - A[i]) + abs(left - i)))
        print(str(maxCurr), str(left), str(i))
        if maxCurr > maxSum:
            maxSum = maxCurr
            prevLeft = left
            right = i
        if maxCurr < 0:
            maxCurr = 0
            left = i + 1
        maxCurr = 0
    return maxSum

def test():
    print(maxArr([1, 3, -1]))