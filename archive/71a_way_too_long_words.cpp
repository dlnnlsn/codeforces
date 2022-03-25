#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string word; cin >> word;
	if (word.size() > 10) {
            cout << *word.begin() << (word.size() - 2) << *(word.end() - 1) << endl;
	}
	else {
	    cout << word << endl;
	}
    }
    return 0;
}
