// NOMOR TIGA

#include <stdio.h>

int main() {
    int n, a, b, i, sum;

    scanf("%d %d %d", &n, &a, &b);

    for (i = 1; i <= n-2; i++) { // dikurang 2 karena a dan b
        sum = a + b;
        a = b;
        b = sum;
    }

    printf("%d\n", sum);
    return 0;
}

