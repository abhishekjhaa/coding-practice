# -*- coding: utf-8 -*-
"""
Created on Thu Dec 14 17:10:36 2017

@author: Accolite
"""

def quickSort():
    arr = [1,8,5,3,2,4,1]
    low = 0
    high = len(arr) - 1
    quickSorted(arr, low, high)
    print(arr)
    
def quickSorted(arr, low, high):
    if low < high:
        pivot = getPivot(arr, low, high)
        quickSorted(arr, low, pivot - 1)
        quickSorted(arr, pivot + 1, high)
    
def getPivot(arr, low, high):
    pivot = arr[high]
    left = low
    right = high - 1
    while left <= right:
        while left < right and arr[left] < pivot:
            left += 1
        while right >= low and arr[right] >= pivot:
            right -= 1
        if left <= right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
    
    arr[left], arr[high] = arr[high], arr[left]
    return left