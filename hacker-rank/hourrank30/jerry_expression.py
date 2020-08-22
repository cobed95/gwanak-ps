#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING expression as parameter.
#

def solve(expression: str) -> [int]:
    return _solve(expression, 0)



def _solve(expression: str, target: int) -> [int]:
    # Write your code here
    if len(expression) == 3:
        return base_case(expression, 0)

    # find operands in the top level
    operator, operand = 0, 0
    cut = -1
    for i in range(1, len(expression)):
        if expression[i] in ['+', '-']:
            operator += 1
        else:
            operand += 1
        if operator + 1 == operand:
            cut = i
            break

    # compute result
    operand1 = expression[1:cut+1]
    operand2 = expression[cut+1:]
    last_is_minus = False
    val = 0
    while True:
        if last_is_minus:
            val_arg = val
            last_is_minus = False
        else:
            val_arg = val * -1
            last_is_minus = True
        if expression[0] == '+':
            res1 = _solve(operand1, val_arg)
            res2 = _solve(operand2, target - val_arg)
            if res1 is not None and res2 is not None:
                return res1.extend(res2)
        else:
            res1 = _solve(operand1, val_arg)
            res2 = _solve(operand2, val_arg - target)
            if res1 is not None and res2 is not None:
                return res1.extend(res2)
        val += 1



def base_case(expression: str, val: int) -> [int]:
    if expression[0] == '+':
        if val < 2:
            return None
        while True:
            n1 = 1
            if val - n1 > 0:
                return [n1, val-n1]
            n1 += 1
    else:
        while True:
            n1 = 1
            if n1 - val > 0:
                return [n1, n1-val]
            n1 += 1



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    expression = input()

    res = solve(expression)

    fptr.write('\n'.join(map(str, res)))
    fptr.write('\n')

    fptr.close()

