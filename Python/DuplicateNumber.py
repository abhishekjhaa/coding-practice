# -*- coding: utf-8 -*-
"""
Created on Sat Jan 20 13:19:19 2018

@author: Accolite
"""

def repeatedNumber(A):
        i = 0
        while i < len(A):
            if A[i] != i:
                if  A[i] != A[A[i]]:
                    num =  A[i]
                    A[i], A[num] = A[num], A[i]
                else:
                    return A[i]
            else:
                i += 1