#include <stdio.h>
#include "matrix.h"

const int MOD = 1e9 + 7;

int main() {
    int rowcol;
    int i = 0, j = 0;
    Matrix m, m2;

    scanf("%d", &rowcol);

    if(rowcol > 0 && rowcol <= ROW_CAP) {
        readMatrix(&m, rowcol, rowcol);
        createMatrix(rowcol, rowcol, &m2);
        
        // ide --> jika elemen m[i][j] adalah 0, maka tambahkan elemen m2[i][j] dengan elemen m2[i-1][j] dan m2[i][j-1]
        // sehingga jumlah jalur ada di elemen m2[rowcol-1][rowcol-1]

        // inisialisasi dulu elemen m2 menjadi 0
        for (i = 0; i < rowcol; i++) {
            for (j = 0; j < rowcol; j++) {
                ELMT(m2, i, j) = 0;
            }
        }

        // case jika posisi awal dan akhir tidak terhalang jebakan
        if(ELMT(m, 0, 0) == 0 && ELMT(m, rowcol - 1, rowcol - 1) == 0) {
            ELMT(m2, 0, 0) = 1;

            for (i = 0; i < rowcol; i++) {
                for (j = 0; j < rowcol; j++) {
                    // jika tidak ada jebakan
                    if (ELMT(m, i, j) == 0) {
                        // tambah dari atas jika bukan baris pertama
                        if (i > 0) {
                            ELMT(m2, i, j) = (ELMT(m2, i, j) + ELMT(m2, i - 1, j)) % MOD;
                        }
                        // tambah dari kiri jika bukan kolom pertama
                        if (j > 0) {
                            ELMT(m2, i, j) = (ELMT(m2, i, j) + ELMT(m2, i, j - 1)) % MOD;
                        }
                    }
                }
            }

            // cetak hasil jumlah jalur
            printf("%d\n", ELMT(m2, rowcol - 1, rowcol - 1));

        } else {
            // case jika posisi awal atau akhir terhalang jebakan
            printf("0\n");
        }
    }
    
    return 0;
}
