#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        auto min_elmt = min_element(nums.begin(), nums.end());
        bool sorted = true;
        for (auto num_ptr = min_elmt + 1; num_ptr != nums.end(); num_ptr++) {
            if (*num_ptr < *(num_ptr - 1)) sorted = false;
        }

        if (sorted) {
            cout << (min_elmt - nums.begin()) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }

    return 0;
}
