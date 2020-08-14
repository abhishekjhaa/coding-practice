# -*- coding: utf-8 -*-
"""
Created on Sun Jan  7 22:43:15 2018

@author: Accolite
CTCI: 16.6
"""

import sys

def smallestDifference():
    #arr1 = [1,3,15,11,2]
    #arr2 = [23,127,235,19, 8]
    
    arr1 = [1,2,8,15]
    arr2 = [4,12,16,23,127,235]
    if len(arr1) > len(arr2):
        arr1, arr2 = arr2, arr1
    
    arr2.sort()
    
    minimum = sys.maxsize
    
    for i in range(len(arr1)):
        low = 0
        high = len(arr2)
        while(low < high):
            mid = (low + high)//2
            print("Mid = " + str(mid))
            if arr2[mid] == arr1[i]:
                return 0
            elif arr2[low] > arr1[i]:
                high = low
                break
            elif arr2[high - 1] < arr1[i]:
                low = high - 1
                break
            elif arr2[mid] > arr1[i]:
                high = mid
                print("High = " + str(high))
            else:
                low = mid
                print("Low = " + str(low))
        print("Search int: " + str(arr1[i]) + " Low = " + str(arr2[low]) + " High = " + str(arr2[high]))
        if minimum > abs(arr2[high] - arr1[i]):
            minimum = abs(arr2[high] - arr1[i])
        if minimum > abs(arr2[low] - arr1[i]):
            minimum = abs(arr2[low] - arr1[i])
    
    return minimum