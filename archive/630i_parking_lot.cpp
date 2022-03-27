#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int64_t answer = (9 * n - 3);
    answer = answer * (1ll << (2 * n - 6));

    cout << answer << endl;

    return 0;
}
