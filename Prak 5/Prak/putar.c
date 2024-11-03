#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

void putarKata() {
    int i, j=0;
    Word temp;
    temp.Length = currentWord.Length;

    // store kata yang diputar di temp
    for(i=currentWord.Length-1; i>=0; i--) {
        temp.TabWord[j] = currentWord.TabWord[i];
        j++;
    }

    // replace atau overwrite currentWord dari temp
    for(i=0; i<currentWord.Length; i++) {
        currentWord.TabWord[i] = temp.TabWord[i];
    }
}

int main() {
    STARTWORD();
    int count = 1;
    int i;

    while (!EndWord) {
        if (count%2!=0) {
            putarKata();
        }

        // print current word
        for (i = 0; i < currentWord.Length; i++) {
        printf("%c", currentWord.TabWord[i]);
        }

        ADVWORD();
        count++;
        
        if (!EndWord) {
            printf(" ");
        }

        
    }

    printf("\n");
    return 0;
}