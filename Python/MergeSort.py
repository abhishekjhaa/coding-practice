# -*- coding: utf-8 -*-
"""
Created on Thu Dec 14 15:52:31 2017

@author: Accolite
"""

def mergeSort():
    arr = [1,8,5,3,2,4,3]
    low = 0
    high = len(arr) - 1
    mergeSorted(arr, low, high)
    print(arr)

def mergeSorted(arr, low, high):
    if low < high:
        middle = (low + high)//2 # put // for integer division
        mergeSorted(arr, low, middle)
        mergeSorted(arr, middle + 1, high)
        merge(arr, low, middle, high)

def merge(arr, low, middle, high):
    tempArr = []
    for i in range(0, high + 1): #important step
        tempArr.append(arr[i])

    leftArrIndex = low
    rightArrIndex = middle + 1
    current = low
     
    while leftArrIndex <= middle and rightArrIndex <= high: 
        if tempArr[leftArrIndex] > tempArr[rightArrIndex]:
            arr[current] = tempArr[rightArrIndex]
            rightArrIndex += 1
        else:
            arr[current] = tempArr[leftArrIndex]
            leftArrIndex += 1
        current += 1
        
    while leftArrIndex <= middle:
        arr[current] = tempArr[leftArrIndex]
        leftArrIndex += 1
        current += 1
        
    