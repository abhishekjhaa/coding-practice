# -*- coding: utf-8 -*-
"""
Created on Fri Jan 19 09:59:29 2018

@author: Accolite
"""

def plusOne(A):
        last = A[-1] + 1
        A[-1] = last % 10
        carry =  last // 10
        if carry > 0:
            for i in range(len(A) - 2, -1, -1):
                sumd = A[i]+carry
                A[i] = (sumd)%10
                carry = (sumd)//10
        if carry > 0:
            A.insert(0, carry)
        return A