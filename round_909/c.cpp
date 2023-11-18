#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        int answer = nums[0];
        int min_sum = min(0, nums[0]);
        int sum = nums[0];
        for (int i = 1; i < n; ++i) {
            answer = max(answer, nums[i]);
            if (abs(nums[i] % 2) == abs(nums[i - 1] % 2)) {
                min_sum = min(0, nums[i]);
                sum = nums[i];
                continue;
            }
            sum += nums[i];
            answer = max(answer, sum - min_sum);
            min_sum = min(min_sum, sum);
        }

        cout << answer << endl;

    }
    return 0;
}
