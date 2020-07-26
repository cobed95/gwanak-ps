#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'arrangeStudents' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def arrangeStudents(a, b):
    # Write your code here
    a.sort()
    b.sort()

    idx_a = 0
    idx_b = 0

    last = None

    while idx_a != len(a) and idx_b != len(b):
        if a[idx_a] > b[idx_b]:
            if last == 'B':
                return False
            last = 'B'
            idx_b += 1
        elif a[idx_a] < b[idx_b]:
            if last == 'A':
                return False
            last = 'A'
            idx_a += 1
        else:
            if last == 'A':
                last = 'B'
                idx_b += 1
            else:
                last = 'A'
                idx_a += 1
    
    if idx_a == len(a) and len(b) - idx_b >= 2:
        return False
    if idx_b == len(b) and len(a) - idx_a >= 2:
        return False 

    return True

if __name__ == '__main__':
    # assert arrangeStudents([1,3], [2,4]) == True
    # assert arrangeStudents([2,3,5], [1,3,4]) == True
    # assert arrangeStudents([1,2], [3,4]) == False 
    # assert arrangeStudents([1,10, 5], [11,2, 5]) == True 
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        a = list(map(int, input().rstrip().split()))

        b = list(map(int, input().rstrip().split()))

        result = arrangeStudents(a, b)

        fptr.write(result + '\n')

    fptr.close()