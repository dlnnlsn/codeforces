#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> summands; 
    int summand;
    while (scanf("%d+", &summand) == 1) summands.push_back(summand);
    sort(summands.begin(), summands.end()); 
    printf("%d", summands[0]);
    for (auto num = summands.begin() + 1; num != summands.end(); ++num) {
        printf("+%d", *num);
    }
    printf("\n");
    return 0;
}
