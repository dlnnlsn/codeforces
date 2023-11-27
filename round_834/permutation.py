#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    n = int(input())
    b = list(map(int, input().split()))
    answer = [None] * n
    b_indexes = {}
    for i, b_item in enumerate(b):
        b_indexes[b_item] = i
        answer[2 * i + 1] = b_item

    possible = True
    available = []
    for i in range(1, n + 1):
        if i in b_indexes:
            if len(available) == 0:
                possible = False
                break
            answer[2 * b_indexes[i]] = available.pop(0)
        else:
            available.append(i)
    if possible:
        print(" ".join(map(str, answer)))
    else:
        print("-1")
