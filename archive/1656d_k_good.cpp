#include <iostream>

using namespace std;

int64_t goodness(int64_t n) {
    int64_t power_of_two = n & ~(n - 1);
    if (power_of_two <= 1e9) {
        if (power_of_two * (2 * power_of_two + 1) <= n) return 2 * power_of_two;
    }
    int64_t odd_part = n / power_of_two;
    if (odd_part > 1 && odd_part < 2e9 && odd_part * (odd_part + 1) / 2 <= n) return odd_part;
    for (int64_t k = 3; k * k <= odd_part; k += 2) {
        if (odd_part % k) continue;
        return k;
    }
    return -1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int64_t n; cin >> n;
        cout << goodness(n) << endl;
    }
    return 0;
}
