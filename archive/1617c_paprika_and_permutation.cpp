#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int min_operations(const vector<int>& numbers) {
    vector<bool> used(numbers.size() + 1, false);
    vector<int> toUse;
    for (int num : numbers) {
        if (num <= numbers.size()) {
            if (used[num]) toUse.push_back(num);
            else used[num] = true;
        }
        else toUse.push_back(num);
    }
    sort(toUse.begin(), toUse.end());
    int operations = 0;
    for (int i = 1; i <= numbers.size(); ++i) {
        if (used[i]) continue;
        if (toUse[operations] <= 2 * i) return -1;
        ++operations;
    }
    return operations;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> numbers; numbers.reserve(n);
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            numbers.push_back(num);
        }
        cout << min_operations(numbers) << endl;
    }
    return 0;
}
