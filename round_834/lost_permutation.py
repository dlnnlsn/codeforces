#!/usr/bin/env python3

from math import sqrt

T = int(input())

for _ in range(T):
    m, s = map(int, input().split())
    nums = list(map(int, input().split()))
    duplicates = False
    nums_set = set()
    for n in nums:
        if n in nums_set:
            duplicates = True
            break
        nums_set.add(n)
    if duplicates:
        print("No")
        continue
    total = sum(nums) + s
    bound = (-1 + int(sqrt(1 + 8 * total))) // 2
    if (bound * (bound + 1)) // 2 != total:
        print("No")
        continue
    if max(nums) > bound:
        print("No")
        continue
    if min(nums) < 1:
        print("No")
        continue
    print("Yes")
