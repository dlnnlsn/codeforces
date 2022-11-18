#!/usr/bin/env python3

T = int(input())


def best(h, astro, serum_order):
    absorbed = 0
    serum_index = 0
    for p in astro:
        while p >= h:
            if serum_index == 3:
                return absorbed
            h *= serum_order[serum_index]
            serum_index += 1
        absorbed += 1
        h += (p // 2)
    return absorbed


for _ in range(T):
    n, h = map(int, input().split())
    astro = list(map(int, input().split()))
    astro.sort()
    print(max(
        best(h, astro, (3, 2, 2)),
        best(h, astro, (2, 3, 2)),
        best(h, astro, (2, 2, 3))
    ))
