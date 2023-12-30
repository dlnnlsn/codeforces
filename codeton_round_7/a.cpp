#include <iostream>

using namespace std;

void process_case() {
    int n; cin >> n;
    bool possible = true;
    int first; cin >> first;
    for (int i = 1; i < n; i++) {
        int num; cin >> num;
        if (num < first) possible = false;
    }
    cout << (possible ? "YES" : "NO") << endl;
}

int main() {
    
    int t; cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}
