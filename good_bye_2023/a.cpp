#include <iostream>

using namespace std;

int main() {
    
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int product = 1;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            product *= num;
            if (product > 2023) possible = false;
        }
        if (!possible) {
            cout << "NO\n";
            continue;
        }

        if (2023 % product) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        cout << (2023 / product);
        for (int i = 1; i < k; i++) cout << " 1";
        cout << endl;
    }

    return 0;
}
