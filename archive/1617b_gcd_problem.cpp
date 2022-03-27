#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int k = 2; k < n; ++k) {
            if (gcd(n - 1, k) == 1) {
                cout << n - 1 - k << " " << k << " " << 1 << endl;
                break;
            }
        }
    }

    return 0;
}
