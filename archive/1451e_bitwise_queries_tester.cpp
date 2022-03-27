#include <cstdio>
#include <random>
#include <vector>

using namespace std;

int main() {
    random_device dev;
    mt19937 gen(dev());
    uniform_int_distribution<int> exp_dist(4, 16);

    int n = 1 << exp_dist(gen);
    fprintf(stderr, "n: %d\n", n);
    uniform_int_distribution<int> num_dist(0, n - 1);

    vector<int> nums;
    for (int i = 0; i < n; ++i) nums.push_back(num_dist(gen));

    printf("%d\n", n);
    fflush(stdout);
    int queries = 0;
    char op[10]; int i; int j;
    while (scanf("%s %d %d", &op, &i, &j) == 3) {
        if (op[0] == '!') break;
        ++queries;
        if (queries > (n + 1)) {
            fprintf(stderr, "QUERY LIMIT EXCEEDED\n");
            printf("-1\n");
            return 1;
        }
        int result = 0;
        if (op[0] == 'A') result = nums[i - 1] & nums[j - 1];
        else if (op[0] =='O') result = nums[i - 1] | nums[j - 1];
        else if (op[0] == 'X') result = nums[i - 1] ^ nums[j - 1];
        fprintf(stderr, "Query %d: %s %d %d -> %d\n", queries, op, i, j, result);
        printf("%d\n", result);
        fflush(stdout);
    }
    vector<int> attempt;
    int num;
    attempt.push_back(i); attempt.push_back(j);
    for (int i = 2; i < n; ++i) {
        scanf("%d", &num); attempt.push_back(num);
    }

    bool correct = true;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != attempt[i]) {
            correct = false;
            break;
        }
    }

    if (correct) {
        fprintf(stderr, "CORRECT ANSWER\n");
    }
    else {
        fprintf(stderr, "INCORRECT ANSWER!\n");
        fprintf(stderr, "GOT     :");
        for (auto num : attempt) fprintf(stderr, " %d", num);
        fprintf(stderr, "\nEXPECTED:");
        for (auto num : nums) fprintf(stderr, " %d", num);
        fprintf(stderr, "\n");
    }
}
