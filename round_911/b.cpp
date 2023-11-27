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

bool can_produce(int a, int b, int c) {
    if ((a == 0) && ((b == 0) || (c == 0))) {
        return false;
    }
    if ((b % 2) != (c % 2)) {
        return false;
    }
    return true;
}

void process_case() {
    int a, b, c; cin >> a >> b >> c;
    cout << can_produce(a, b, c) << " " << can_produce(b, a, c) << " " << can_produce(c, a, b) << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        process_case();
    }
    return 0;
}
