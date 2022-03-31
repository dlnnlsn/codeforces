#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << (a == 0 ? 1 : 2 * b + a + 1) << endl;
    }
    return 0;
}
