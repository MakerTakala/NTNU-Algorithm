#include <stdio.h>
int main() {
    long long t, a, b;
    scanf("%ld", &t);
    while(t--) {
        scanf("%ld %ld", &a, &b);
        printf("%ld\n", a + b);
    }
    return 0;
}