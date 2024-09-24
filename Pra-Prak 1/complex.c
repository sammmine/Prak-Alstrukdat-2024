#include <stdio.h>
#include <math.h>
#include "complex.h"

boolean IsCOMPLEXValid(float Re, float Im) {
    return TRUE;
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
    C->Re = Re;
    C->Im = Im;
    // kalau pointer penulisannya gini (arrow operator)
}

void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;

    scanf("%.2f", &Re);
    scanf("%.2f", &Im);

    if (IsCOMPLEXValid(Re, Im)) {
        CreateComplex(C, Re, Im);
    } else {
        printf("Input tidak valid.\n");
    }
}

void TulisCOMPLEX(COMPLEX C) {
    printf("%.2f + %.2fi", (C).Re, (C).Im);
    // dot operator
}

