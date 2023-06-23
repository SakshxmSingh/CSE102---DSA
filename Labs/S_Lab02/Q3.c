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
        printf ("%d ", pRoot->nData);
        PreOrderTraversal (pRoot->pLeft);
        PreOrderTraversal (pRoot->pRight);
    }
}


// BTNode* InsertBSTRecur(BTNode* pRoot, int value) {
//     if (pRoot==NULL){
//         pRoot = malloc(sizeof(BTNode));
//         pRoot->pLeft = NULL, pRoot->pRight = NULL;
//         pRoot->nData = value;
//         // return NULL;
//     }
//     if (pRoot->nData > value) {
//         pRoot = InsertBSTRecur(pRoot->pLeft, value);
//     }
//     else pRoot = InsertBSTRecur(pRoot->pRight, value);
//     return pRoot;
// }

BTNode* InsertBSTRecur(BTNode** ppRoot, int value) {
    if (*ppRoot == NULL) {
        *ppRoot = malloc(sizeof(BTNode));
        (*ppRoot)->pLeft = NULL;
        (*ppRoot)->pRight = NULL;
        (*ppRoot)->nData = value;
        (*ppRoot)->pParent = NULL;
    } else if ((*ppRoot)->nData > value) {
        (*ppRoot)->pLeft = InsertBSTRecur(&((*ppRoot)->pLeft), value);
        // (*ppRoot)->pLeft->pParent = *ppRoot;
    } else {
        (*ppRoot)->pRight = InsertBSTRecur(&((*ppRoot)->pRight), value);
        // (*ppRoot)->pRight->pParent = *ppRoot;
    }
    return *ppRoot;
}


void InsertBSTIter(BTNode* pRoot, int value) {
    BTNode* par = NULL;
    while (pRoot!=NULL){
        if (pRoot->nData>value){
            pRoot=pRoot->pLeft;
        }
        else pRoot = pRoot->pRight;
        par = pRoot->pParent;
    }
    if (pRoot==NULL){
        pRoot = malloc(sizeof(BTNode));
        pRoot->pLeft = NULL, pRoot->pRight = NULL;
        pRoot->nData = value;
        pRoot->pParent=par;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    BTNode *pRoot = malloc(sizeof(BTNode));
    pRoot->pLeft = NULL, pRoot->pRight = NULL;
    pRoot->nData = arr[0];
    for (int i=1; i<n; i++) {
        pRoot = InsertBSTRecur(&pRoot, arr[i]);
    }

    PreOrderTraversal(pRoot);

    return 0;
}