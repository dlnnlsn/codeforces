#!/usr/bin/env python3

from math import lcm

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    candidate = lcm(a, b)
    if candidate == b:
        candidate = b * (b // a)
    print(candidate)
