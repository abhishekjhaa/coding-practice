# -*- coding: utf-8 -*-
"""
Created on Tue Dec 19 10:19:29 2017

@author: Accolite
CTCI 10.5
"""

def sparseSearch():
    inputArr = ["at","", "", "", "", "", "", "", "", "dad", "", ""]
    if (find("dad", inputArr, 0, len(inputArr) - 1)):
        print("Found It")
    else:
        print("Not Found")

def find(strng, inputArr, first, last):
    if first > last:
        return False
    mid = (first + last)//2
    if inputArr[mid] == "" and strng != "":
        return find(strng, inputArr, first, mid - 1) or find(strng, inputArr, mid + 1, last)
    elif inputArr[mid] == strng:
        return True
    elif inputArr[mid] > strng:
        return find(strng, inputArr, first, mid - 1)
    else:
        return find(strng, inputArr, mid + 1, last)
