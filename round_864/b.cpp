#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> table[i][j];
            }
        }
        int needed = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (table[i][j] != table[n - i - 1][n - j - 1]) {
                    needed++;
                }
            }
        }
        k -= needed/2;
        if (k < 0) {
            cout << "NO" << endl;
            continue;
        }
        if ((k % 2) == 0) {
            cout << "YES" << endl;
            continue;
        }
        cout << ((n % 2) == 0 ? "NO" : "YES") << endl;
    }
    return 0;
}
