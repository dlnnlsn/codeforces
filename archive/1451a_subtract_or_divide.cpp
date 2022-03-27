#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n <= 3) cout << n - 1;
        else if (n % 2) cout << 3;
        else cout << 2;
        cout << endl;
    }

    return 0;
}
