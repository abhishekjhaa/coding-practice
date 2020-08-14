# -*- coding: utf-8 -*-
"""
Created on Wed Dec 13 11:29:37 2017

@author: Accolite
"""

def permutations():
    strng = input("Enter a string: ")
    print(getPermutation(strng))
    print(getPermutationAnotherWay(strng))

def getPermutation(remainder):
    listOfPermutations = []
    if len(remainder) == 0:
        listOfPermutations.append("")
        return listOfPermutations
    
    firstChar = remainder[0]
    permutations = getPermutation(remainder[1:])
    for permutation in permutations:
        for i in range(len(permutation) + 1): # important step add + 1
            listOfPermutations.append(permutation[0:i] + firstChar + permutation[i:])
    return listOfPermutations

def getPermutationAnotherWay(remainder):
    listOfPermutations = []
    if len(remainder) == 0:
        listOfPermutations.append("")
        return listOfPermutations
    
    for i in range(len(remainder)):
        words = getPermutationAnotherWay(remainder[0:i] + remainder[i+1:])
        for word in words:
            listOfPermutations.append(remainder[i] + word)
    
    return listOfPermutations
        