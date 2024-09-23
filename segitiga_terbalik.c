// NOMOR DUA

#include <stdio.h>

int main() {
    int n, i;
    int spasi, star;
    scanf("%d", &n);

    for (i = n; i >= 1; i--) {
        
        // buat spasi
        for (spasi = n-i; spasi >= 1; spasi--) {
            printf(" ");
        }
        
        // buat star
        for (star = 2*i - 1; star >= 1; star--) {
            printf("*");
        }
        
        printf("\n");

    }

    return 0;
}