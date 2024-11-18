#include "hapus-duplikat.h"
#include "boolean.h"
#include <stdio.h> 
#include <stdlib.h>

List hapusDuplikat(List l) {
    Address p, q;           // Make two new pointers:
                            // First pointer is for the first-duplicate-element
                            // Second pointer is for the rest of the duplicates
                            // (Idea: delete the rest of the duplicates first, then we delete the first-duplicate-element)
    int idxP, idxQ;         // Indeces of the two pointers
    ElType valP, valQ;      // Values of the two pointers
    List result;            // The result list
    boolean found = false;  // Flag to delete the first-duplicate-element
    

    CreateList(&result);
    p = FIRST(l);

    while (p != NULL) {
        valP = INFO(p);
        idxP = indexOf(l, valP);
        q = NEXT(p);
        idxQ = idxP + 1;

        while (q != NULL) {
            valQ = INFO(q);
            if (valQ != valP) {
                break; // Stop if the value is already different, meaning there is no duplicate elements left (except itself)
            }
            deleteAt(&l, idxQ, &valQ); // Delete the duplicates
            q = NEXT(q);
            found = true;
        }

        if (found) {
            deleteAt(&l, idxP, &valP); // Delete the first-duplicate-element
            found = false; // Reset the flag
        }
        
        p = NEXT(p);
    }


    // Sort the result list ascendingly
        p = FIRST(l);
        while (p != NULL) {
            insertFirst(&result, INFO(p));
            p = NEXT(p);
        }
    return result;
}
