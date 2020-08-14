# -*- coding: utf-8 -*-
"""
Created on Tue Dec 12 11:12:08 2017

@author: Accolite

CTCI : 8.6
"""

def allsubsets(strng):
    strnglen = len(strng)
    numOfSubsets = 2**strnglen;
    for i in range(numOfSubsets):
        j = i
        index = 0
        subset = ""
        while j > 0:
            if j & 1 == 1:
                subset += strng[index]
            index += 1
            j >>= 1
        print(subset + ",")
        
def allSubsets(strng):
    strnglen = len(strng)
    listOfSubset = []
    listOfSubset.append("")
    lastIndex = 0
    currentIndex = 0
    for i in range(strnglen):
        while lastIndex >= currentIndex:
            listOfSubset.append(listOfSubset[currentIndex] + strng[i])
            currentIndex += 1
        currentIndex = 0
        lastIndex = len(listOfSubset) - 1
    print(listOfSubset)
    