#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int o1 = 4, o2 = 4;
        if ((x1 == 1) || (x1 == n)) o1 = 3;
        if ((y1 == 1) || (y1 == m)) o1 -= 1;
        if ((x2 == 1) || (x2 == n)) o2 = 3;
        if ((y2 == 1) || (y2 == m)) o2 -= 1;
        cout << min(o1, o2) << endl;
    }
    return 0;
}
