#!/usr/bin/python3
"""
    grid structures.
"""


def island_perimeter(grid):
    """
    Computes the perimeter of the island described in the grid.

    Args:
    grid(list of list of integers): for each integer,
    0 represents water and 1 represents land.

    Return:
        int: the perimeter of the island.
    """

    height = len(grid)
    width = len(grid[0])
    edges = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j]:
                if i <= 0 or not grid[i - 1][j]:
                    edges += 1
                if j <= 0 or not grid[i][j - 1]:
                    edges += 1
                if j >= width - 1 or not grid[i][j + 1]:
                    edges += 1
                if i >= height - 1 or not grid[i + 1][j]:
                    edges += 1
    return edges
