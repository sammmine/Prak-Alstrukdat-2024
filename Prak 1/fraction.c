#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "fraction.h"

boolean IsFRACTIONValid(int N, int D) {
    return (N && D!=0);
}

void CreateFRACTION(FRACTION *F, int N, int D) {
    Numerator(*F) = N;
    Denominator(*F) = D;
}

void ReadFRACTION(FRACTION *F) {
    int n, d;
    scanf("%d %d", &n, &d);

    while (!IsFRACTIONValid(n, d)) {
        printf("FRACTION tidak valid\n");
        scanf("%d %d", &n, &d);
    }

    CreateFRACTION(F, n, d);
}

void WriteFRACTION(FRACTION F) {
    printf("%d/%d", (F).N, (F).D);
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;
    int a, b;

    a = (F1).N*(F2).D + (F2).N*(F1).D;
    b = (F1).D*(F2).D;

    CreateFRACTION(&F, a, b);
    F = SimplifyFRACTION(F);

    return F;
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;
    int a, b;

    a = (F1).N*(F2).D - (F2).N*(F1).D;
    b = (F1).D*(F2).D;

    CreateFRACTION(&F, a, b);
    F = SimplifyFRACTION(F);

    return F;

}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;
    int a, b;

    a = (F1).N*(F2).N;
    b = (F1).D*(F2).D;

    CreateFRACTION(&F, a, b);
    F = SimplifyFRACTION(F);

    return F;
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2) {
    FRACTION F;
    int a, b;

    a = (F1).N*(F2).D;
    b = (F1).D*(F2).N;

    CreateFRACTION(&F, a, b);
    F = SimplifyFRACTION(F);

    return F;
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1) {
    (F1).N *= n;

    F1 = SimplifyFRACTION(F1);

    return F1;
}

int GCD(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

FRACTION SimplifyFRACTION(FRACTION F) {
    int fpb = GCD(abs((F).N), abs((F).D));

    (F).N = (F).N / fpb;
    (F).D = (F).D / fpb;

    return F;
}

float ToDecimal(FRACTION F) {
    return ((float)(F).N / (float)(F).D);
}