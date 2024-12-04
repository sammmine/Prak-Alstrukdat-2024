#include <stdio.h>
#include "list_circular.h"

int main() {
    int N, i, val;
    List l;
    CreateList(&l);

    scanf("%d\n", &N);

    for(i=0; i<N; i++){
        scanf(" %d", &val);
        insertLast(&l, val);
    }

    // Find the max value
    int max = -9999;
    Address p = FIRST(l);
    while (NEXT(p) != FIRST(l)){
        if (INFO(p)>max) max = INFO(p);
        p = NEXT(p);
    }
    if (INFO(p)>max) max = INFO(p);

    // Search the max value address
    Address q = search(l, max);
    // Make that address as the first of the list
    FIRST(l) = q;

    displayList(l);
}