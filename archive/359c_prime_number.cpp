#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int64_t pow(int64_t a, int64_t n, int64_t m) {
    int64_t result = 1;
    while (n > 0) {
        if (n % 2) result = (result * a) % m;
        n /= 2;
        a = (a * a) % m;
    }
    return result;
}

int main() {
    int n, x; cin >> n >> x;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num; a.push_back(num);
    }

    unordered_map<int, int> counts;
    priority_queue<int, vector<int>, greater<int>> exponents;
    for (int i = 0; i < n; ++i) {
        int exp = a[n - 1] - a[i];
        if (counts.count(exp) == 0) {
            counts[exp] = 0;
            exponents.push(exp);
        }
        ++counts[exp];
    } 

    int num_power_of_p = 0;

    while (!exponents.empty()) {
        int exp = exponents.top();
        exponents.pop();

        int coeff = counts[exp];
        while (coeff % x == 0) {
            coeff /= x;
            exp += 1;
        }

        if (exponents.empty() || exp < exponents.top()) {
            num_power_of_p = exp;
            break;
        }

        if (counts.count(exp) == 0) {
            counts[exp] = 0;
            exponents.push(exp);
        }
        counts[exp] += coeff;
    }

    int64_t gcd = pow(x, min(num_power_of_p, a[n - 1]), MOD);
    for (int i = 0; i < n - 1; ++i) gcd = (gcd * pow(x, a[i], MOD)) % MOD;

    cout << gcd << endl;

    return 0;
}
