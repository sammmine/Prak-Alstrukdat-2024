#include <stdio.h>
#include "stack.h"

int main() {
    int N, i, j, a, lenWord, angka, tens;
    char ch, word[MaxEl];
    Stack stack;

    CreateEmpty(&stack);

    scanf("%d\n", &N);

    for(i=0; i<N; i++){
        scanf(" %c", &ch);
        
        // Close bracket berperan sebagai penanda untuk mengolah word
        // Jika ch adalah abjad, angka, atau open bracket, push ch ke stack
        if (ch!=']') {
            Push(&stack, ch);
        }

        // Jika ch adalah close bracket, maka olah word yang ada di dalam brackets
        else {
            lenWord = 0;
            // Store abjad ke array word
            // Pop semua abjad dari stack sampai bertemu '['
            while(InfoTop(stack) != '['){
                Pop(&stack, &word[lenWord]);
                lenWord++;
            }

            // Buang '[' dari stack
            Pop(&stack, &ch);

            // Proses angka yang akan digunakan untuk menduplikasi word
            angka = 0;
            tens = 1;
            while (!IsEmpty(stack) && InfoTop(stack) >= '0' && InfoTop(stack) <= '9') {
                Pop(&stack, &ch);
                angka = angka + (ch - '0') * tens;
                tens *= 10;
            }

            // Reverse abjad-abjad, sebelum diduplikasi
            for (j=0; j<lenWord/2; j++){
                char temp = word[j];
                word[j] = word[lenWord-j-1];
                word[lenWord-j-1] = temp;
            }

            // Duplikasi word sebanyak variabel angka
            for (j=0; j<angka; j++){
                for (int k=0; k<lenWord; k++){
                    Push(&stack, word[k]);
                }
            }
        }
    }

    // Masukkan semua abjad ke array penampung lagi
    lenWord=0;
    while(!IsEmpty(stack)){
        Pop(&stack, &word[lenWord]);
        lenWord++;
    }

    // Print, tapi reverse
    for (i=lenWord-1; i>=0; i--){
        printf("%c", word[i]);
    }
    printf("\n");

    return 0;
}