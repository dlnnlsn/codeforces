#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            int exp; cin >> exp;
            counts[exp]++;
        }

        int64_t total_pairs = 0;

        for (const auto& [exp, count] : counts) {
            int64_t pairs = count;
            pairs *= (count - 1);
            total_pairs += pairs / 2;
        }

        if (counts.count(1) && counts.count(2)) {
            int64_t pairs = counts[1];
            pairs *= counts[2];
            total_pairs += pairs;
        }

        cout << total_pairs << endl;
    }

    return 0;
}
