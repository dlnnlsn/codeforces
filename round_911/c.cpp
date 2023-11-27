#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#ifdef DEBUG
    void print() {
        cout << endl;
    }

    template <typename T, typename... Rest>
    void print(const T val, Rest... rest) {
        cout << " " << val;
        print(rest...);
    }

    template <typename T>
    void printvec(const vector<T>& vec) {
        for (const T val : vec) {
            cout << " " << val;
        }
        cout << endl;
    }
#else
    void print() {}

    template <typename T, typename... Rest>
    void print(const T val, Rest... rest) {}

    template <typename T>
    void printvec(const vector<T>& vec) {}
#endif

void process_case() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
        left[i]--; right[i]--;
    }
    printvec(left);
    printvec(right);

    vector<int> min_operations(n, 0);

    int answer = -1;

    stack<int> to_process;
    to_process.push(0);

    while (!to_process.empty()) {
        int node = to_process.top();
        to_process.pop();

        if (left[node] != -1) {
            min_operations[left[node]] = min_operations[node];
            if (s[node] != 'L') min_operations[left[node]]++;
            to_process.push(left[node]);
        }

        if (right[node] != -1) {
            min_operations[right[node]] = min_operations[node];
            if (s[node] != 'R') min_operations[right[node]]++;
            to_process.push(right[node]);
        }

        if ((left[node] == -1) && (right[node] == -1)) {
            if (answer == -1) answer = min_operations[node];
            else answer = min(answer, min_operations[node]);
        }
    }

    cout << answer << endl;
}

int main() {
    int t; cin >> t;
    while (t--) {
        process_case();
    }
    return 0;
}
