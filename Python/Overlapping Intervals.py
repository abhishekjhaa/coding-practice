# -*- coding: utf-8 -*-
"""
Created on Sat Jan 20 13:51:53 2018

@author: Accolite
"""

# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
        
def merge(intervals):
        intervalLength = len(intervals)
        i = 0
        while i < intervalLength:
            collapsed = False
            print("i = ", str(i))
            print("Comparing to: ", str(intervals[i].start), str(intervals[i].end))
            j = i + 1
            print("intervalLength", str(intervalLength))
            while j < intervalLength:
                print("j = ", str(j))
                if intervals[i].end < intervals[j].start or intervals[j].end < intervals[i].start:
                    print("Skipped: ", str(intervals[j].start), str(intervals[j].end))
                    if intervals[i].start > intervals[j].start:
                        intervals[i], intervals[j] =  intervals[j], intervals[i]
                    j += 1
                else:
                    intervals[i].start = min(intervals[i].start, intervals[j].start)
                    intervals[i].end = max(intervals[i].end, intervals[j].end)
                    print(str(intervals[j].start), str(intervals[j].end))
                    del(intervals[j])
                    intervalLength -= 1
                    collapsed = True
            if not collapsed:
                i += 1
        return intervals

def insert(intervals, new_interval):
        if new_interval.start > new_interval.end:
            new_interval.start, new_interval.end = new_interval.end, new_interval.start
        merged = False
        for interval in intervals:
            if not (interval.end < new_interval.start or new_interval.end < interval.start):
                print("merged: ", str(interval.start), str(interval.end), str(new_interval.start), str(new_interval.end))
                interval.start = min(interval.start, new_interval.start)
                interval.end = max(interval.end, new_interval.end)
                merged = True
        if not merged:
            print("True")
            intervals.append(new_interval)
        print("False")
        intervals.sort(key = lambda x: x.start)
        i = 0
        intervalLength = len(intervals)
        while i < intervalLength:
            collapsed = False
            print("i = ", str(i))
            print("Comparing to: ", str(intervals[i].start), str(intervals[i].end))
            print("intervalLength", str(intervalLength))
            j = i + 1
            while j < intervalLength:
                print("j = ", str(j))
                if not (intervals[i].end < intervals[j].start or intervals[j].end < intervals[i].start):
                    intervals[i].start = min(intervals[i].start, intervals[j].start)
                    intervals[i].end = max(intervals[i].end, intervals[j].end)
                    print(str(intervals[j].start), str(intervals[j].end))
                    del(intervals[j])
                    intervalLength -= 1
                    collapsed = True
                else:
                    #print("Skipped: ", str(intervals[j].start), str(intervals[j].end))
                    j += 1
            if not collapsed:
                i += 1
        return intervals
                


def test():
    #t = [ (54, 75), (56, 60), (61, 86), (22, 43), (56, 87), (32, 53), (14, 81), (64, 65), (9, 42), (12, 33), (22, 58), (84, 90), (27, 59), (41, 48), (43, 47), (22, 29), (16, 23), (41, 72), (15, 87), (20, 59), (45, 84), (14, 77), (72, 93), (20, 58), (47, 53), (25, 88), (5, 89), (34, 97), (14, 47) ]
    #t = [ (47, 76), (51, 99), (28, 78), (54, 94), (12, 72), (31, 72), (12, 55), (24, 40), (59, 79), (41, 100), (46, 99), (5, 27), (13, 23), (9, 69), (39, 75), (51, 53), (81, 98), (14, 14), (27, 89), (73, 78), (28, 35), (19, 30), (39, 87), (60, 94), (71, 90), (9, 44), (56, 79), (58, 70), (25, 76), (18, 46), (14, 96), (43, 95), (70, 77), (13, 59), (52, 91), (47, 56), (63, 67), (28, 39), (51, 92), (30, 66), (4, 4), (29, 92), (58, 90), (6, 20), (31, 93), (52, 75), (41, 41), (64, 89), (64, 66), (24, 90), (25, 46), (39, 49), (15, 99), (50, 99), (9, 34), (58, 96), (85, 86), (13, 68), (45, 57), (55, 56), (60, 74), (89, 98), (23, 79), (16, 59), (56, 57), (54, 85), (16, 29), (72, 86), (10, 45), (6, 25), (19, 55), (21, 21), (17, 83), (49, 86), (67, 84), (8, 48), (63, 85), (5, 31), (43, 48), (57, 62), (22, 68), (48, 92), (36, 77), (27, 63), (39, 83), (38, 54), (31, 69), (36, 65), (52, 68) ]
    t = [ (6037774, 6198243), (6726550, 7004541), (8842554, 10866536), (11027721, 11341296), (11972532, 14746848), (16374805, 16706396), (17557262, 20518214), (22139780, 22379559), (27212352, 28404611), (28921768, 29621583), (29823256, 32060921), (33950165, 36418956), (37225039, 37785557), (40087908, 41184444), (41922814, 45297414), (48142402, 48244133), (48622983, 50443163), (50898369, 55612831), (57030757, 58120901), (59772759, 59943999), (61141939, 64859907), (65277782, 65296274), (67497842, 68386607), (70414085, 73339545), (73896106, 75605861), (79672668, 84539434), (84821550, 86558001), (91116470, 92198054), (96147808, 98979097) ]
    intervals = []
    for item in t:
        intervals.append(Interval(item[0], item[1]))
    
    #inter = merge(intervals)
    inter = insert(intervals, Interval(36210193, 61984219))
    for item in inter:
        print(str(item.start), str(item.end))