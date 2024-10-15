#include <stdio.h>
#include "matrix.c"

// KOK SALAH YA

const int MOD = 1e9 + 7;

int main() {
    int n, i, j, k, l, count=0;
    Matrix m;

    // n adalah row dan kolom (matriks persegi)
    scanf("%d", &n);
    readMatrix(&m, n, n); 

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(ELMT(m, i, j)!=0){
                for(k=0; k<n; k++){
                    // cek horizontal, i dibuat tetap
                    if(ELMT(m, i, k)!=0 && i!=k){
                        count+=ELMT(m, i, k);
                        count=count%MOD;
                    }
                }
                for(l=0; l<n; l++){
                    // cek vertikal, j dibuat tetap
                    if(ELMT(m, l, j)!=0 && l!=j){
                        count+=ELMT(m, l, j);
                        count=count%MOD;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}