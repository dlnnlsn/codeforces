#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> scores;
    while (n--) {
        int score; cin >> score; scores.push_back(score);
    }
    sort(scores.begin(), scores.end());
    auto tied_with_k = lower_bound(scores.begin(), scores.end(), *(scores.end() - k));
    auto first_positive = upper_bound(scores.begin(), scores.end(), 0);
    cout << min(scores.end() - tied_with_k, scores.end() - first_positive) << endl;
    return 0;
}
