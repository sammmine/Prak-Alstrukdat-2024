#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"


// Akhir dari proses, true jika kata terakhir telah diakuisisi
boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while ((currentChar == BLANK) && (!EOP)) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if (EOP) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    currentWord.Length = 0;
    while ((currentChar != BLANK) && (!EOP)) {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();
    }
}