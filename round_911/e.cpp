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

}

int main() {
    int t; cin >> t;
    while (t--) {
        process_case();
    }
    return 0;
}
