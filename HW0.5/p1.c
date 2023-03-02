#include <stdio.h>
unsigned int t, a, b;
int main() {
    scanf("%u", &t);
    
    while(t--) {
        scanf("%u %u", &a, &b);
        printf("%u\n", a + b);
    }
    return 0;
}