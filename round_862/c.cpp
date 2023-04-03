#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> ks(n, 0);
        for (int i = 0; i < n; ++i) cin >> ks[i];
        sort(ks.begin(), ks.end());
        while (m--) {
            int64_t a, b, c; cin >> a >> b >> c;
            if (c <= 0) {
                cout << "NO" << endl;
                continue;
            }
            int64_t s = a * c; s *= 4;
            double sq = sqrt((double)s);
            double min_k = b - sq;
            double max_k = b + sq;
            auto it = upper_bound(ks.begin(), ks.end(), min_k);
            if (it == ks.end()) {
                cout << "NO" << endl;
                continue;
            }
            if (*it >= max_k) cout << "NO" << endl;
            else {
                cout << "YES" << endl;
                cout << (*it) << endl;
            }
        }
        if (t) cout << endl;
    }
    return 0;
}
