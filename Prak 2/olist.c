#include <stdio.h>
#include "liststatik.h"

// nomor 1
// main di index

int main () {
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

    // print list tanpa duplikasi elemen
    printList(lcopy);
    printf("\n");
    for (i=0; i<listLength(lcopy); i++) {
        printf("%d %d\n", ELMT(lcopy, i), ELMT(lcount, i));
    }

}