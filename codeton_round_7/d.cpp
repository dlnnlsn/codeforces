#include <iostream>
#include <vector>
#include <set>

using namespace std;

#ifdef DEBUG
    template<typename T>
    void print_vec(const vector<T>& vec) {
        for (const T val : vec) cout << " " << val;
        cout << endl;
    }
    
    template<typename T>
    void print(const T val) {
        cout << val;
    }
#else
    template<typename T>
    void print_vec(const vector<T>& vec) {
        return;
    }
    
    template<typename T>
    void print(const T val) {
        return;
    }
#endif


int closest_prefix(const vector<int>& tree, const vector<bool>& has_odd, int val, int root, bool even) {
    if (!even && !has_odd[root]) return -1;

    if ((2 * root) >= tree.size()) {
        if (((tree[root] % 2) == 0) == even) {
            if (tree[root] <= val) return tree[root];
        }
        if (even) return 0;
        return -1;
    }

    if (tree[root] <= val) {
        if (((tree[root] % 2) == 0) == even) return tree[root];
        return closest_prefix(tree, has_odd, val, 2 * root + 1, even);
    }

    if ((2 * root + 1) < tree.size()) {
        if (tree[2 * root + 1] > val) {
            return closest_prefix(tree, has_odd, val, 2 * root + 1, even);
        }
        val -= tree[2 * root + 1];
        const int left = closest_prefix(tree, has_odd, val, 2 * root, (even + tree[2 * root + 1]) % 2); 
        if (left != -1) return tree[2 * root + 1] + left;
        return closest_prefix(tree, has_odd, val + tree[2 * root + 1], 2 * root + 1, even);
    }
    return closest_prefix(tree, has_odd, val, 2 * root, even);
}

void process_case() {
    int n, q; cin >> n >> q;
    set<int> ones;
    int total = 0;
    vector<int> nums(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (nums[i] == 1) ones.insert(i);
        total += nums[i];
    }

    int leaves_start = 2 * n;
    int tmp = n;
    while (tmp) {
        leaves_start &= (~tmp);
        tmp /= 2;
    }

    vector<int> tree(2 * leaves_start, 0);
    vector<bool> has_odd(2 * leaves_start, false);

    for (int i = leaves_start; i < leaves_start + n; i++) {
        tree[i] = nums[i - leaves_start + 1];
        if (tree[i] % 2) has_odd[i] = true;
    }
    for (int i = leaves_start - 1; i > 0; i--) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
        has_odd[i] = ((tree[i] % 2) == 1) | (has_odd[2 * i] && ((tree[2 * i + 1] % 2) == 0)) | has_odd[2 * i + 1];
    }

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            print_vec(nums);
            print_vec(tree);
            print_vec(has_odd);
            int s; cin >> s;

            if (s > total) {
                print("Target is larger than sum of all available numbers\n");
                cout << "NO" << endl;
                continue;
            }

            if (ones.size() == 0) {
                if (s % 2) {
                    print("No ones and the total is odd\n");
                    cout << "NO" << endl;
                    continue;
                }
                print("No ones and the total is even\n");
                cout << ((s <= total) ? "YES" : "NO") << endl;
                continue;
            }

            int first_one = *ones.begin();
            print("First one is at "); print(first_one); print("\n");

            if (s <= (2 * first_one - 1)) {
                print("Can be made with initial run of 2s and possibly the 1\n");
                cout << "YES" << endl;
                continue;
            }
            if (s <= (total - 2 * first_one + 2)) {
                print("Can be made with a subarray starting at the one\n");
                cout << "YES" << endl;
                continue;
            }

            int left = total - s;
            print("Must remove a prefix and suffix totalling "); print(left); print("\n");

            const int closest = closest_prefix(tree, has_odd, left, 1, (left % 2) == 0);
            if (closest == -1) {
                print("No suffix with the correct parity\n");
                cout << "NO" << endl;
                continue;
            }

            print("Closest suffix is "); print(closest); print(" leaving "); print(left - closest); print(" to make using "); print(first_one - 1); print(" 2s\n");
            if ((left - closest) <= 2 * (first_one - 1)) {
                print("There are enough 2s\n");
                cout << "YES" << endl;
                continue;
            }
            print("There are not enough 2s\n");
            cout << "NO" << endl;
        }
        else {
            int i, v; cin >> i >> v;
            if (nums[i] == v) continue;
            if (v == 1) {
                ones.insert(i); total -= 1;
            }
            else {
                ones.erase(i); total += 1;
            }
            nums[i] = v;
            i = i + leaves_start - 1;
            has_odd[i] = (v % 2) == 1;
            tree[i] = v;
            i /= 2;
            while (i) {
                tree[i] = tree[2 * i] + tree[2 * i + 1];
                has_odd[i] = ((tree[i] % 2) == 1) | (has_odd[2 * i] && ((tree[2 * i + 1] % 2) == 0)) | has_odd[2 * i + 1];
                i /= 2;
            }
            print_vec(nums);
            print_vec(tree);
            print_vec(has_odd);
        }
    }
}

int main() {
    
    int t; cin >> t;
    while (t--) {
        process_case();
    }

    return 0;
}
