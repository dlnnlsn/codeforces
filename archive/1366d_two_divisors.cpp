#include <iostream>
#include <vector>

using namespace std;

void print_list(const vector<int>& list) {
    cout << list[0];
    for (auto it = list.begin() + 1; it != list.end(); ++it) cout << " " << *it;
    cout << endl;
}

int main() {
    vector<int> prime_divisor;
    prime_divisor.reserve(1e7 + 1);
    for (int i = 0; i < 1e7 + 1; ++i) prime_divisor.push_back(i);
    
    for (int p = 2; p < 1e4; ++p) {
        if (prime_divisor[p] == p) {
            for (int m = p * p; m <= 1e7; m += p) prime_divisor[m] = p;
        }
    }

    int n; cin >> n;
    vector<int> d1; vector<int> d2;

    while (n--) {
        int a; cin >> a;
        int p = prime_divisor[a];
        int prime_power = 1;
        while (a % p == 0) {
            a /= p;
            prime_power *= p;
        }
        if (a == 1) {
            d1.push_back(-1); d2.push_back(-1);
        }
        else {
            d1.push_back(prime_power); d2.push_back(a);
        }
    }

    print_list(d1);
    print_list(d2);

    return 0;
}
