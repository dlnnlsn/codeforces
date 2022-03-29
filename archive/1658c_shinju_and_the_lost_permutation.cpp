#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int first; cin >> first;
        int prev = first;
        bool works = true;
        bool hasOne = (first == 1);
        for (int i = 1; i < n; ++i) {
            int num; cin >> num;
            if (num == 1) {
                if (hasOne) works = false;
                else hasOne = true;
            } 
            else {
                if (num > prev + 1) works = false;
            }
            prev = num;
        }
        if (first > prev + 1) works = false;
        if (works && hasOne) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
