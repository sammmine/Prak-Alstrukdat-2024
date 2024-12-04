#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l) {
    return FIRST(l) == NULL;
}

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

Address allocate(ElType val) {
    // Allocating memory and making a new node
    Address p = (Address) malloc (sizeof(ElmtList));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P) {
    // Deallocate memory for a node
    free(P); // Function from stdlib.h, used to free up the space allocated by malloc
}

Address search(List l, ElType val) {
    // Search a node
    if (isEmpty(l)) return NULL;
    Address p = FIRST(l);
    boolean found = false;
    while (NEXT(p) != FIRST(l) && !found) { // While it's not the end of the circular list and found is still false
        found = INFO(p) == val;
        if (!found) p = NEXT(p);
    }
    if (INFO(p) == val) found = true;   // This is to check the last node
                                        // If it is found in the first/middle of the node, it doesn't affect anything, because the while loop is already break-ed
    if (found) return p;
    return NULL; // If it's not found
}

boolean addrSearch(List l, Address p) {
    // Search if a node exists based on its address
    if (isEmpty(l)) return false;
    Address q = FIRST(l);
    boolean found = false;
    while (NEXT(q) != FIRST(l) && !found) { // While it's not the end of the circular list and found is still false
        found = q == p;
        if (!found) q = NEXT(q);
    }
    if (q == p) found = true;   // This is to check the last node
                                // If it is found in the first/middle of the node, it doesn't affect anything, because the while loop is already break-ed
    return found;
}

void insertFirst(List *l, ElType val) {
    Address p = allocate(val); // Making a new node with the value we want to insert
    Address loc = FIRST(*l);
    if (p != NULL) {
        if (isEmpty(*l)) {
            FIRST(*l) = p;
            NEXT(p) = FIRST(*l); // Since it's circular, the next of the first node is the first node itself
        } else {
            NEXT(p) = loc;
            FIRST(*l) = p;
            p = NEXT(p);
            while (NEXT(p) != loc) { // Moving to the last node of the circular list
                p = NEXT(p);
            }
            NEXT(p) = FIRST(*l); // Readdressing the next of the last nodes
        }
    }
}

void insertLast(List *l, ElType val) {
    Address p = FIRST(*l);
    Address loc = NULL;
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        while (NEXT(p) != FIRST(*l)) { // Moving to the last node of the circular list
            p = NEXT(p);
        }
        NEXT(p) = allocate(val);
        if (NEXT(p) != NULL) { // If the allocation is successful
            NEXT(NEXT(p)) = FIRST(*l); // The next of the val node is the first list
        } else {
            NEXT(p) = FIRST(*l); 
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p = FIRST(*l); // p is for pointing at the soon-to-be-deleted node
    *val = INFO(p);
    if (NEXT(p) == p) { // If there's only one node in list
        FIRST(*l) = NULL;
    } else {
        FIRST(*l) = NEXT(p);
        Address loc = FIRST(*l);
        while (NEXT(loc) != p) { // Moving to the last node of the circular list
            loc = NEXT(loc);
        }
        NEXT(loc) = FIRST(*l); // Readdressing the next of the last node
    }
    deallocate(p);
}

void deleteLast(List *l, ElType *val) {
    Address p = FIRST(*l); // p is for pointing at the soon-to-be-deleted node
    Address loc = NULL;
    while (NEXT(p) != FIRST(*l)) { // Move to the last node
        loc = p;
        p = NEXT(p);
    }
    *val = INFO(p); // Store the value of the last node
    if (loc == NULL) { // If there's only one node in list
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = FIRST(*l); // Readdressing the next of the last node
    }
    deallocate(p);
}

void displayList(List l){
    printf("[");
    Address p = FIRST(l);
    while (NEXT(p)!=FIRST(l)){
        printf("%d,", INFO(p));
        p = NEXT(p);
    }
    if (p != NULL){
        printf("%d", INFO(p));
    }
    printf("]");
}