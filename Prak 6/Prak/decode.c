#include <stdio.h>
#include "stack.h"

// KHUSUS UNTUK NOMOR 2 DAN 3, TIPE DATA INFOTYPE DIGANTI MENJADI CHAR

int main() {
    int N, i, j, lenWord;
    char ch, openBrac, dup;
    char store[MaxEl], all[MaxEl];
    Stack word, number;

    CreateEmpty(&word);
    CreateEmpty(&number);

    scanf("%d\n", &N);

    for(i=0; i<N; i++){
        scanf(" %c", &ch);
        
        // Jika ch adalah angka, push ch ke stack number
        if (ch>='0' && ch<='9'){
            Push(&number, ch); // Ch masih char, belum diubah ke integer
        }

        // Jika ch adalah abjad atau '[', push ch ke stack word
        else if (ch>='a' && ch<='z' || ch=='['){
            Push(&word, ch);
        }

        // Jika ch adalah ']', olah stack word
        else if (ch==']'){
            // Pop abjad ke array penampung
            lenWord = 0;
            // Olah word yang ada di brackets, sehingga pop sampai '['
            while(InfoTop(word) != '['){
                Pop(&word, &store[lenWord]);
                lenWord++;
            }

            // Pop '[' dari stack
            Pop(&word, &openBrac);

            // Reverse abjad-abjad, sebelum diduplikasi
            for (j=0; j<lenWord/2; j++){
                char temp = store[j];
                store[j] = store[lenWord-j-1];
                store[lenWord-j-1] = temp;
            }

            // Push abjad-abjad di array kembali ke stack dan diduplikasi
            Pop(&number, &dup);
            for (j=0; j<(dup-'0'); j++){
                for (int k=0; k<lenWord; k++){
                    Push(&word, store[k]);
                }
            }
        }
    }

    // Keluaran

    // Masukkan semua abjad ke array penampung lagi
    lenWord=0;
    while(!IsEmpty(word)){
        Pop(&word, &store[lenWord]);
        lenWord++;
    }

    // Print, tapi reverse
    for (i=lenWord-1; i>=0; i--){
        printf("%c", store[i]);
    }
    printf("\n");

    return 0;
}