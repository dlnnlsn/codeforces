#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        unsigned int b_total = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            cin >> b; b_total ^= b;
        }
        if (n % 2) {
            cout << b_total << endl;
        }
        else {
            cout << (b_total == 0 ? 0 : -1) << endl;
        }
    }
    return 0;
}
