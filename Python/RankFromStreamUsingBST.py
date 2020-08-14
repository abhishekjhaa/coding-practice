# -*- coding: utf-8 -*-
"""
Created on Wed Dec 20 09:36:42 2017

@author: Accolite

CTCI 10.10
"""
def rankFromStreamUsingBST():
    # 5 1 4 4 5 9 7 13 3
    root = BST(20)
    root.insertNew(15)
    root.insertNew(25)
    root.insertNew(10)
    root.insertNew(23)
    root.insertNew(5)
    root.insertNew(13)
    root.insertNew(24)
    
    print(root.getRank(13))

class BST(object):
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.leftSize = 0
        
    def insertNew(self, newData):
        if self.data >= newData:
            if self.left == None:
                self.left = BST(newData)
            else:
                self.left.insertNew(newData)
            self.leftSize += 1
        elif self.data < newData:
            if self.right == None:
                self.right = BST(newData)
            else:
                self.right.insertNew(newData)
    def getRank(self, data):
        if self.data == data:
            return self.leftSize
        elif self.data > data:
            if self.left != None:
                return self.left.getRank(data)
            else:
                return -1
        else:
            if self.right != None:
                rank = self.right.getRank(data)
                if rank != -1:
                    return self.leftSize + 1 + rank
                else:
                    return rank
            else:
                return -1

def rankFromStreamUsingBSTTestCase():
    # 5 1 4 4 5 9 7 13 3
    root = BST(5)
    root.insertNew(1)
    root.insertNew(4)
    root.insertNew(4)
    root.insertNew(5)
    root.insertNew(9)
    root.insertNew(7)
    root.insertNew(13)
    root.insertNew(3)
    
    print(root.getRank(1))
    print(root.getRank(3))
    print(root.getRank(4))