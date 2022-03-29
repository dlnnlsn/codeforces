#include <iostream>

using namespace std;

int main() {
    
    int t; cin >> t;
    while (t--) {
        int n, B, x, y; cin >> n >> B >> x >> y;
        int64_t total = 0;
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num += x;
            if (num > B) num = num - x - y;
            total += num;
        }
        cout << total << endl;
    }

    return 0;
}
