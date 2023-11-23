#include <iostream>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int num_b = 0;
        int last_b = -1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == 'B') {
                num_b++;
                last_b = i;
            }
        }

        if (num_b == k) {
            cout << 0 << endl; continue;
        }

        if (num_b > k) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'B') num_b--;
                if (num_b == k) {
                    cout << 1 << endl;
                    cout << (i + 1) << " A" << endl;
                    break;
                }
            }
            continue;
        }

        int beginning_as = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                beginning_as = i; break;
            }
        }
        if (beginning_as >= (k - num_b)) {
            cout << 1 << endl;
            cout << (k - num_b) << " B" << endl;
            continue;
        }

        int bs_after = num_b;
        bool done = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') num_b--;
            if ((k - num_b) == (i + 1)) {
                cout << 1 << endl;
                cout << (i + 1) << " B" << endl;
                done = true;
                break;
            }
        }
        if (done) continue;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') bs_after--;
            if ((k - bs_after) < (i + 1)) {
                cout << 2 << endl;
                cout << (i + 1) << " A" << endl;
                cout << (k - bs_after) << " B" << endl;
                break;
            }
        }
    }
    return 0;
}
