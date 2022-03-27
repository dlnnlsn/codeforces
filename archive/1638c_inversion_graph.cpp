#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p; p.reserve(n);
        for (int i = 0; i < n; ++i) {
            int num; cin >> num; p.push_back(num);
        }

        vector<int> components(n, 0);
        components[0] = p[0];
        int num_components = 1;
        for (int i = 1; i < n; ++i) {
            if (p[i] > components[num_components - 1]) {
                components[num_components] = p[i];
                ++num_components;
                continue;
            }
            int component = components[num_components - 1];
            while ((num_components > 0) && (p[i] < components[num_components - 1])) {
                --num_components;
            }
            components[num_components] = component;
            ++num_components;
        }

        cout << num_components << endl;
    }

    return 0;
}
