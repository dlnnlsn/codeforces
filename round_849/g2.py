#!/usr/bin/env python3

from bisect import bisect

t = int(input())

for _ in range(t):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    left_cost = [num + index + 1 for (index, num) in enumerate(a)]
    costs = [(num + min(index + 1, n - index), index) for (index, num) in enumerate(a)]
    costs.sort()
    total_costs = [0] * n
    total_costs[0] = costs[0][0]
    pos = [0] * n
    pos[costs[0][1]] = 0
    for i in range(1, n):
        pos[costs[i][1]] = i
        total_costs[i] = total_costs[i - 1] + costs[i][0]
    max_used = 0
    for (index, cost) in enumerate(left_cost):
        if (cost > c): continue
        used = bisect(total_costs, c - cost)
        if pos[index] < used:
            if (used < n) and (total_costs[used] - costs[pos[index]][0] <= c - cost):
                used += 1
            used -= 1
        max_used = max(max_used, used + 1)
    print(max_used)
