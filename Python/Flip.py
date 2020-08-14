# -*- coding: utf-8 -*-
"""
Created on Mon Jan 22 11:22:45 2018

@author: Accolite
"""

def flip(A):
        print(A)
        allOnes = True
        initialNumberOfOnes = 0
        backwardOnes = []
        forwardOnes = []
        index = 0
        for char in A:
            if char != '1':
                allOnes = False
            else:
                initialNumberOfOnes += 1
            backwardOnes.append(initialNumberOfOnes)
            index += 1
        initialNumberOfOnes = 0
        for i in range(len(A)-1, -1, -1):
            if A[i] == '1':
                initialNumberOfOnes += 1
            forwardOnes.insert(0, initialNumberOfOnes)
        if allOnes:
            return []
        maxOnes = 0
        left = 0
        right = 0
        for i in range(len(A)):
            for j in range(i, len(A)):
                noOfOnes = 0
                p = i
                q = j
                while p <= q:
                    if A[p] == '0':
                        noOfOnes += 1
                    p += 1
                if i - 1 >= 0:
                  noOfOnes += backwardOnes[i - 1]
                if j + 1 < len(A):
                    noOfOnes += forwardOnes[j + 1]
                if maxOnes < noOfOnes:
                    maxOnes = noOfOnes
                    left = i
                    right = j
        return [left+1, right+1]
                    

def test():
    print(flip("100101101"))