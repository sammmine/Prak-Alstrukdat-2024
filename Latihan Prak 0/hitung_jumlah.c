// NOMOR LIMA

#include <stdio.h>

int main() {
    int n, k, a_i;
    int i = 1;
    int sum = 0;
    scanf("%d %d", &n, &k);

    while (i <= n) {
    scanf("%d", &a_i);
        
    if (a_i>=1 && a_i<=10000) {
        
        if (a_i%k != 0) {
            sum = sum + a_i;
        }
    
        i++;
        }
    }

    printf("%d\n", sum);

    
    return 0;
}