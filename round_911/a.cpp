#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef DEBUG
    void print() {
        cout << endl;
    }

    template <typename T, typename... Rest>
    void print(const T val, Rest... rest) {
        cout << " " << val;
        print(rest...);
    }

    template <typename T>
    void printvec(const vector<T>& vec) {
        for (const T val : vec) {
            cout << " " << val;
        }
        cout << endl;
    }
#else
    void print() {}

    template <typename T, typename... Rest>
    void print(const T val, Rest... rest) {}

    template <typename T>
    void printvec(const vector<T>& vec) {}
#endif

void process_case() {
    int n; cin >> n;
    string s; cin >> s;

    int previous_block = -1;
    int num_blocks[4] = {};

    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            num_blocks[min(3, i - previous_block - 1)]++;
            previous_block = i;
        }
    }
    num_blocks[min(3, n - previous_block - 1)]++;

    if (num_blocks[3] > 0) {
        cout << 2 << endl;
        return;
    }

    int total = num_blocks[1] + 2 * num_blocks[2];
    cout << total << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        process_case();
    }
    return 0;
}
