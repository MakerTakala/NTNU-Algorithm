#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for(long long i = 0, a = 0, b = 0; i < t; i++) {
        scanf("%ld %ld", &a, &b);
        printf("%ld\n", a + b);
    }

    return 0;
}