#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumMoves' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER d
#

def minimumMoves(s, d):
    # Write your code here
    length = len(s)
    given_string = s
    count = 0
    idx = d // 2
    for i in range(length-d):
        substring = given_string[i:i+d]
        try:
            substring.index('1', i, i+d)
        except:
            s = list(given_string)
            s[i+idx] = '1'
            given_string = "".join(s) 
            count += 1
    return count




if __name__ == '__main__':
    # assert minimumMoves("00100", 2) == 2
    # assert minimumMoves("101", 2) == 0

    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    d = int(input().strip())

    result = minimumMoves(s, d)

    fptr.write(str(result) + '\n')

    fptr.close()





