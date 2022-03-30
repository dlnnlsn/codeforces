#include <iostream>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int min_index = -1, min_value = 1e9 + 1;
        int max_index = -1, max_value = 0;

        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            if (num < min_value) {
                min_value = num; min_index = i + 1;
            }
            if (num > max_value) {
                max_value = num; max_index = i + 1;
            }
        }
        cout << min_index << " " << max_index << endl;
    }

    return 0;
}
