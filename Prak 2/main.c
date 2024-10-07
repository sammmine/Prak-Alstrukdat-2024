#include <stdio.h>
#include "liststatik.c"

// nomor tiga

int main () {
    // membuat list tanpa duplikat dan list count dulu
    // copy dari nomor 1
    ListStatik l, lcopy, lcount;
    int i;
    int idxcopy = 0, idxcount = 0;

    // list l adalah input
    readList(&l);
    // lcopy adalah list l tanpa duplikat elemen
    CreateListStatik(&lcopy);
    // lcount adalah list yang berisi jumlah muncul elemen list l
    CreateListStatik(&lcount);

    // mencopy elemen list l ke lcopy tanpa duplikasi elemen
    for (i=getFirstIdx(l); i<listLength(l); i++) {
        // jika elemen i belum ada di lcopy (dengan mengecek index)
        if (indexOf(lcopy, ELMT(l, i)) == IDX_UNDEF) {
            // copy elemen i ke lcopy
            ELMT(lcopy, idxcopy) = ELMT(l, i);
            // elemen lcount bertambah (dengan diubah dari MARK ke 0)
            ELMT(lcount, idxcopy) = 0;
            idxcopy += 1;
        }
    }

    // menghitung duplikat elemen di list l
    for (i=getFirstIdx(l); i<listLength(l); i++) {
        // cari index dari elemen l di lcopy
        idxcount = indexOf(lcopy, ELMT(l,i));
        // tambah 1 untuk index tersebut (menandakan countnya)
        ELMT(lcount, idxcount) += 1;
    }

    ElType max, max2;
    int idxmax2;
    max = max2 = ELMT(lcount, 0);
    
    for (i=0; i<listLength(lcopy); i++) {
        if (ELMT(lcount, i) > max) {
            max2 = max;
            max = ELMT(lcount, i);
        } else if (ELMT(lcount, i) > max2 && ELMT(lcount, i) != max) {
            max2 = ELMT(lcount, i);
        }
    }

    idxmax2 = indexOf(lcount, max2);
    printf("%d", ELMT(l, idxmax2));
    
}