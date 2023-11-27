#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t; cin >> t;

    vector<int> nums(200000, 0);

    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> nums[i];

        int64_t ops = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                int k = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
                ops += (k - 1);
                nums[i] /= k;
            }
        }
        cout << ops << endl;
    }

    return 0;
}
