#include <stdio.h>
#include "stack.h"

int main() {
    int N, i;
    int a, b, sum, count, avg;
    char ch;
    Stack s;
    
    CreateEmpty(&s);

    scanf("%d\n", &N);

    for (i=0; i<N; i++){
        scanf(" %c", &ch);

        // START PROCESSING CHARACTER

        // Jika karakter adalah '+', pop 2 elemen dari stack, jumlahkan, dan push hasil penjumlahan
        if (ch == '+'){
            Pop(&s, &a);
            Pop(&s, &b);
            sum = a + b;
            Push(&s, b);
            Push(&s, a);
            Push(&s, sum); 
        }

        // Jika karakter adalah 'X', pop isi terakhir stack
        else if (ch == 'X'){
            Pop(&s, &a);
        }

        // jika character S
        else if (ch == 'S'){
            sum = 0;
            while (!IsEmpty(s)){
                Pop(&s, &a);
                sum += a;
            }
            Push(&s, sum);
        }

        // Jika karakter adalah 'A', rata-ratakan seluruh isi stack
        else if (ch == 'A'){
            sum = 0;
            count = 0;
            while (!IsEmpty(s)){
                Pop(&s, &a);
                sum += a;
                count += 1;
            }
            if (count == 0){
                avg = 0; // case stack tidak ada angka (avoiding pembagian dengan nol)
            } else {
                avg = sum / count; // floor atau pembulatan ke bawah
            }
            
            Push(&s, avg); 
        }
        
        // Jika karakter adalah angka, push ke stack
        else { // (ch >= '0' && ch <= '9')
            Push(&s, (ch-'0'));
        } 
    }

    // Keluaran
    sum = 0;
    while(!IsEmpty(s)){
        Pop(&s, &a);
        sum += a;
    }

    printf("%d\n", sum);
    return 0;
}