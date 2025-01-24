#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */
Address newNode(ElType x){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
    Address P = (Address) malloc(sizeof(Node));
    if (P != NULL) {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
    return l == NULL;
}
boolean isOneElmt(List l){
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
    if (isEmpty(l)) {
        return false;
    } else {
        return NEXT(l) == NULL;
    }
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
    return INFO(l);
}
List tail(List l){
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
    return NEXT(l);
}
List konso(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
    Address P = newNode(e);
    if (P != NULL) {
        NEXT(P) = l;
        l = P;
    }
    return l;
}
List konsb(List l, ElType e){
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(NEXT(l), e);
        return l;
    }
}
List copy(List l){
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konso(copy(tail(l)), head(l));
    }
}
List concat(List l1, List l2){
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l){
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}
boolean isMember(List l, ElType x){
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
    if (isEmpty(l)) {
        return false;
    }
    return (head(l) == x) || isMember(tail(l), x);
}
void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
    if (!isEmpty(l)) {
        printf("%d", head(l));
        List temp = tail(l);
        while (!isEmpty(temp))
        {
            printf("\n%d", head(temp));
            temp = tail(temp);
        }
        printf("\n");
    }
}

// TAMBAHAN

List insertAt(List l, ElType e, int idx) {
    if (idx == 0) {
        return konso(l, e);
    }
    else {
        return konso(insertAt(tail(l), e, idx-1), head(l));
    }
}

List deleteFirst(List l) {
    return tail(l);
}

List deleteAt(List l, int idx) {
    if (idx == 0) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(tail(l), idx-1), head(l));
    }
}

List deleteLast(List l) {
    int list_length = length(l);
    return deleteAt(l, list_length-1);
}

List reverseList (List l) {
    if (isOneElmt(l)) return l;
    return konsb(reverseList(tail(l)), head(l));
}

void splitOddEven (List l, List *l1, List *l2) {
    if (isEmpty(l)) return;

    if (head(l) % 2 == 0) *l1 = konsb(*l1, head(l));
    else *l2 = konsb(*l2, head(l));

    splitOddEven(tail(l), l1, l2);
}

void splitOnX (List l, int x, List *l1, List *l2) {
    if (x == 0) {
        *l2 = l;
        return;
    } else {
        *l1 = konsb(*l1, head(l));
        splitOnX(tail(l), x-1, l1, l2);
    }
}

ElType getMiddle(List l) {
    int length_list = length(l);
    List left = NULL, right = NULL;

    splitOnX(l, length_list/2, &left, &right);
    return INFO(right);
}