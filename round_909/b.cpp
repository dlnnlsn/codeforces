#include <iostream>
#include <vector>

using namespace std;

int64_t max_difference(const vector<int64_t>& boxes, int n, int k) {
    int64_t smallest_truck = boxes[k - 1];
    int64_t largest_truck = boxes[k - 1];
    for (int i = 2 * k - 1; i < n; i += k) {
        int64_t truck = boxes[i] - boxes[i - k];
        smallest_truck = min(smallest_truck, truck);
        largest_truck = max(largest_truck, truck);
    }
    return largest_truck - smallest_truck;
}

int main() {

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int64_t> boxes(n, 0);
        cin >> boxes[0];
        for (int i = 1; i < n; i++) {
            cin >> boxes[i];
            boxes[i] += boxes[i - 1];
        }

        int64_t largest_difference = 0;
        for (int k = 1; k * k <= n; k += 1) {
            if (n % k) continue;
            largest_difference = max(largest_difference, max_difference(boxes, n, k));
            largest_difference = max(largest_difference, max_difference(boxes, n, n / k));
        }
        cout << largest_difference << endl;
    }

    return 0;
}
