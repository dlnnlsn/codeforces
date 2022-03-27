#include <iostream>

using namespace std;

constexpr int64_t MOD = 998244353;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        int64_t product = 1;
        for (int i = 2; i <= n/2; ++i) {
            product = (((product * i) % MOD) * i) % MOD;
        }
        cout << product << endl;
    }
    return 0;
}
