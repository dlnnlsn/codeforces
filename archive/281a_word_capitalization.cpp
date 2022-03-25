#include <cstdio>

using namespace std;

int main() {
    unsigned char word[1001];
    scanf("%s", word);
    word[0] &= 0b11011111;
    printf("%s\n", word);
    return 0;
}
