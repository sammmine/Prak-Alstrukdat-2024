#include <stdio.h>
#include "listlinier.h"

int main() {
    int val;
    List l, result;
    CreateList(&l);
    CreateList(&result);
    

    // Input
    scanf("%d", &val);
    if (val!=-9999){
        do{
            insertLast(&l, val);
            scanf("%d", &val);
        } while (val != -9999);
    }

    if (!isEmpty(l)){
        // Insert result's first element
        int store;
        deleteFirst(&l, &store);
        insertFirst(&result, store);

        // P is a pointer to point at the correct ascending position
        // IdxP is a integer to flag the correct ascending index based on pointer p
        Address p = result;
        int idxP = 0;
        boolean found = false;
        while (l!=NULL){
            idxP = 0;
            p = result; 
            found = false;
            deleteFirst(&l, &store);
            while (!found){
                if (store<INFO(p)){
                    insertAt(&result, store, idxP);
                    found = true;
                } else if (NEXT(p) == NULL) {
                    insertLast(&result, store);
                    found = true;
                } 
                else {
                    idxP++;
                    p = NEXT(p);
                }
            }   
        }
    }
        
    displayList(result);
    
}