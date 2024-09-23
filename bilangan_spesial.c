// NOMOR EMPAT

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a >= 1 && a < b && a <= 1000 && b >= 1 && b <= 1000) {

        while (a<b) {
            printf("%d ", a);

            if (a%2!=0) {
                a = a + 1;
                printf("%d ", a);
            }

            a = a*2;
        }

        printf("\n");
        return 0;

    }
}