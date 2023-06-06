#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTNode {
    int nData;
    struct Node *pParent;
    struct Node *pLeft;
    struct Node *pRight;
} BTNode;

int max(int a, int b) {
    return a>=b ? a : b;
}

int min(int a, int b) {
    return a<=b ? a : b;
}

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
        printf ("%d ", pRoot->nData);
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

int diameter (BTNode *pRoot) {
    if (pRoot==NULL){
        return 0;}
    else{
        return max(height(pRoot->pLeft)+height(pRoot->pRight)+1, max(diameter(pRoot->pLeft), diameter(pRoot->pRight)));}
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

int TreeMaxBT(BTNode *pRoot) {
    if (pRoot==NULL){
        BTNode* par = pRoot->pParent;
        return par->nData;
    }
    return max(TreeMaxBT(pRoot->pLeft), TreeMaxBT(pRoot->pRight));
}

int TreeMinBT(BTNode *pRoot) {
    if (pRoot==NULL){
        BTNode* par = pRoot->pParent;
        return par->nData;
    }
    return min(TreeMinBT(pRoot->pLeft), TreeMinBT(pRoot->pRight));
}

BTNode* TreeMinBST(BTNode *pRoot) {
    while (pRoot==NULL){
        pRoot=pRoot->pLeft;
    }
    return pRoot;
}

BTNode* TreeMaxBST(BTNode *pRoot) {
    while (pRoot==NULL){
        pRoot=pRoot->pRight;
    }
    return pRoot;
}

BTNode* Search(BTNode *pRoot, int key) {
    if (pRoot==NULL) printf("Key doesnt exist"); return NULL;
    if (pRoot->nData==key) return pRoot;
    else if (pRoot->nData<key) Search(pRoot->pRight, key);
    else Search(pRoot->pLeft, key);
}

BTNode* SuccBST(BTNode *pRoot) {
    if (pRoot->pRight!=NULL){
        return TreeMinBST(pRoot->pRight);
    }
    BTNode* par = NULL;
    par = pRoot->pParent;
    while (par->pRight=pRoot){
        if (par==NULL) break;
        pRoot = par;
        par = par->pParent;
    }
    return par;
}

BTNode* PredBST(BTNode *pRoot) {
    if (pRoot->pLeft!=NULL){
        return TreeMaxBST(pRoot->pLeft);
    }
    BTNode* par = NULL;
    par = pRoot->pParent;
    while (par->pLeft=pRoot){
        if (par==NULL) break;
        pRoot = par;
        par = par->pParent;
    }
    return par;
}

BTNode* InsertBSTRecur(BTNode* pRoot, int value) {
    if (pRoot==NULL){
        pRoot = malloc(sizeof(BTNode));
        pRoot->pLeft = NULL, pRoot->pRight = NULL;
        pRoot->nData = value;
        // return NULL;
    }
    if (pRoot->nData > value) {
        pRoot = InsertBSTRecur(pRoot->pLeft, value);
    }
    else pRoot = InsertBSTRecur(pRoot->pRight, value);
    return pRoot;
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

BTNode* Delete(BTNode* pRoot, int value) {

    BTNode* to_be_deleted = Search(pRoot, value);
    if(to_be_deleted==NULL){
        printf("Key doesnt exist");
        return NULL;
    }

    BTNode* y = malloc(sizeof(BTNode));

    if(to_be_deleted->pLeft==NULL || to_be_deleted->pRight==NULL){
        y = to_be_deleted;
    }
    else pRoot = SuccBST(y);

    BTNode* x = malloc(sizeof(BTNode));

    if (y->pLeft != NULL){
        x = y->pLeft;
    }
    else x = y->pRight;

    if(x!=NULL){
        x->pParent = y->pParent;
    }

    BTNode* yPar = malloc(sizeof(BTNode));
    yPar = y->pParent;

    if(y->pParent==NULL){
        pRoot = x;
    }
    else if(y==yPar->pLeft){
        yPar->pLeft = x;
    }
    else yPar->pRight = x;

    if(y!=to_be_deleted){
        to_be_deleted->nData = y->nData;
    }

    return pRoot;
}

int main(){
    //MAKING A RANDOM BINARY TREE
    {BTNode *BT = malloc(sizeof(BTNode));
    BT->nData=15;
    BTNode *BTL1 = malloc(sizeof(BTNode));
    BTL1->nData=13;
    BTNode *BTL2 = malloc(sizeof(BTNode));
    BTL2->nData=8;
    BTNode *BTL3 = malloc(sizeof(BTNode));
    BTL3->nData=9;
    BTNode *BTL4 = malloc(sizeof(BTNode));
    BTL4->nData=33;
    BTNode *BTL5 = malloc(sizeof(BTNode));
    BTL5->nData=69;
    BTNode *BTL6 = malloc(sizeof(BTNode));
    BTL6->nData=120;
    BTNode *BTR1 = malloc(sizeof(BTNode));
    BTR1->nData=18;
    BTNode *BTR2 = malloc(sizeof(BTNode));
    BTR2->nData=12;
    BTNode *BTR3 = malloc(sizeof(BTNode));
    BTR3->nData=5;
    BTNode *BTR4 = malloc(sizeof(BTNode));
    BTR4->nData=6;
    BTNode *BTR5 = malloc(sizeof(BTNode));
    BTR5->nData=34;

    BT->pLeft=BTL1, BT->pRight=BTR1, BT->pParent=NULL;
    BTL1->pLeft=BTL2, BTL1->pRight=BTR2, BTL1->pParent=BT;
    BTL2->pLeft=BTL3, BTL2->pRight=BTR3, BTL2->pParent=BTL1;
    BTL3->pLeft=NULL, BTL3->pRight=NULL, BTL3->pParent=BTL2;
    BTR3->pLeft=NULL, BTR3->pRight=BTR4, BT->pParent=BTL2;
    BTR4->pLeft=NULL, BTR4->pRight=NULL, BTR4->pParent=BTR3;
    BTR2->pLeft=NULL, BTR2->pRight=NULL, BTR2->pParent=BTL1;
    BTR1->pLeft=BTL4, BTR1->pRight=BTR5, BTR1->pParent=BT;
    BTL4->pLeft=NULL, BTL4->pRight=NULL, BTL4->pParent=BTR1;
    BTR5->pLeft=BTL5, BTR5->pRight=NULL, BTR5->pParent=BTR1;
    BTL5->pLeft=BTL6, BTL5->pRight=NULL, BTL5->pParent=BTR5;
    BTL6->pLeft=NULL, BTL6->pRight=NULL, BTL6->pParent=BTL5;
    }


    //MAKING A BINARY SEARCH TREE
    {BTNode *BST = malloc(sizeof(BTNode));
    BST->pLeft=BST->pRight=BST->pParent=NULL;
    BST->nData=15;
    

    }




    



    return 0;
}