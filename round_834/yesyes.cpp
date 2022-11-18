#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string heard; cin >> heard;
        bool answer = true;
        char expected = heard[0];
        if (!((expected == 'Y') || (expected == 'e') || (expected == 's'))) {
            cout << "No" << endl;
            continue;
        }
        for (auto it = heard.begin(); it != heard.end(); ++it) {
            if (*it != expected) {
                answer = false;
                break;
            } 
            switch (expected) {
                case 'Y': expected = 'e'; break;
                case 'e': expected = 's'; break;
                case 's': expected = 'Y'; break;
            }
        }
        cout << (answer ? "Yes" : "No") << endl;
    }

    return 0;
}
