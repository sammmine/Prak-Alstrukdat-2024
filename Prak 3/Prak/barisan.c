#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin l, ltemp;
    int i, j, k, back = 0;
    boolean found;

    // list input
    CreateListDin(&l, 1000);
    readList(&l);

    // membuat list kosong temporary
    CreateListDin(&ltemp, 1000);

    // masukan elemen pertama list l ke list temporary
    ELMT(ltemp, 0) = ELMT(l, 0);
    NEFF(ltemp) = 1;

    for (i = 1; i < listLength(l); i++) {
        j = 0;
        found = false; 

        while (!found && j <= getLastIdx(ltemp)) {
            if (ELMT(l, i) < ELMT(ltemp, j)) {
                // mundurin angka2 selanjutnya
                for (k = getLastIdx(ltemp); k >= j; k--) {
                    ELMT(ltemp, k + 1) = ELMT(ltemp, k);
                }
                ELMT(ltemp, j) = ELMT(l, i);
                back += getLastIdx(ltemp) - j + 1;
                NEFF(ltemp) += 1;
                found = true;           
            } else {
                j++;
            }
        }

        if (!found) {
            ELMT(ltemp, NEFF(ltemp)) = ELMT(l, i);
            NEFF(ltemp) += 1;
        }
    }

    printf("%d\n", back);
    
    return 0;
}
