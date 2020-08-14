# -*- coding: utf-8 -*-
"""
Created on Thu Dec 14 20:56:53 2017

@author: Accolite
"""

def HeapSort():
    arr = [1,8,5,3,2,4,1]
    n = len(arr)
    for i in range(n - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
    print(arr)
        
def heapify(arr, n, i):
    #heapify tree with node rooted at i
    leftChild = 2*i + 1
    rightChild = 2*i + 2
    
    largestChild = i
    
    if leftChild < n and arr[leftChild] > arr[i]:
        largestChild = leftChild
    if rightChild < n  and arr[rightChild] > arr[largestChild]:
        largestChild = rightChild
    
    if i != largestChild:
        arr[i], arr[largestChild] = arr[largestChild], arr[i]
        heapify(arr, n, largestChild)
            