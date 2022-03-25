#include <cstdio>

using namespace std;

int main() {
    unsigned char first[101], second[101];
    scanf("%s", first);
    scanf("%s", second);

    int index = 0;
    while(first[index]) {
        first[index] &= 0b11011111;
        second[index] &= 0b11011111;
        if (first[index] < second[index]) {
            printf("-1\n");
            return 0;
        }
        else if (first[index] > second[index]) {
            printf("1\n");
            return 0;
        }
        ++index;
    }
    printf("0\n");
    return 0;
}
