#!/usr/bin/env python3

t = int(input())

for _ in range(t):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] += i + 1
    a.sort()
    used = 0
    while (used < n) and (c >= a[used]):
        c -= a[used]
        used += 1
    print(used)
