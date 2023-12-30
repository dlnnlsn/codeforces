#include <iostream>

using namespace std;

void process_case() {
    int n; cin >> n;
    string s; cin >> s;

    int first_a = n; int last_b = -1;
    for (int i = 0; i < n; i++) if (s[i] == 'B') last_b = i;
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'A') first_a = i;

    if (first_a == n) {
        cout << 0 << endl; return;
    }
    if (last_b == -1) {
        cout << 0 << endl; return;
    }

    if (first_a > last_b) {
        cout << 0 << endl; return;
    }

    cout << (last_b - first_a) << endl;
}

int main() {
    
    int t; cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}
