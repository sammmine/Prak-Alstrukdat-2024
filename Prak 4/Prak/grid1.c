#include <stdio.h>
#include "matrix.h"

const int MOD = 1e9 + 7;

int main() {
    int rowcol;
    int i=0, j=0;
    boolean found=false, found2=false;
    Matrix m, m2;

    scanf("%d", &rowcol);

    if(rowcol>0 && rowcol<=ROW_CAP) {
        readMatrix(&m, rowcol, rowcol);
        createMatrix(rowcol, rowcol, &m2);
        if(ELMT(m, 0, 0) == 0 && ELMT(m, rowcol, rowcol) == 0) {

            ELMT(m2, 0, 0) = 1;

            for (i = 0; i < rowcol; i++) {
                for (j = 0; j < rowcol; j++) {

                    // ide --> jika elemen m[i][j] adalah 0, maka tambahkan elemen m2[i][j] dengan elemen m2[i-1][j] dan m2[i][j-1]
                    // sehingga jumlah jalur ada di elemen m2[rowcol-1][rowcol-1]

                    if (ELMT(m, i, j) == 0) {
                        if (i > 0) {
                            ELMT(m2, i, j) = (ELMT(m2, i, j) + ELMT(m2, i-1, j)) % MOD;
                        }
                        if (j > 0) {
                            ELMT(m2, i, j) = (ELMT(m2, i, j) + ELMT(m2, i, j-1)) % MOD;
                        }
                    }
                }
                
            }

            

        }

        printf("%d\n", ELMT(m2, rowcol-1, rowcol-1));
    }
    
    return 0;
}