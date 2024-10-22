#include <stdio.h>
#include "mesinkarakter.h"

// Karakter yang ada di jendela
char currentChar; 
// EOP (End Of Pita) akan menyala (true) jika currentChar = MARK
boolean EOP;

static FILE *pita;
static int retval;

void START() {
    pita = stdin; // Stdin is an input stream that takes input from the user or from a file (in this case, from a file)
    ADV();
}

void ADV() {
    // Read the next character 
    retval = fscanf(pita,"%c",&currentChar); 
    EOP = (currentChar == MARK);
    if (EOP) {
        fclose(pita);
    }
}