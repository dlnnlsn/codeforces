#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n; scanf("%d", &n);

    vector<int> xors; xors.push_back(0);
    for (int i = 0; i < n - 1; ++i) {
        printf("XOR %d %d\n", i + 1, i + 2);
        fflush(stdout);
        int num; scanf("%d", &num); xors.push_back(num);
    }

    int prefix = 0;
    vector<int> prefixes; prefixes.reserve(n);
    // fprintf(stderr, "PREFIXES:");
    for (auto num : xors) {
        prefix ^= num;
        prefixes.push_back(prefix);
        // fprintf(stderr, " %d", prefix);
    }
    // fprintf(stderr, "\n");
    
    int comp_a = -1; int comp_b = -1;
    int same_a = -1; int same_b = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int ixorj = prefixes[i] ^ prefixes[j];
            if (ixorj == 0) {
                same_a = i; same_b = j;
                goto found;
            }
            else if (ixorj == (n - 1)) {
                comp_a = i; comp_b = j;
                goto found;
            }
        }
    }
found:
    int index; int value;
    if (comp_a != -1) {
        index = 0;
        if (index == comp_a) ++index;
        if (index == comp_b) ++index;
        printf("AND %d %d\n", comp_a + 1, index + 1);
        fflush(stdout);
        scanf("%d", &value);
        int num;
        printf("AND %d %d\n", comp_b + 1, index + 1);
        fflush(stdout);
        scanf("%d", &num);
        value |= num;
    }
    else {
        printf("AND %d %d\n", same_a + 1, same_b + 1);
        fflush(stdout);
        index = same_a;
        scanf("%d", &value);
    }

    value ^= prefixes[index];
    printf("!");
    for (int num : prefixes) printf(" %d", num ^ value);
    printf("\n");
    fflush(stdout);

    return 0;
}
