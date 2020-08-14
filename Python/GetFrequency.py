# -*- coding: utf-8 -*-
"""
Created on Thu Jan  4 10:43:27 2018

@author: Accolite
CTCT 16.2
"""

def GetFrequency(book, searchWord):
    myhash = {}
    for word in book:
        word = word.strip().lower()
        if word != "":
            try:
                myhash[word] += 1
            except:
                myhash[word] = 1
    if searchWord in myhash.keys():
        print(myhash[searchWord])
    else:
        print("Word Not Found")
    print(myhash)