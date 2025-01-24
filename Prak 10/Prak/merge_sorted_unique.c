#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

void mergeSortedUnique(List l1, List l2, List *res) {
    if (isEmpty(l1) && isEmpty(l2)) return;
    else {
        if (isEmpty(l1)) {
            if (!isMember(*res, head(l2))) *res = konsb(*res, head(l2));
            mergeSortedUnique(l1, tail(l2), res);
        }
        else if (isEmpty(l2)) {
            if (!isMember(*res, head(l1))) *res = konsb(*res, head(l1));
            mergeSortedUnique(tail(l1), l2, res);
        }
        else {
            if (head(l1) < head(l2)) {
                if (!isMember(*res, head(l1))) *res = konsb(*res, head(l1));
                mergeSortedUnique(tail(l1), l2, res);
            }
            else {
                if (!isMember(*res, head(l2))) *res = konsb(*res, head(l2));
                mergeSortedUnique(l1, tail(l2), res);
            }
        }
    }    
}