# -*- coding: utf-8 -*-
"""
Created on Tue Dec 19 11:41:06 2017

@author: Accolite
CTCI: 10.7
"""

import sys

def missingInt():
    listOfInt = []
    for i in range(1000000):
        if i != 10:
            listOfInt.append(i)
    findMissingInt(listOfInt)

def findMissingInt(listOfInt):
    bitVector = bytearray(len(listOfInt)//8 + 1)
    print(str(sys.getsizeof(bitVector)) +" Bytes")
    for i in listOfInt:
        bitVector[i//8] |= 1 << (i % 8)
    print(str(sys.getsizeof(bitVector)) +" Bytes")
    for i in range(len(listOfInt)):
        if bitVector[i//8] & (1 << i % 8) == 0:
            print(i)
            return
    
