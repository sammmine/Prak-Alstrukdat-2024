#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l, l2, count;
    int i, idxcount;
    int idx2 = 0;

    readList(&l);
    CreateListStatik(&l2);
    CreateListStatik(&count);
    
    for (i=0; i < listLength(l); i++){
        if (indexOf(l2, ELMT(l,i)) == IDX_UNDEF){ 
            ELMT(l2, idx2) = ELMT(l,i); 
            ELMT(count, idx2) = 0; 
            idx2 ++;
        }
    }
       
    for (i=0; i < listLength(l); i++){
        idxcount = indexOf(l2, ELMT(l,i));
        ELMT(count, idxcount) ++;
        }

    int max, max2, min;
    extremeValues(count, &max, &min); 
    
    if (max == min){
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    }
    else{
        int idxmax2;
        max2 = min;
        idxmax2= indexOf(count, max2);
        for (i=0; i < listLength(count); i++){
            if (ELMT(count,i) > max2 && ELMT(count,i) < max){
                max2 = ELMT(count,i);
                idxmax2 = i;
            }
            else if (ELMT(count,i) == max2){
                if (ELMT(l2, i) < ELMT(l2, idxmax2)){
                    idxmax2 = i;
                    max2 = ELMT(count,i);
                }
            }
        }
        printf("%d\n", ELMT(l2, idxmax2));
    }
    return 0;
}