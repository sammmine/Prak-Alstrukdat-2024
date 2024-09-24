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

    scanf("%.2f %.2f", &Re, &Im);

    while (!IsCOMPLEXValid(Re, Im)){
        printf("Complex tidak valid.\n");
        scanf("%.2f %.2f", &Re, &Im);
    }
    CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
    printf("%.2f + %.2fi", (C).Re, (C).Im);
    // dot operator
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Csum;

    (Csum).Re = (C1).Re + (C2).Re;
    (Csum).Im = (C1).Im + (C2).Im;

    return Csum;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Csub;

    (Csub).Re = (C1).Re - (C2).Re;
    (Csub).Im = (C1).Im - (C2).Im;

    return Csub;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX Cmul;

    (Cmul).Re = (C1).Re * (C2).Re - (C1).Im * (C2).Im;
    (Cmul).Im = (C1).Re * (C2).Im + (C1).Im * (C2).Re;

    return Cmul;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX Cdiv;
    float denom;

    denom = pow((C2).Re, 2) + pow((C2).Im, 2);

    if (denom == 0) {
        (Cdiv).Re = 0;
        (Cdiv).Im = 0;

    } else {
        ConjugateCOMPLEX(C2);
        Cdiv = MultiplyCOMPLEX(C1, C2);
        (Cdiv).Re = (Cdiv).Re / denom;
        (Cdiv).Im = (Cdiv).Im / denom;
 
    }

    return Cdiv;
}

float AbsCOMPLEX(COMPLEX C) {
    float modC;

    modC = sqrt(pow((C).Re, 2) + pow((C).Im, 2));

    return modC;
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    // konjugasi itu hanya menegatifkan komponen imajinernya
    (C).Im = 0 - (C).Im;

    return C;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return ((C1).Re == (C2).Re && (C1).Im == (C2).Im);
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return ((C1).Re != (C2).Re && (C1).Im != (C2).Im);
}