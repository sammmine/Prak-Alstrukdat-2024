#include <stdio.h>
#include "boolean.h"
#include "fraction.h"

boolean IsFRACTIONValid(int N, int D) {
    return (D!=0);
}

void CreateFRACTION(FRACTION *F, int N, int D) {
    Numerator(*F) = N;
    Denominator(*F) = D;
}

void ReadFRACTION(FRACTION *F) {
    int n, d;

    do {
        scanf("%d %d", &n, &d);
        if(!IsFRACTIONValid(n,d)) {
            printf("FRACTION tidak valid\n");
        } 
    } while (!IsFRACTIONValid(n,d));

    CreateFRACTION(F, n, d);
}

void WriteFRACTION(FRACTION F) {
    F = SimplifyFRACTION(F);
    printf("%d/%d", (F).N, (F).D);
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;

    (F).N = (F1).N*(F2).D + (F2).N*(F1).D;
    (F).D = (F1).D*(F2).D;

    return SimplifyFRACTION(F);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;

    (F).N = (F1).N*(F2).D - (F2).N*(F1).D;
    (F).D = (F1).D*(F2).D;

    return SimplifyFRACTION(F);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;

    (F).N = (F1).N*(F2).N;
    (F).D = (F1).D*(F2).D;

    return SimplifyFRACTION(F);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;

    (F).N = (F1).N*(F2).D;
    (F).D = (F1).D*(F2).N;

    return SimplifyFRACTION(F);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    (F1).N *= n;

    F1 = SimplifyFRACTION(F1);

    return F1;
}

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

FRACTION SimplifyFRACTION(FRACTION F) {
    int fpb = GCD((F).N, (F).D);

    (F).N = (F).N / fpb;
    (F).D = (F).D / fpb;

    // ini untuk kalau penyebutnya minus, minusnya dipindah ke pembilang
    if (F.D < 0) {
        F.N = -F.N;
        F.D = -F.D;
    }

    return F;
}

float ToDecimal(FRACTION F) {
    return ((float)(F).N / (F).D);
}