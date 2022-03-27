#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int64_t total = 0;
    int64_t diff = 0;
    int mul = 1;

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        total += num;
        if (num % 2) diff += mul;
        mul = -mul;
    } 

    cout << (total - abs(diff)) / 2 << endl;
    return 0;
}
