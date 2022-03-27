#include <iostream>
#include <vector>

using namespace std;

vector<int> logs;

void initialize_logs(int n) {
    logs.push_back(-1);
    int next_power_of_two = 1;
    int log = -1;
    for (int i = 1; i <= n; ++i) {
        if (i == next_power_of_two) {
            next_power_of_two *= 2;
            ++log;
        }
        logs.push_back(log);
    }
}

vector<vector<int>> build_table(const vector<int>& nums, int (*op)(int, int)) {
    vector<vector<int>> table;
    table.push_back(vector<int>(nums));
    for (int power_of_two = 1; power_of_two < nums.size(); power_of_two *= 2) {
        vector<int> row = vector<int>(table.back());
        for (int i = 0; i < nums.size() - power_of_two; ++i) {
            row[i] = op(row[i], row[i + power_of_two]);
        }
        table.push_back(row);
    }
    return table;
}

int query(const vector<vector<int>>& table, int left, int right, int (*op)(int, int)) {
    const int row = logs[right - left + 1];
    return op(table[row][left], table[row][right - (1 << row) + 1]);
}

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int my_min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n; cin >> n;
    initialize_logs(n);

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num; cin >> num; nums.push_back(num);
    }

    vector<vector<int>> gcd_table = build_table(nums, gcd);
    vector<vector<int>> min_table = build_table(nums, my_min); 

    int lo = 0; int hi = n;
    while ((hi - lo) > 1) {
        int mid = (hi + lo) / 2;
        bool works = false;
        for (int i = 0; i < n - mid; ++i) {
            if (query(gcd_table, i, i + mid, gcd) == query(min_table, i, i + mid, my_min)) {
                works = true;
                break;
            }
        }
        if (works) lo = mid;
        else hi = mid;
    }

    vector<int> pairs;
    for (int i = 0; i < n - lo; ++i) {
        if (query(gcd_table, i, i + lo, gcd) == query(min_table, i, i + lo, my_min)) pairs.push_back(i + 1);
    }

    cout << pairs.size() << " " << lo << endl;
    cout << pairs[0];
    for (auto it = pairs.begin() + 1; it != pairs.end(); ++it) cout << " " << *it;
    cout << endl;

    return 0;
}
