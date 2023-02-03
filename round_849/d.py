#!/usr/bin/env python3

t = int(input())

for _ in range(t):
    n = int(input())
    s = input()
    distinct_start = 0
    distinct_end = 0
    chars_start = {}
    chars_end = {}
    for c in s:
        if c in chars_end:
            chars_end[c] += 1
        else:
            chars_end[c] = 1
            distinct_end += 1
    maximum_sum = 0
    for c in s:
        if c in chars_start:
            chars_start[c] += 1
        else:
            chars_start[c] = 1
            distinct_start += 1
        chars_end[c] -= 1
        if chars_end[c] == 0:
            distinct_end -= 1
        maximum_sum = max(maximum_sum, distinct_start + distinct_end)
    print(maximum_sum)
        
