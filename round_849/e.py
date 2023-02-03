#!/usr/bin/env python3

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    total = sum(map(abs, a))
    num_negative = 0
    for num in a:
        if num < 0:
            num_negative += 1
    if num_negative % 2 == 1:
        total -= 2 * min(map(abs, a))
    print(total)
