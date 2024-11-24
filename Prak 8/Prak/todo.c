#include <stdio.h>
#include "listlinier.h"

int main() {
    List l;
    CreateList(&l);

    char task;
    int id, bin, idxSearch;
    boolean leave = true;

    while (leave) {
        scanf(" %c", &task);

        if (task == 'X') {
            leave = false;
        }

        else if (task == 'P') {
            // Menambahkan task ke urutan pertama dalam list
            scanf(" %d", &id);
            insertFirst(&l, id);

        } else if (task == 'I') {
            // Menambahkan task ke akhir list
            scanf(" %d", &id);
            insertLast(&l, id);

        } else if (task == 'C') {
            // Menghapus task dari urutan pertama dalam list
            // Jika list kosong, do nothing
            if (!isEmpty(l)) {
                deleteFirst(&l, &bin);
            }

        } else if (task == 'D') {
            // Menghapus task dengan id tertentu dari list
            // Jika task tidak ditemukan, do nothing
            scanf(" %d", &id);
            idxSearch = indexOf(l, id);
            if (idxSearch != IDX_UNDEF) {
                deleteAt(&l, idxSearch, &bin);
            }
        }
    }
    
    displayList(l);
    return 0;
}
