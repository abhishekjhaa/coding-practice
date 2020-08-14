# -*- coding: utf-8 -*-
"""
Created on Thu Jan  4 10:35:46 2018

@author: Accolite
"""

def Swap(x,y):
    x = x^y
    y = x^y
    x = x^y
    print(x)
    print(y)