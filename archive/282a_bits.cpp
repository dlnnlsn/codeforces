#include <iostream>

using namespace std;

int main() {
    int x = 0;
    int n; cin >> n;
    while (n--) {
        string instruction; cin >> instruction;
        if (instruction[1] == '+') ++x;
        else --x;
    }
    cout << x << endl;
}
