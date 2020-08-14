# -*- coding: utf-8 -*-
"""
Created on Wed Dec 13 15:34:25 2017

@author: Accolite

CTCI : 8.8
"""


def duplicatePermutations():
    strng = input("Enter a string: ")
    hashmap = {}
    for char in strng:
        try:
            hashmap[char] = hashmap[char] + 1
        except:
            hashmap[char] = 1
            
    print(getPermutations(len(strng), hashmap))
    
def getPermutations(length, hashmap):
    listOfPermutation = []
    if length == 0:
        listOfPermutation.append("")
        return listOfPermutation
    
    for key in hashmap.keys():
        count = hashmap[key]
        if count > 0:
            hashmap[key] -= 1
            listOfWords = getPermutations(length - 1, hashmap)
            for word in listOfWords:
                listOfPermutation.append(key + word)
            hashmap[key] += 1
    return listOfPermutation
    