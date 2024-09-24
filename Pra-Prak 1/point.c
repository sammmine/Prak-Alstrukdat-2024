#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"

void CreatePoint (POINT *P, float X, float Y) {
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P) {
    float X, Y;
    scanf("%.2f %.2f", &X, &Y);

    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) {
    printf("(%.2f,%.2f)", (P).X, (P).Y);
}

boolean EQ(POINT P1, POINT P2) {
    return ((P1).X == (P2).X && (P1).Y == (P2).Y);
}

boolean NEQ(POINT P1, POINT P2) {
    return ((P1).X != (P2).X || (P1).Y != (P2).Y);
}

boolean IsOrigin(POINT P) {
    return ((P).X == 0 && (P).Y == 0);
}

boolean IsOnSbX(POINT P) {
    return ((P).Y == 0);
}

boolean IsOnSbY(POINT P) {
    return ((P).X == 0);
}

int Kuadran(POINT P) {
    if (!IsOrigin(P) && !IsOnSbX(P) && !IsOnSbY) {
        if ((P).X > 0 && (P).Y > 0) {
            return 1;
        } else if ((P).X > 0 && (P).Y < 0) {
            return 4;
        } else if ((P).X < 0 && (P).Y > 0) {
            return 2;
        } else if ((P).X < 0 && (P).Y < 0) {
            return 3;
        }
    }
    return 0;
}

POINT NextX(POINT P) {
    (P).X = (P).X + 1; 
    return P;
}

POINT NextY(POINT P) {
    (P).Y = (P).Y + 1; 
    return P;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
    (P).X += deltaX;
    (P).Y += deltaY;
    return P;
}

POINT MirrorOf(POINT P, boolean SbX) {
    if (SbX) {
        // thdp sumbu x
        (P).Y *= (-1);
    } else {
        // thdp sumbu y
        (P).X *= (-1);
    }

    return P;
}

float Jarak0 (POINT P) {
    return sqrt((pow((P).X, 2) + pow((P).Y, 2)));
}

float Panjang (POINT P1, POINT P2) {
    return sqrt((pow(((P1).X - (P2).X), 2) + pow(((P1).Y - (P2).Y), 2)));
}

void Geser(POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P) {
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P) {
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX) {
    if (SbX) {
        // thdp sumbu x
        Ordinat(*P) *= (-1);
    } else {
        // thdp sumbu y
        Absis(*P) *= (-1);
    }
}

void Putar(POINT *P, float Sudut) {
    float rad = (-1) * Sudut * 3.14159265358979323846 / 180.0;
    float cos = cosf(rad);
    float sin = sinf(rad);
    
    float x = (Absis(*P) * cos) - (Ordinat(*P) * sin);
    float y = (Absis(*P) * sin) + (Ordinat(*P) * cos);

    Absis(*P) = x;
    Ordinat(*P) = y;
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
    float a, b;

    a = ((P2).Y - (P1).Y) / ((P2).X - (P1).X);
    b = (P1).Y - ((P1).X / ((P2).X - (P1).X));

    printf("y = %.2fx + %.2f", a, b);
}