#!/usr/bin/env python3

t = int(input())

dx = {"U": 0, "D": 0, "L": -1, "R": 1}
dy = {"U": 1, "D": -1, "L": 0, "R": 0}

for _ in range(t):
    n = int(input())
    dirs = input()
    x, y = 0, 0
    passes_candy = False
    for step in dirs:
        x += dx[step]
        y += dy[step]
        if (x == 1) and (y == 1):
            passes_candy = True
            break
    print("YES" if passes_candy else "NO")
