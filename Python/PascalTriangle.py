# -*- coding: utf-8 -*-
"""
Created on Fri Jan 19 11:29:56 2018

@author: Accolite
"""

def getRow(A):
        if A == 0:
            return 1
        previousList = [[1]]
        for i in range(1, A+1):
            newList = [1]
            for j in range(1, len(previousList)):
                newList.append(previousList[j] + previousList[j - 1])
            newList.append(1)
            previousList = newList
        return previousList