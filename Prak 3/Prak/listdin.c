#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity) {
    // Membentuk list dinamis l dengan kapasitas capacity
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    // Memory allocation untuk list
    BUFFER(*l) = (int*) malloc(CAPACITY(*l) * sizeof(ElType));
}

void dealocateList(ListDin *l) {
    // Me-reset list l dengan free memory
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l) {
    // Panjang list dinamis adalah n-efektif-nya
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l) {
    // List dinamisnya rata kiri
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l) {
    return NEFF(l)-1 ;
}

boolean isIdxValid(ListDin l, IdxType i) {
    return (i>=IDX_MIN && i<CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i) {
    return (i>=IDX_MIN && i<NEFF(l));
}

boolean isEmpty(ListDin l) {
    return NEFF(l)==0;
}

boolean isFull(ListDin l) {
    return NEFF(l)==CAPACITY(l);
}

void readList(ListDin *l) {
    int n; // untuk n-efektif
    IdxType i;

    do {
        scanf("%d", &n);
    } while (n<0 || n>CAPACITY(*l));

    NEFF(*l) = n;

    for (i=IDX_MIN; i<NEFF(*l); i++) {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListDin l) {
    IdxType i;

    printf("[");
    for (i=0; i<=getLastIdx(l); i++) {
        printf("%d", ELMT(l, i));
        if (i<getLastIdx(l)) {
            printf(",");
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus) {
    IdxType i;
    ListDin l;

    // list menampung hasil
    CreateListDin(&l, CAPACITY(l1));
    NEFF(l) = NEFF(l1);

    for (i=IDX_MIN; i<listLength(l1); i++) {
        if (plus) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        } else {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return l;
}

boolean isListEqual(ListDin l1, ListDin l2) {
    IdxType i;
    if (listLength(l1) != listLength(l2)) {
        return false;
    }
    for (i=IDX_MIN; i<=listLength(l1); i++) {
        if (ELMT(l1, i) != ELMT(l2, i)) {
            return false;
        }
    }
    return true;
}

IdxType indexOf(ListDin l, ElType val) {
    IdxType i;

    for (i=0; i<listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }

    return IDX_UNDEF;
}

void extremeValues(ListDin l, ElType *max, ElType *min) {
    IdxType i;

    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i=0; i<listLength(l); i++) {
        if (ELMT(l, i)>*max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i)<*min) {
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut) {
    IdxType i;

    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i=0; i<listLength(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

ElType sumList(ListDin l) {
    int sum = 0;
    IdxType i;

    for (i=0; i<listLength(l); i++) {
        sum += ELMT(l,i);
    }

    return sum;
}

int countVal(ListDin l, ElType val) {
    int count = 0;
    IdxType i;

    for (i=0; i<listLength(l); i++) {
        if (ELMT(l, i) == val) {
            count++;
        }
    }

    return count;
}

void sort(ListDin *l, boolean asc){
    int i, j, temp;
    if (asc) {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMT(*l,j) < ELMT(*l,j-1)) {
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j-1);
                    ELMT(*l,j-1) = temp;
                }
            }
        }
    } else {
        for (i=getFirstIdx(*l); i<getLastIdx(*l); i++){
            for (j=getLastIdx(*l); j>i; j--){
                if (ELMT(*l,j) > ELMT(*l,j-1)) {
                    temp = ELMT(*l,j);
                    ELMT(*l,j) = ELMT(*l,j-1);
                    ELMT(*l,j-1) = temp;
                }
            }
        }

    }
}

void insertLast(ListDin *l, ElType val) {
    ELMT(*l, getLastIdx(*l)+1) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val) {
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

void expandList(ListDin *l, int num) {
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L)+num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l, i) = ELMT(L, i);
    }
}

void shrinkList(ListDin *l, int num) {
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, CAPACITY(L)-num);
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l, i) = ELMT(L, i);
    }
}

void compressList(ListDin *l) {
    ListDin L;
    copyList(*l, &L);
    dealocateList(l);
    CreateListDin(l, NEFF(L));
    NEFF(*l) = NEFF(L);
    IdxType i;
    for (i=getFirstIdx(L); i<=getLastIdx(L); i++) {
        ELMT(*l, i) = ELMT(L, i);
    }
}
