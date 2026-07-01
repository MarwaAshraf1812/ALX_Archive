#!/usr/bin/python3
"""
0. minOperations
"""


def minOperations(n):
    """
    Gets fewest # of operations needed to result in exactly n H characters
    """
    if n <= 0:
        return 0
    operation, factor = 0, 2
    while factor * factor <= n:
        while n % factor == 0:
            n //= factor
            operation += factor
        factor += 1
    if n > 1:
        operation += n
    return operation
