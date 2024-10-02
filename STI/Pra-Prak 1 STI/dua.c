#include <stdio.h>

int main() {
    int N, i;

    scanf("%d", &N);

    for (i=1 ; i<=N ; i++) {
        if (i%2==0 && i%7==0) {
            printf("RonaldoMessi\n");
        } else {
            if (i%2==0 || i%5==0 || (i%2==0 && i%5==0)) {
                printf("Messi\n");
            } else if (i%7 == 0) {
                printf("Ronaldo\n");
            } else {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}