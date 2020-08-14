# -*- coding: utf-8 -*-
"""
Created on Tue Feb  6 17:39:23 2018

@author: Accolite
"""

def AreEqual():
    inp = input().split("\n")
    noOfTestCases = int(inp[0])
    for j in range(noOfTestCases):
        arrLength = int(inp[3*j+1])
        arr1 = ParseArr(inp[3*j+2].split(" "))
        arr2 = ParseArr(inp[3*j+3].split(" "))
        CompareArray(arr1, arr2)

def CompareArray(arr1, arr2):
    comp = [-1]*1001
    missingNum = -1
    missingNumCount = 0
    for i in arr1:
        comp[i] += 1
    for i in arr2:
        if comp[i] == -1:
            missingNum = i
            missingNumCount += 1
        comp[i] -= 1

    if missingNumCount == 0:
        print("Yes")
        return
    if missingNumCount > 1:
        print("No")
        return
    
    otherNum = -1
    for i in range(len(comp)):
        if comp[i] > -1:
            otherNum = i
            
    if otherNum > missingNum:
        diff = otherNum - missingNum
        print(str(diff) + " 2")
    else:
        diff = missingNum - otherNum
        print(str(diff) + " 1")

def ParseArr(arr):
    i = 0
    while i < len(arr):
        if arr[i] == '':
            del (arr[i])
        else:
            arr[i] = int(arr[i])
            i += 1
    return arr
            
        