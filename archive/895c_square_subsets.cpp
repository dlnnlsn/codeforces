#include <iostream>
#include <vector>

using namespace std;

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
constexpr int64_t MOD = 1e9 + 7;

vector<int> types = { -1 };
void initialize_types() {
    for (int i = 1; i <= 70; ++i) {
        int tmp = i;
        int type = 0;
        for (int i = 0; i < primes.size(); ++i) {
            int exp = 0;
            while ((tmp % primes[i]) == 0) {
                tmp /= primes[i];
                ++exp;
            }
            if (exp % 2) {
                type |= (1 << i);
            }
        }
        types.push_back(type);
    }
}

int64_t pow(int64_t a, int n) {
    int64_t result = 1;
    while (n > 0) {
        if (n % 2) result = (result * a) % MOD;
        n /= 2;
        a = (a * a) % MOD;
    }
    return result;
}

int main() {
    initialize_types();

    int n; cin >> n;
    vector<int> counts(71, 0);
    for (int i = 0; i < n; ++i) {
        int num; cin >> num; ++counts[num];
    }

    vector<int64_t> dp(1 << primes.size(), 0);
    dp[0] = 1;

    for (int i = 1; i <= 70; ++i) {
        if (counts[i] == 0) continue;
        for (int type = 0; type < (1 << primes.size()); ++type) {
            if (type > (type ^ types[i])) continue;
            int64_t value = dp[type] + dp[type ^ types[i]];
            value = (value * pow(2, counts[i] - 1)) % MOD;
            dp[type] = value;
            dp[type ^ types[i]] = value;
        }
    }

    cout << ((dp[0] == 0) ? (MOD - 1) : dp[0] - 1) << endl;

    return 0;
}
