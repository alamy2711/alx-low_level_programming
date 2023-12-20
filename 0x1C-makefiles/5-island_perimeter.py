#!/usr/bin/python3
"""Defines island_perimeter function."""


def island_perimeter(grid):
    """Return the perimeter of the island described in grid."""
    rows = len(grid)
    cols = len(grid[0])
    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]
    pr = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                for x, y in directions:
                    if grid[i + x][j + y] == 0:
                        pr += 1
    return pr
