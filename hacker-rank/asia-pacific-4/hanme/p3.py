#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getMinEffort' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY C as parameter.
#
def getMinEffort(C):
    # Write your code here
    n = len(C)
    m = len(C[0])
    effort = []
    for _ in range(n+1):
        effort.append([0] * (m+1))

    helper(n, m, C, effort)

    result = effort[n][m]
    print(effort)  
    print(result)
    return result


def helper(n, m, G, E):
    for i in range(1, n+1):
        for j in range(1, m+1):
            left = abs(G[i-1][j-1] - G[i-1][j-2]) if j > 1 else 0
            up = abs(G[i-1][j-1] - G[i-2][j-1]) if i > 1 else 0 
            print("\n", i, j, left, up)
            if left <= up:
                if E[i][j-1] <= E[i-1][j]:
                    print(1)
                    # perfect. choose left
                    E[i][j] =  E[i][j-1] if E[i][j-1] > left else left 
                    print(E[i][j])
                elif E[i][j-1] > E[i-1][j] and E[i][j-1] <= up:
                    print(2)
                    # hew. choose left 
                    E[i][j] =  E[i][j-1] if E[i][j-1] > left else left
                    print(E[i][j])
                else:
                    print(3)
                    # disguise. choose up 
                    E[i][j] =  E[i-1][j] if E[i-1][j] > up else up
                    print(E[i][j])

            else:
                if E[i][j-1] >= E[i-1][j]:
                    print(4)
                    # perfect. choose up 
                    E[i][j] =  E[i-1][j] if E[i-1][j] > left else left
                    print(E[i][j])
                elif E[i][j] > E[i-1][j] and E[i-1][j] <= left:
                    print(5)
                    # hew. choose up 
                    E[i][j] =  E[i-1][j] if E[i-1][j] > up else up
                    print(E[i][j])
                else:
                    print(6)
                    # disguise. choose left 
                    E[i][j] =  E[i][j-1] if E[i][j-1] > left else left
                    print(E[i][j])
 


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    answer = getMinEffort(arr)

    fptr.write(str(answer) + '\n')

    fptr.close()
