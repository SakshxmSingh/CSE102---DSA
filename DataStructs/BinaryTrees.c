#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    int nData;
    struct Node *pParent;
    struct Node *pLeft;
    struct Node *pRight;
} BTNode;

void PreOrderTraversal(BTNode *pRoot){
    if (pRoot!=NULL) {
        printf ("%d", pRoot->nData);
        PreOrderTraversal (pRoot->pLeft);
        PreOrderTraversal (pRoot->pRight);
    }
}

void InOrderTraversal(BTNode *pRoot){
    if (pRoot!=NULL) {
        InOrderTraversal (pRoot->pLeft);
        printf ("%d", pRoot->nData);
        InOrderTraversal (pRoot->pRight);
    }
}

void PostOrderTraversal(BTNode *pRoot){
    if (pRoot!=NULL) {
        PostOrderTraversal (pRoot->pLeft);
        PostOrderTraversal (pRoot->pRight);
        printf ("%d", pRoot->nData);
    }
}

int count (BTNode *pRoot) {
    if (pRoot==NULL){
        return 0;}
    else{
        return 1 + count(pRoot->pLeft) + count(pRoot->pRight);
    }
}

int height (BTNode *pRoot) {
    if (pRoot==NULL){
        return 0;}
    else{
        return 1 + max(height(pRoot->pLeft), height (pRoot->pRight));}
}

BTNode* Copy(BTNode *pRoot) {
    if (pRoot == NULL) {
        return NULL;
    }
    BTNode *copy = NULL;
    copy = (BTNode *)malloc(sizeof(BTNode));
    copy->nData = pRoot->nData;
    copy->pLeft = Copy(pRoot->pLeft);
    copy->pRight = Copy(pRoot->pRight);
    return copy;
}

int main(){
    BTNode *pRoot = NULL;
    



    return 0;
}