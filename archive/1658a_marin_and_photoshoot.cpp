#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string people; cin >> people;
        int to_add = 0;
        int last_male = -3;
        for (int i = 0; i < n; ++i) {
            if (people[i] == '0') {
                if (i - last_male < 3) to_add += (3 - i + last_male);
                last_male = i;
            }
        }
        cout << to_add << endl;
    }

    return 0;
}
