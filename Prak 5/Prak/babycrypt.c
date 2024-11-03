#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

int charToInt(char a) {
    if (a=='a' || a=='A') return 1;
    if (a=='b' || a=='B') return 2;
    if (a=='c' || a=='C') return 3;
    if (a=='d' || a=='D') return 4;
    if (a=='e' || a=='E') return 5;
    if (a=='f' || a=='F') return 6;
    if (a=='g' || a=='G') return 7;
    if (a=='h' || a=='H') return 8;
    if (a=='i' || a=='I') return 9;
    if (a=='j' || a=='J') return 10;
    if (a=='k' || a=='K') return 11;
    if (a=='l' || a=='L') return 12;
    if (a=='m' || a=='M') return 13;
    if (a=='n' || a=='N') return 14;
    if (a=='o' || a=='O') return 15;
    if (a=='p' || a=='P') return 16;
    if (a=='q' || a=='Q') return 17;
    if (a=='r' || a=='R') return 18;
    if (a=='s' || a=='S') return 19;
    if (a=='t' || a=='T') return 20;
    if (a=='u' || a=='U') return 21;
    if (a=='v' || a=='V') return 22;
    if (a=='w' || a=='W') return 23;
    if (a=='x' || a=='X') return 24;
    if (a=='y' || a=='Y') return 25;
    if (a=='z' || a=='Z') return 26;
    return -999; // buat karakter selain alphabet
}

boolean isUpper(char a) {
    if (a=='A'||a=='B'||a=='C'||a=='D'||a=='E'||a=='F'||a=='G'||a=='H'||a=='I'||a=='J'||a=='K'||a=='L'||a=='M'||a=='N'||a=='O'||a=='P'||a=='Q'||a=='R'||a=='S'||a=='T'||a=='U'||a=='V'||a=='W'||a=='X'||a=='Y'||a=='Z') {
        return true;
    }
    return false;
}

char intToChar(int a, boolean upper) {
    if (!upper) {
        if (a==1) return 'a';
        if (a==2) return 'b';
        if (a==3) return 'c';
        if (a==4) return 'd';
        if (a==5) return 'e';
        if (a==6) return 'f';
        if (a==7) return 'g';
        if (a==8) return 'h';
        if (a==9) return 'i';
        if (a==10) return 'j';
        if (a==11) return 'k';
        if (a==12) return 'l';
        if (a==13) return 'm';
        if (a==14) return 'n';
        if (a==15) return 'o';
        if (a==16) return 'p';
        if (a==17) return 'q';
        if (a==18) return 'r';
        if (a==19) return 's';
        if (a==20) return 't';
        if (a==21) return 'u';
        if (a==22) return 'v';
        if (a==23) return 'w';
        if (a==24) return 'x';
        if (a==25) return 'y';
        if (a==26) return 'z';
    } else if (upper) {
        if (a==1) return 'A';
        if (a==2) return 'B';
        if (a==3) return 'C';
        if (a==4) return 'D';
        if (a==5) return 'E';
        if (a==6) return 'F';
        if (a==7) return 'G';
        if (a==8) return 'H';
        if (a==9) return 'I';
        if (a==10) return 'J';
        if (a==11) return 'K';
        if (a==12) return 'L';
        if (a==13) return 'M';
        if (a==14) return 'N';        
        if (a==15) return 'O';
        if (a==16) return 'P';
        if (a==17) return 'Q';
        if (a==18) return 'R';
        if (a==19) return 'S';
        if (a==20) return 'T';
        if (a==21) return 'U';
        if (a==22) return 'V';
        if (a==23) return 'W';
        if (a==24) return 'X';
        if (a==25) return 'Y';
        if (a==26) return 'Z';
    }
    
}

int main() {
    int n;
    scanf("%d ", &n);
    STARTWORD();

    if (n>=26) {
        n = n%26;
    }

    while(!EndWord) {
        // mulai geser characters
        int i, geser;
        boolean upper;
        for (i=0; i<currentWord.Length; i++) {
            // cek dulu apakah uppercase atau tidak
            upper = isUpper(currentWord.TabWord[i]);
            // convert char ke int
            geser = charToInt(currentWord.TabWord[i]);
            // jika alphabet
            if (geser!=-999) {
                geser = geser-n;
                if(geser<0) {
                    geser = 26+geser;
                }
                // overwrite
                currentWord.TabWord[i] = intToChar(geser, upper);
            }
            
        }

        // selesai satu kata digeser, tulis kata
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }

        // nextword
        ADVWORD();
        if (!EndWord) {
                printf(" ");
        }
    }

    printf("\n");
    return 0;

}