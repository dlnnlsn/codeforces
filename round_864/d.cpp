#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m; 
    vector<int> imp(n, 0);
    for (int i = 0; i < n; ++i) cin >> imp[i];
    vector<int> parent(n, -1);
    vector<int64_t> total_imp(n, 0);
    vector<int> size(n, 0);
    vector<priority_queue<pair<int, int>>> children(n, priority_queue<pair<int, int>>());
    vector<vector<int>> neighbours(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int s, t; cin >> s >> t;
        s--; t--;
        neighbours[s].push_back(t);
        neighbours[t].push_back(s);
    }
    stack<int> to_visit;
    vector<bool> visited(n, false);
    to_visit.push(0);
    stack<int> nodes;
    while (!to_visit.empty()) {
        int s = to_visit.top();
        to_visit.pop();
        nodes.push(s);
        visited[s] = true;
        for (const int t : neighbours[s]) {
            if (visited[t]) continue;
            parent[t] = s;
            to_visit.push(t);
        }
    }
    while (!nodes.empty()) {
        int child = nodes.top();
        nodes.pop();
        size[child]++;
        total_imp[child] += imp[child];
        if (child == 0) continue;
        size[parent[child]] += size[child];
        total_imp[parent[child]] += total_imp[child];
        children[parent[child]].push(make_pair(size[child], -child));
    }

    while (m--) {
        int type, x; cin >> type >> x;
        x--;
        if (type == 1) {
            cout << total_imp[x] << endl;
            continue;
        }
        int heavy = -1;
        while ((heavy == -1) && (!children[x].empty())) {
            auto [heavy_size, tmp] = children[x].top();
            children[x].pop();
            tmp = -tmp;
            if (parent[tmp] == x) heavy = tmp; 
        }
        if (heavy == -1) continue;
        size[x] -= size[heavy];
        size[heavy] += size[x];
        total_imp[x] -= total_imp[heavy];
        total_imp[heavy] += total_imp[x];
        children[parent[x]].push(make_pair(size[heavy], -heavy));
        children[heavy].push(make_pair(size[x], -x));
        parent[heavy] = parent[x];
        parent[x] = heavy;
    }
    return 0;
}
