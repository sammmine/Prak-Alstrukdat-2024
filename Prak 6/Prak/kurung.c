#include <stdio.h>
#include "stack.h"

int main() {
    int N, i;
    char ch, close;
    Stack s;

    CreateEmpty(&s);

    scanf("%d\n", &N); 

    // Edge case jika N character berjumlah ganjil
    if(N % 2 != 0){
        printf("Invalid\n");
        return 0;
    }

    for (i=0; i<N; i++){
        scanf(" %c", &ch);

        // If it's an opening bracket, push the closing bracket to the stack
        if (ch == '('){
            Push(&s, ')');
        }
        else if (ch == '['){
            Push(&s, ']');
        }
        else if (ch == '{'){
            Push(&s, '}');
        }

        // If it's a closing bracket, pop the stack and compare
        else if(ch == ')' || ch == ']' || ch == '}'){
            if(IsEmpty(s)){
                printf("Invalid\n");
                return 0;
            } else {
                Pop(&s, &close);
                if(close != ch){
                    printf("Invalid\n");
                    return 0;
                }
            }
        }
    }
    
    // Cek apakah stack kosong, stack kosong artinya semua brackets memiliki pasangan dan urutan pasangan valid
    if (IsEmpty(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}