#include <stdio.h>
#include "listlinier.h"

int main() {
    int digit;

    // Input bilangan non-negatif pertama
    List l1;
    CreateList(&l1);
    while (1) {
        scanf(" %d", &digit);
        if (digit == -1) break;
        insertLast(&l1, digit);
    }

    // Input bilangan non-negatif kedua
    List l2;
    CreateList(&l2);
    while (1) {
        scanf(" %d", &digit);
        if (digit == -1) break;
        insertLast(&l2, digit);
    }

    // Reverse kedua list agar dapat menjumlahkan bilangan dari belakang
    Address p1 = l1;
    Address p2 = l2;
    List rev1, rev2;
    CreateList(&rev1);
    CreateList(&rev2);
    // Reverse list bilangan pertama
    while (p1 != NULL){
        insertFirst(&rev1, INFO(p1));
        p1 = NEXT(p1);
    }
    // Reverse list bilangan kedua
    while (p2 != NULL){
        insertFirst(&rev2, INFO(p2));
        p2 = NEXT(p2);
    }

    // Proses penjumlahan
    List result;
    CreateList(&result);
    p1 = rev1;
    p2 = rev2;
    int carry = 0;
    while (p1 != NULL || p2 != NULL || carry > 0){  // Tidak masalah jika length kedua list berbeda.
                                                    // Karena selama masih ada angka di kedua atau salah satu list, iterasi akan tetap berjalan.
        int sum = carry;
        if (p1 != NULL){
            sum += INFO(p1);
            p1 = NEXT(p1);
        }
        if (p2 != NULL){
            sum += INFO(p2);
            p2 = NEXT(p2);
        }
        carry = sum/10; // Simpanan penjumlahan untuk angka di depannya
        insertFirst(&result, sum%10); // Sisa hasil penjumlahan
    }

    // Output (bukan pakai displayList)
    // List result tidak perlu di-reverse karena telah memakai insertFirst
    Address p = result;
    while (p != NULL){
        printf("%d", INFO(p));
        if (NEXT(p) != NULL) printf(" ");
        p = NEXT(p);
    }

    printf("\n");
    return 0;
}