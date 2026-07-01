#!/usr/bin/python3
'''
Module 0-nqueens
A program that solves the N queens problem
'''
import sys


if len(sys.argv) != 2:
    print('Usage: nqueens N')
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print('N must be a number')
    sys.exit(1)
if N < 4:
    print('N must be at least 4')
    sys.exit(1)


def solveNQueens(n):
    '''
    Solve the N queens problem
    '''
    col = set()
    pos = set()
    neg = set()

    final_result = []
    board = [[] for n in range(n)]

    def solve(row):
        '''recursive function to solve the n queens problem'''
        if row == n:
            '''base case'''
            final_result.append(board.copy())
            return
        for i in range(n):
            if i in col or (row + i) in pos or (row - i) in neg:
                continue

            col.add(i)
            pos.add(row + i)
            neg.add(row - i)

            board[row] = [row, i]

            solve(row + 1)

            col.remove(i)
            pos.remove(row + i)
            neg.remove(row - i)
            board[row] = []

    solve(0)
    return final_result


if __name__ == '__main__':
    result_boards = solveNQueens(N)
    for board in result_boards:
        print(board)
