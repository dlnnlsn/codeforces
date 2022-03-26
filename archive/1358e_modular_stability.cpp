#include <iostream>
#include <vector>

using namespace std;

int64_t mod_pow(int64_t a, int64_t n, int64_t m) {
    if (n == 0) return 1;
    int64_t result = mod_pow(a, n/2, m);
    result = (result * result) % m;
    if (n % 2) result = (result * a) % m;
    return result;
}

constexpr int64_t MOD = 998244353;

int64_t inverse(int64_t n) {
    return mod_pow(n, MOD - 2, MOD);
}

int main() {
    int n, k; cin >> n >> k;
    int64_t nCk = 1;
    int top = k - 1;
    int64_t total = 0;

    for (int first = n/k; first > 0; --first) {
        while ((n/first - 1) != top) {
            ++top;
            nCk = (nCk * top) % MOD;
            nCk = (nCk * inverse(top - k + 1)) % MOD;
        }
        total = (total + nCk) % MOD;
    }

    cout << total << endl;
}
