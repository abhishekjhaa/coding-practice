# -*- coding: utf-8 -*-
"""
Created on Tue Dec 19 18:57:19 2017

@author: Accolite
CTCI: 10.8
"""
def findDuplicates():
    inpArr = []
    for i in range(1, 32001):
        inpArr.append(i)
    inpArr[10] = 3
    inpArr[983] = 42
    inpArr[93] = 420
    bitVector = bytearray(32000//8 + 1)
    for j in inpArr:
        if bitVector[j//8] & (1 << (j % 8)) > 0:
            print(j)
        else:
            bitVector[j//8] |= 1 << (j % 8) 
    
