#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        char min_char = s[0];
        int min_index = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] < min_char) {
                min_char = s[i];
                min_index = i;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] == min_char) {
                for (int i = j - 1; i >= 0; i--) {
                    s[i + 1] = s[i];
                }
                s[0] = min_char;
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}
