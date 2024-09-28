#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "rotating_point.h"
#include "circle.h"
#include "point.h"
#include "circle.c"
#include "point.c"

COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX H; 
    // buat temporary
    int i;

    (H).Re = 1;
    (H).Im = 0;

    for (i=1; i<=p; i++) {
        H = MultiplyCOMPLEX(C, H);
    }

    return H;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    int i;

    for (i = 1; i <= n; i++) {
        C = PowerCOMPLEX(C, i); 
        (*P).X = (*P).X * (C).Re - (*P).Y * (C).Im;
        (*P).Y = (*P).X * (C).Im + (*P).Y * (C).Re;

        if ( ((*P).X*(*P).X + (*P).Y*(*P).Y) != 1) {
            printf("Titik keluar dari lingkaran pada iterasi ke %d\n", i);
            return;
        }
    }

    printf("Titik tetap berada di dalam lingkaran setelah %d iterasi\n", n);
}

int main() {
    POINT P;
    COMPLEX C;
    int n;

    scanf("%f %f", &(P).X, &(P).Y);
    scanf("%f %f", &(C).Re, &(C).Im);
    scanf("%d", &n);

    TransformPointByComplexPower(&P, C, n);

    return 0;
}
