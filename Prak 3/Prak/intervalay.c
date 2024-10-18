#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin l, l2;
    int n = NEFF(l), i = 0;
    int start, stop, start2, stop2;

    scanf("%d", &n);
    CreateListDin(&l, n);
    readList(&l);

    scanf("%d %d", &start2, &stop2);

    CreateListDin(&l2, CAPACITY(l));

    // masukan interval sebelum newInterval yang tidak beririsan
    while (i < n && ELMT(l, i + 1) < start2) {
        insertLast(&l2, ELMT(l, i));
        insertLast(&l2, ELMT(l, i + 1));
        i += 2;
    }

    // gabungkan newInterval dengan interval yang bertumpuk
    while (i < n && ELMT(l, i) <= stop2) {
        if (start2 >= ELMT(l, i)) {
            start2 = ELMT(l, i);
        }

        if (stop2 <= ELMT(l, i + 1)) {
            stop2 = ELMT(l, i + 1);
        }

        i += 2;
    }

    // masukan newInterval yang sudah diperbarui
    insertLast(&l2, start2);
    insertLast(&l2, stop2);

    // masukan interval setelah newInterval yang tidak beririsan
    while (i < n) {
        insertLast(&l2, ELMT(l, i));
        insertLast(&l2, ELMT(l, i + 1));
        i += 2;
    }

    // salin hasil ke intervalay
    copyList(l, &l2);
    dealocateList(&l2);

    printList(l);
    dealocateList(&l);

    return 0;
}
