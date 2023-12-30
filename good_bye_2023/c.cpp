#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        int64_t sum = a[0];
        int num_odd = a[0] % 2;
        cout << a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] % 2) ++num_odd;
            sum += a[i];

            int64_t answer = sum;
            answer -= num_odd / 3;
            if (num_odd % 3 == 1) --answer;
            cout << " " << answer;
        }
        cout << endl;
    }

    return 0;
}
