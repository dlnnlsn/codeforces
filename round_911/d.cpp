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

const int max_num = 100000;

vector<int> phi(max_num + 1, 0);

void process_case() {
    int n; cin >> n;
    vector<int64_t> count(max_num + 1, 0);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        count[num]++;
    }

    vector<int64_t> suffix(max_num + 1, 0);
    for (int i = max_num - 1; i >= 0; i--) {
        suffix[i] = count[i + 1] + suffix[i + 1];
    }

    int64_t answer = 0;

    for (int d = 1; d <= max_num; d++) {
        int64_t total_smaller = 0;
        for (int m = d; m <= max_num; m += d) {
            int64_t pairs = 0;
            pairs = total_smaller * count[m] * suffix[m];
            pairs += total_smaller * (count[m] * (count[m] - 1)) / 2;
            pairs += (count[m] * (count[m] - 1)) / 2 * suffix[m];
            pairs += (count[m] * (count[m] - 1) * (count[m] - 2)) / 6;
            total_smaller += count[m];
            answer += pairs * phi[d];
        }
    }

    cout << answer << endl;
}

int main() {

    for (int i = 0; i <= max_num; i++) {
        phi[i] = i;
    }

    for (int p = 2; p <= max_num; p++) {
        if (phi[p] != p) continue;
        for (int m = p; m <= max_num; m += p) {
            phi[m] = phi[m] / p * (p - 1);
        }
    }

    int t; cin >> t;
    while (t--) {
        process_case();
    }
    return 0;
}
