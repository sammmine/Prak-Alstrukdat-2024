#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

const int MOD = 1e9 + 7;

int main() {
    int rowcol, i, j, k, l, count=0;
    Matrix m;

    scanf("%d", &rowcol);

    if(rowcol>1 && rowcol<=ROW_CAP) {
        readMatrix(&m, rowcol, rowcol);

        for(i=0; i<rowcol; i++){
            for(j=0; j<rowcol; j++){
                if(ELMT(m, i, j) != 0){
                    for(k=0; k<rowcol; k++){
                        if(ELMT(m, i, k)!=0 && k!=j){
                            count+=ELMT(m, i, k);
                            count = count%MOD;
                        }
                    }
                    for(l=0; l<rowcol;l++){
                        if(ELMT(m, l, j)!=0 && l!=i){
                            count+=ELMT(m, l, j);
                            count = count%MOD;
                        }
                    }
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}