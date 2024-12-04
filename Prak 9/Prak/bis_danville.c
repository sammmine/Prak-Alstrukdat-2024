#include <stdio.h>
#include "list_circular.h"

int main() {
    // Input jumlah mahasiswa
    int n;
    scanf("%d", &n);

    // Buat dua buah list barisan mahasiswa (clockwise (cw) dan counter-clockwise (ccw))
    int i, val;
    List cw, ccw;
    CreateList(&cw);
    CreateList(&ccw);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insertFirst(&cw, val); // Untuk cw, kita storing terbalik
        insertLast(&ccw, val); // Untuk ccw, kita storing normal (terurut sesuai input)
    }

    Address p, q, nextP, nextQ;
    int iscw = 0, isccw = 0;
    p = FIRST(cw);
    q = FIRST(ccw);
    for (i=0; i<n; i++) {
        nextP = NEXT(p);
        nextQ = NEXT(q);

        if (INFO(nextP) > INFO(p)) iscw += 1;
        if (INFO(nextQ) > INFO(q)) isccw += 1;

        p = nextP;
        q = nextQ;
    }

    if (iscw==1 || isccw==1 || n==1 || n==0) printf("YES\n");
    else printf("NO\n");
    return 0;

    /* PENJELASAN ALGORITMA:
        CONTOH 1:
            - Misal input 1 2 3 4.
            - Expected outputnya adalah "YES" karena list memenuhi syarat secara clockwise.
            - Maka, cw = 4 3 2 1 dan ccw = 1 2 3 4.
            - Untuk kondisi cw, INFO(nextP)>INFO(p) hanya memenuhi saat p=1 dan nextP=4, sehingga iscw adalah 1. Dalam kata lain, saat kembali ke titik awal atau first of circular list.
            - Untuk kondisi ccw, INFO(nextQ)>INFO(q) akan selalu memenuhi, namun tidak masalah karena isccw harus 1.
        
        CONTOH 2:
            - Misal input 1 5 4 3 2.
            - Expected outputnya adalah "YES" karena list memenuhi syarat secara counter-clockwise.
            - Maka, cw = 2 3 4 5 1 dan ccw = 1 5 4 3 2.
            - Untuk kondisi cw, INFO(nextP)>INFO(p) akan hampir selalu memenuhi, namun tidak masalah karena iscw harus 1.
            - Untuk kondisi ccw, INFO(nextQ)>INFO(q) hanya memenuhi saat q=5 dan nextQ=1, sehingga isccw adalah 1.
    */

    //Algoritma ini akan selalu memenuhi untuk kasus-kasus tertentu, seperti jika mahasiswa tidak terurut dari angka 1-N (contoh input = 2 3 4 1)
}