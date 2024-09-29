#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"
#include "boolean.h"
// #include "point.h"
// #include "point.c"

// masih salah di keempat dan di tengah

boolean IsCIRCLEValid(float X, float Y, float R) {
    return (R > 0);
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R) {
    Center(*C).X = X;
    Center(*C).Y = Y;
    Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C) {
    float x, y, r;

    scanf("%f %f %f", &x , &y, &r);

    while (!IsCIRCLEValid(x, y, r)) {
        printf("CIRCLE tidak valid\n");
        scanf("%f %f %f", &x , &y, &r);
    }

    CreateCIRCLE(C, x, y, r);
}

void WriteCIRCLE(CIRCLE C) {
    printf("P(%.2f,%.2f) r=%.2f", (C).CENTER.X, (C).CENTER.Y, (C).R);
}

float Circumference(CIRCLE C) {
    return (2*3.14*(C).R);
}

float Area(CIRCLE C) {
    return (3.14*(C).R*(C).R);
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P) {
    float x, y, d;

    x = ((C).CENTER.X - (P).X) * ((C).CENTER.X - (P).X);
    y = ((C).CENTER.Y - (P).Y) * ((C).CENTER.Y - (P).Y);
    d = sqrt(x + y);
    // d for distance

    return (d < (C).R);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P) {
    float x, y, d;

    x = ((C).CENTER.X - (P).X) * ((C).CENTER.X - (P).X);
    y = ((C).CENTER.Y - (P).Y) * ((C).CENTER.Y - (P).Y);
    d = sqrt(x + y);

    return (d == (C).R);
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2) {
    float x, y, d;

    x = ((C1).CENTER.X - (C2).CENTER.X) * ((C1).CENTER.X - (C2).CENTER.X);
    y = ((C1).CENTER.Y - (C2).CENTER.Y) * ((C1).CENTER.Y - (C2).CENTER.Y);
    d = sqrt(x + y);

    return (d < abs((C1).R - (C2).R));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2) {
    float x, y, d;

    x = ((C1).CENTER.X - (C2).CENTER.X) * ((C1).CENTER.X - (C2).CENTER.X);
    y = ((C1).CENTER.Y - (C2).CENTER.Y) * ((C1).CENTER.Y - (C2).CENTER.Y);
    d = sqrt(x + y);

    return ((d == abs((C1).R - (C2).R)) || (d == (C1).R + (C2).R));
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2) {
    float x, y, d;

    x = ((C1).CENTER.X - (C2).CENTER.X) * ((C1).CENTER.X - (C2).CENTER.X);
    y = ((C1).CENTER.Y - (C2).CENTER.Y) * ((C1).CENTER.Y - (C2).CENTER.Y);
    d = sqrt(x + y);

    return ((d > abs((C1).R - (C2).R)) && (d < (C1).R + (C2).R));
}

