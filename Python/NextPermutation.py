# -*- coding: utf-8 -*-
"""
Created on Wed Jan 31 17:55:53 2018

@author: Accolite
"""

def nextPermutation(A):
        for i in range(len(A) -1, -1, -1):
            if i > 0 and A[i] > A[i - 1]:
                j = i + 1
                maxIndex = i
                while j < len(A):
                    if A[j] > A[i - 1] and A[j] < A[maxIndex]:
                        maxIndex = j
                    j += 1
                A[i - 1], A[maxIndex] = A[maxIndex], A[i - 1]
                j = i
                k = len(A) - 1
                while j < k:
                    A[j], A[k] = A[k], A[j]
                    k -= 1
                    j += 1
                return A
        A.reverse()
        return A
def Test():
    arr = [ 873, 855, 693, 461, 634, 102, 207, 58, 60, 972, 50, 20, 406, 90, 494, 684, 572, 841, 253, 734, 937, 803, 482, 147, 987, 914, 997, 807, 866, 262, 526, 229, 891, 985, 905, 824, 507 ]
    #arr = [ 839, 776, 843, 422, 252, 385, 543, 94, 711, 636, 517, 257, 222 ]
    print(nextPermutation(arr))