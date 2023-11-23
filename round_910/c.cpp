#include <iostream>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int min_steps = m + n - 2;
        if (k < min_steps) {
            cout << "NO" << endl;
            continue;
        }
        if ((k % 2) != (min_steps % 2)) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << "R"; for (int i = 1; i < m - 1; i++) cout << " R";
        cout << endl;
        for (int i = 1; i < n; i++) {
            cout << ((i % 2) ? "R" : "B");
            for (int j = 1; j < m - 1; j++) {
                cout << (((i + j) % 2) ? " R" : " B");
            }
            cout << endl;
        }
        for (int i = 0; i < n - 1; i++) {
            if (i % 2) {
                cout << "R"; for (int j = 1; j < m; j++) cout << " R";
            }
            else {
                cout << "B"; for (int j = 1; j < m; j++) cout << " B";
            }
            cout << endl;
        }
    }

    return 0;
}
