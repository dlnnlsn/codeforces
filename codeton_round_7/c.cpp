#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process_case() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n, pair<int, int>(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> b(n, 0); for (int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool possible = true;
    for (int i = 0; i < n - x; i++) {
        if (a[i].first > b[x + i]) {
            possible = false;
            break;
        }
    }

    for (int i = n - x; i < n; i++) {
        if (a[i].first <= b[i + x - n]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    
    vector<int> result(n, 0);
    for (int i = 0; i < n - x; i++) {
        result[a[i].second] = b[x + i];
    }
    for (int i = n - x; i < n; i++) {
        result[a[i].second] = b[i + x - n];
    }
    cout << result[0];
    for (int i = 1; i < n; i++) {
        cout << " " << result[i];
    }
    cout << endl;
}

int main() {
    
    int t; cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}
