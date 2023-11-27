#include <iostream>
#include <vector>

using namespace std;

int digit_sum(int n, int times) {
    if (times >= 3) {
        n = n % 9;
        return n == 0 ? 9 : n;
    }
    for (int i = 0; i < times; ++i) {
        int tmp = n;
        n = 0;
        while (tmp > 0) {
            n += tmp % 10;
            tmp /= 10;
        }
    }
    return n;
}

void _update_tree(int l, int r, int tn, int tl, int tr, vector<int>& tree) {
    if (l > r) return;
    if ((l == tl) && (r == tr)) {
        tree[tn]++;
        return;
    }
    int tm = (tl + tr) / 2;
    _update_tree(l, min(r, tm), 2*tn + 1, tl, tm, tree);
    _update_tree(max(l, tm + 1), r, 2*tn + 2, tm + 1, tr, tree);
}

void update_tree(int l, int r, int n, vector<int>& tree) {
    _update_tree(l, r, 0, 0, n - 1, tree);
}

int _read_tree(int n, int tn, int tl, int tr, vector<int>& tree) {
    if ((n == tl) && (n == tr)) return tree[tn];
    int tm = (tl + tr) / 2;
    if (n <= tm) {
        return tree[tn] + _read_tree(n, 2*tn + 1, tl, tm, tree);
    }
    return tree[tn] + _read_tree(n, 2*tn + 2, tm + 1, tr, tree);
}

int read_tree(int index, int n, vector<int>& tree) {
    return _read_tree(index, 0, 0, n - 1, tree);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector<int> tree(4*n, 0);
        for (int i = 0; i < q; ++i) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r;
                update_tree(l - 1, r - 1, n, tree);
            }
            else {
                int x; cin >> x;
                cout << digit_sum(a[x - 1], read_tree(x - 1, n, tree)) << endl;
            }
        }
    }
    return 0;
}
