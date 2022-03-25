#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string stones; cin >> stones;
    char prev = 0;
    int toremove = 0;
    for (char curr : stones) {
        if (curr == prev) ++toremove;
        prev = curr;
    } 
    cout << toremove << endl;
}
