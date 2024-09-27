#include <stdio.h>
#include <math.h>

int main() {
    int n;
    int store;
    int sum = 0;

    scanf("%d", &n);

    while (n > 0) {
        store = n%10;
        if (store%2 == 0) {
            sum += store;
        } 
        n = floor(n/10);
    }

    printf("%d", sum);

    return 0;
}