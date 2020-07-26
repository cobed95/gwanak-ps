#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getNumberOfIntegers' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING L
#  2. STRING R
#  3. INTEGER K
#

def getNumberOfIntegers(L, R, K):
    # Write your code here
    count = 0
    for num in range(L+1, R+1):
        s = str(num)
        if len(s) - s.count('0') == K:
            count += 1
    return count


if __name__ == '__main__':
    # assert getNumberOfIntegers(1, 100, 1) == 18
    # assert getNumberOfIntegers(10, 55, 2) == 41 
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    L = input()

    R = input()

    K = int(input().strip())

    ans = getNumberOfIntegers(L, R, K)

    fptr.write(str(ans) + '\n')

    fptr.close()