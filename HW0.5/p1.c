#include <stdio.h>
int main() {
    unsigned short t;
    unsigned int a, b;
    scanf("%hu", &t);
    while(t--) {
        scanf("%u %u", &a, &b);
        printf("%u\n", a + b);
    }
    return 0;
}