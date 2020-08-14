# -*- coding: utf-8 -*-
"""
Created on Sun Jan 21 19:22:10 2018

@author: Accolite
"""

def solve(A):
        A.sort()
        arrLen = len(A)
        print("ArrLen: ", str(arrLen))
        print(A)
        count = 0
        for i in range(arrLen):
            if A[i] == arrLen - 1 - i:
                j = i + 1
                while j < arrLen and A[j] > A[i]:
                    count += 1
                    j += 1
                    print("Here is the num: ",str(A[i]))
                if count == A[i]:
                    return 1
            count = 0
        return -1