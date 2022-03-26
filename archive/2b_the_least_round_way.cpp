#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> min_twos(n, 0);
    vector<int> min_fives(n, 0);
    vector<bool> two_zero(n, false);
    vector<bool> five_zero(n, false);
    vector<vector<char>> twos_path;
    vector<vector<char>> fives_path;

    for (int y = 0; y < n; ++y) {
        twos_path.push_back(vector<char>());
        fives_path.push_back(vector<char>());
        for (int x = 0; x < n; ++x) {
            int num; cin >> num;
            if (num == 0) {
                two_zero[x] = true;
                five_zero[x] = true;
                min_twos[x] = 1;
                min_fives[x] = 1;
                twos_path[y].push_back(y == 0 ? 'R' : 'D');
                fives_path[y].push_back(y == 0 ? 'R' : 'D');
                // cout << "(1, 1, 1, 1, " << twos_path[y][x] << ", " << fives_path[y][x] << ") ";
                continue;
            }
            int twos = 0; int fives = 0;
            int tmp = num;
            while (tmp % 2 == 0) {
                ++twos; tmp /= 2;
            }
            while (num % 5 == 0) {
                ++fives; num /= 5;
            }
            if (x == 0 || ((y != 0) && (min_twos[x] < min_twos[x - 1]))) {
                twos_path[y].push_back('D');
                min_twos[x] += twos;
            }
            else {
                twos_path[y].push_back('R');
                min_twos[x] = min_twos[x - 1] + twos;
            }
            if (x == 0 || ((y != 0) && (min_fives[x] < min_fives[x - 1]))) {
                fives_path[y].push_back('D');
                min_fives[x] += fives;
            }
            else {
                fives_path[y].push_back('R');
                min_fives[x] = min_fives[x - 1] + fives;
            }

            if (two_zero[x] && (min_twos[x] != 0)) {
                twos_path[y][x] = 'D';
                min_twos[x] = 1;
            }
            if (x != 0 && two_zero[x - 1] && (min_twos[x] != 0)) {
                twos_path[y][x] = 'R';
                min_twos[x] = 1;
                two_zero[x] = true;
            }

            if (five_zero[x] && (min_fives[x] != 0)) {
                fives_path[y][x] = 'D';
                min_fives[x] = 1;
            }
            if (x != 0 && five_zero[x - 1] && (min_fives[x] != 0)) {
                fives_path[y][x] = 'R';
                min_fives[x] = 1;
                five_zero[x] = true;
            }

            // cout << "(" << min_twos[x] << ", " << min_fives[x] << ", " << two_zero[x] << ", " << five_zero[x] << ", " << twos_path[y][x] << ", " << fives_path[y][x] <<  ") ";
        }
        // cout << endl;
    } 

    int min_zeroes;
    vector<vector<char>> path_parts;
    vector<char> path;

    if (min_twos[n - 1] < min_fives[n - 1]) {
        min_zeroes = min_twos[n - 1];
        path_parts = move(twos_path);
    }
    else {
        min_zeroes = min_fives[n - 1];
        path_parts = move(fives_path);
    }

    int x = n - 1; int y = n - 1;
    while (x > 0 || y > 0) {
        path.push_back(path_parts[y][x]);
        if (path_parts[y][x] == 'D') --y;
        else --x;
    }

    cout << min_zeroes << endl;
    for (auto it = path.rbegin(); it != path.rend(); ++it) cout << *it;
    cout << endl;

    return 0;
}
