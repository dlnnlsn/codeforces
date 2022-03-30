#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int total = 0;
        int odd_index = 0;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num % 2) odd_index = i + 1;
            total += num;
        }
        if (total % 2 == 0) odd_index = 0;
        else {
            bool composite = false;
            for (int k = 3; k * k <= total; k += 2) {
                if (total % k == 0) {
                    composite = true;
                    break;
                }
            }
            if (composite) odd_index = 0;
        }

        int start = 1;
        if (odd_index == 1) start = 2;
        if (odd_index != 0) cout << n - 1 << endl;
        else cout << n << endl;
        cout << start;
        for (int i = start + 1; i <= n; ++i) {
            if (i == odd_index) continue;
            cout << " " << i;
        }
        cout << endl;
    }
}
