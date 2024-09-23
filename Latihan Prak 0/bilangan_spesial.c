// NOMOR EMPAT

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", a);

    while (a<b) {

        if (a%2!=0) {
            a = a + 1;
            printf(" %d", a);
        }

        a = a*2;

        if (a<=b) {
            printf(" %d", a);
        }
        
    }

    printf("\n");
    return 0;
}