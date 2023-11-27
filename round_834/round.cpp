#include <iostream>

using namespace std;

int main() {

    int T; cin >> T;
    while (T--) {
        long long int n, m; cin >> n >> m;
        long long int tmp = n;
        int exponent_of_two = 0;
        while ((tmp % 2) == 0) {
            exponent_of_two++;
            tmp /= 2;
        }

        int exponent_of_five = 0;
        while ((tmp % 5) == 0) {
            exponent_of_five++;
            tmp /= 5;
        }

        long long int k = 1;
        if (exponent_of_two > exponent_of_five) {
            for (int i = 0; i < exponent_of_two - exponent_of_five; ++i) {
                k *= 5;
                if (k > m) {
                    k /= 5;
                    break;
                }
            }
        }
        else if (exponent_of_two < exponent_of_five) {
            for (int i = 0; i < exponent_of_five - exponent_of_two; ++i) {
                k *= 2;
                if (k > m) {
                    k /= 2;
                    break;
                }
            }
        }

        while (k <= m) {
            k *= 10;
        }
        k /= 10;
        k = k * (m / k);
        cout << (k * n) << endl;
    }

    return 0;
}
