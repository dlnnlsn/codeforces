#!/usr/bin/env python3

MOD = 998244353


def mod_inverse(m, n):
    original_n = n
    s, t, u, v = 1, 0, 0, 1
    while n != 0:
        q = m // n
        s, t, u, v = u, v, s - q * u, t - q * v
        m, n = n, m % n
    return s % original_n


n, p, k = map(int, input().split())

answers = [0] * (k + 1)
answers[0] = 1
answer = 1
pr = 1
pn = pow(p, n, MOD)
p_inverse = mod_inverse(p, MOD)
p_ir = 1

for r in range(1, min(k + 1, n + 1)):
    answer = (answer * (pn - pr)) % MOD
    answer = (answer * (pn - pr)) % MOD
    answer = (answer * p_ir) % MOD
    p_ir = (p_ir * p_inverse) % MOD
    pr = (pr * p) % MOD
    answer = (answer * mod_inverse(pr - 1, MOD)) % MOD
    answers[r] = answer

print(" ".join(map(str, answers)))
