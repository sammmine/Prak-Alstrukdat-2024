#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin l;
    CreateListDin(&l, 100000);
    readList(&l);

    int N = listLength(l);
    int i;

    // simpen nilai maksimum dari kiri ke kanan
    int maks[N];
    maks[0] = ELMT(l, 0);
    for (i = 1; i < N; i++) {
        maks[i] = (ELMT(l, i) > maks[i - 1]) ? ELMT(l, i) : maks[i - 1];
    }

    // simpen nilai minimum dari kanan ke kiri
    int min[N];
    min[N - 1] = ELMT(l, N - 1);
    for (i = N - 2; i >= 0; i--) {
        min[i] = (ELMT(l, i) < min[i + 1]) ? ELMT(l, i) : min[i + 1];
    }

    // hitung jumlah elemen yang bisa jadi pivot
    int count = 0;
    for (i = 0; i < N; i++) {
        // elemen harus lebih besar dari maks kiri dan lebih kecil dari min kanan
        if ((i == 0 || maks[i - 1] <= ELMT(l, i)) &&
            (i == N - 1 || min[i + 1] >= ELMT(l, i))) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
