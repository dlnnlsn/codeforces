#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void build_tree(vector<int>& tree, const vector<int>& values, int node, int left, int right, function<int(int, int)> op) {
    if (left == right) {
        tree[node] = values[left];
        return;
    }
    int mid = (left + right) / 2;
    build_tree(tree, values, node * 2, left, mid, op);
    build_tree(tree, values, node * 2 + 1, mid + 1, right, op);
    tree[node] = op(tree[2 * node], tree[2 * node + 1]); 
}

vector<int> build_tree(const vector<int>& values, function<int(int, int)> op) {
    vector<int> tree(4 * values.size() + 1, 0);
    build_tree(tree, values, 1, 0, values.size() - 1, op);
    return tree; 
}

int query(const vector<int>& tree, int node, int tree_left, int tree_right, int left, int right, function<int(int, int)> op) {
    if ((left == tree_left) && (right == tree_right)) return tree[node];
    int tree_mid = (tree_left + tree_right) / 2;
    if (left > tree_mid) return query(tree, 2 * node + 1, tree_mid + 1, tree_right, left, right, op);
    if (tree_mid + 1 > right) return query(tree, 2 * node, tree_left, tree_mid, left, right, op);
    return op(query(tree, 2 * node, tree_left, tree_mid, left, tree_mid, op),
              query(tree, 2 * node + 1, tree_mid + 1, tree_right, tree_mid + 1, right, op));
}

int query(const vector<int>& tree, int nums, int left, int right, function<int(int, int)> op) {
    return query(tree, 1, 0, nums - 1, left, right, op);
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
    vector<int> nums; nums.reserve(n);
    for (int i = 0; i < n; ++i) {
        int num; cin >> num; nums.push_back(num);
    }

    vector<int> gcd_tree = build_tree(nums, gcd);
    vector<int> min_tree = build_tree(nums, my_min);

    int lo = 0; int hi = n;
    while ((hi - lo) > 1) {
        int mid = (hi + lo) / 2;
        bool works = false;
        for (int i = 0; i + mid < n; ++i) {
            if (query(gcd_tree, n, i, i + mid, gcd) == query(min_tree, n, i, i + mid, my_min)) {
                works = true;
                break;
            }
        }
        if (works) lo = mid;
        else hi = mid;
    }

    vector<int> pairs;
    for (int i = 0; i + lo < n; ++i) {
        if (query(gcd_tree, n, i, i + lo, gcd) == query(min_tree, n, i, i + lo, my_min)) pairs.push_back(i + 1);
    }

    cout << pairs.size() << " " << lo << endl;
    cout << pairs[0];
    for (auto it = pairs.begin() + 1; it != pairs.end(); ++it) cout << " " << *it;
    cout << endl;

    return 0;
}
