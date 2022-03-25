#include <iostream>

using namespace std;

int main() {
    int solved_problems = 0;
    int n; cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a + b + c) >= 2) ++solved_problems;
    }
    cout << solved_problems << endl;

    return 0;
}
