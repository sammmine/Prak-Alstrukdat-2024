#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree new = (Address) malloc (sizeof(TreeNode));
    if (new != NULL){
        ROOT(new) = root;
        LEFT(new) = left_tree;
        RIGHT(new) = right_tree;
    }
    return new;
}
void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root,left_tree,right_tree);
}
Address newTreeNode(ElType val){
    Address p = (Address) malloc (sizeof(TreeNode));
    if (p != NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}
void deallocTreeNode (Address p){
    free(p);
}
boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}
boolean isOneElmt (BinTree p){
    if (isTreeEmpty(p)) return false;
    return (RIGHT(p) == NULL && LEFT(p) == NULL);
}
boolean isUnerLeft (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && isTreeEmpty(RIGHT(p)));
}
boolean isUnerRight (BinTree p){
    return (!isTreeEmpty(p) && isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
boolean isBinary (BinTree p){
    return (!isTreeEmpty(p) && !isTreeEmpty(LEFT(p)) && !isTreeEmpty(RIGHT(p)));
}
void printPreorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}
void printTree(BinTree p, int h){
    int i;
    if (!isTreeEmpty(p)){
        printf("%d\n", ROOT(p));
        printTreeNow(LEFT(p),h,h);
        printTreeNow(RIGHT(p),h,h);
    }
}
void printTreeNow(BinTree p, int h, int now){
    if (!isTreeEmpty(p)){
        for (int i = 0; i < now; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        printTreeNow(LEFT(p),h,h+now);
        printTreeNow(RIGHT(p),h,h+now);
    }
}
boolean isEqual(BinTree p1, BinTree p2) {
    if (isTreeEmpty(p1) && isTreeEmpty(p2)) return true;
    if (isTreeEmpty(p1) && !isTreeEmpty(p2)) return false;
    if (!isTreeEmpty(p1) && isTreeEmpty(p2)) return false;

    if (ROOT(p1) != ROOT(p2)) return false;
    return isEqual(LEFT(p1), LEFT(p2)) && isEqual(RIGHT(p1), RIGHT(p2));
}
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int getMaximumDepth(BinTree p) {
    int left;
    if (isTreeEmpty(LEFT(p))) left = 1;
    else left = 1 + getMaximumDepth(LEFT(p));

    int right;
    if (isTreeEmpty(RIGHT(p))) right = 1;
    else right = 1 + getMaximumDepth(RIGHT(p));

    return max(left, right);
}
BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start, ElType end) {
    if (start > end) {
        return NULL;
    }
    int mid = (start + end) / 2;

    BinTree left = createBinSearchTreeFromSortedArray(arr, start, mid-1);
    BinTree right = createBinSearchTreeFromSortedArray(arr, mid+1, end);
    BinTree rootNow = NewTree(arr[mid], left, right);

    return rootNow;
}
int countNodes(BinTree p) {
    if (p == NULL) return 0;

    return 1 + countNodes(LEFT(p)) + countNodes(RIGHT(p));
}
boolean searchTarget(BinTree p, ElType target) {
    if (p == NULL) return false;
    if (ROOT(p) == target) return true;
    else {
        boolean found = 0;
        if (LEFT(p) != NULL) found |= searchTarget(LEFT(p), target);
        if (RIGHT(p) != NULL) found |= searchTarget(RIGHT(p), target);

        return found;
    }
}
void printPathToElement(BinTree p, ElType target) {
    if (!searchTarget(p, target)) {
        printf("-1\n");
        return;
    }

    if (ROOT(p) == target) {
        printf("%d\n", ROOT(p));
        return;
    }
    else {
        if (searchTarget(LEFT(p), target)) {
            printf("%d -> ", ROOT(p));
            printPathToElement(LEFT(p), target);
        } 
        else {
            printf("%d -> ", ROOT(p));
            printPathToElement(RIGHT(p), target);
        }
    }
}