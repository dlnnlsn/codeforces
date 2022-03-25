#include <iostream>

using namespace std;

int main() {
    string name; cin >> name;
    bool seen[26]; for (int i = 0; i < 26; ++i) seen[i] = false;
    int distinct = 0;
    for (char c : name) {
        if (!seen[c - 'a']) ++distinct;
        seen[c - 'a'] = true;
    }
    if (distinct % 2) {
        cout << "IGNORE HIM!" << endl;
    }
    else {
        cout << "CHAT WITH HER!" << endl;
    }

    return 0;
}
