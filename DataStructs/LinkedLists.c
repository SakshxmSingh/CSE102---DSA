#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int nData;
    struct Node *pNext;
} Node;

void insertAfterPos(int val , int pos, Node *pFront) {
    Node *pTemp = NULL;
    int nIter = 1; // Position of first node is assumed 1.
    pTemp = (Node *)malloc(sizeof(Node));
    pTemp->nData = val;
    pTemp->pNext = NULL;
    while (pFront != NULL) {
        if (nIter == pos) {
            if (pFront->pNext == NULL) {
                pFront->pNext = pTemp;
                break;
            }
            else {
                pTemp->pNext = pFront->pNext;
                pFront->pNext = pTemp;
                break;
            }
        }
    pFront = pFront->pNext;
    nIter++;
    }
}

void insertAtEnd(int val, Node *pFront){
    Node *pInsertEnd = NULL, *pPoint=NULL;
    pInsertEnd = (Node *)malloc(sizeof(Node));
    pInsertEnd->nData=val;
    pInsertEnd->pNext=NULL;

    if (pFront==NULL){
        pFront = pInsertEnd;
    }
    else{
        pPoint = pFront;
        while (pPoint->pNext != NULL){
            pPoint = pPoint->pNext;}
        pPoint->pNext=pInsertEnd;
    }
}

void printLL(Node *pFront){
    Node *pPoint = NULL;
    pPoint = pFront;
    while (pPoint->pNext!=NULL){
        printf("%d ",pPoint->nData);
        pPoint = pPoint->pNext;
    }
    printf("%d\n",pPoint->nData);

}

void deleteFront(Node *pFront){
    Node *pTemp = NULL;
    if (pFront == NULL){
        return;
    }
    else {
        pTemp = pFront;
        pFront = pFront->pNext;
        free(pTemp);
    }
}

void deleteLast(Node *pFront){
    if (pFront == NULL){
        return;
    }
    if (pFront->pNext == NULL) {
        Node *pTemp = pFront;
        pFront = NULL;
        free(pTemp);
        return;
    }
    Node *pPrev = NULL, *pCur = NULL;
    pPrev = pFront;
    pCur = pFront->pNext;
    while (pCur->pNext != NULL) {
        pPrev = pCur;
        pCur = pCur->pNext; }
    pPrev->pNext = NULL;
    free(pCur);
}

void deleteData(int val, Node *pFront){
    Node *pPrev = NULL, *pCur = NULL;
    pPrev = pFront;
    pCur = pFront->pNext;
    while (pCur->nData != val){
        pPrev = pCur;
        pCur = pCur->pNext; 
        }
    pPrev->pNext = pCur->pNext;
    free(pCur);
}

int main(){

    //creating nodes
    Node *pNode1 = NULL;
    pNode1 = (Node *)malloc(sizeof(Node));
    pNode1->nData=50;
    pNode1->pNext=NULL;

    Node *pNode2 = NULL;
    pNode2 = (Node *)malloc(sizeof(Node));
    pNode2->nData=30;
    pNode2->pNext=NULL;


    //conecting nodes
    Node *pFront = NULL;
    pFront = pNode1;
    pFront->pNext=pNode2;


    // inserting a node in front
    Node* pInsertFront = NULL;
    pInsertFront = (Node *)malloc(sizeof(Node));
    pInsertFront->nData=82;
    pInsertFront->pNext=NULL;
    if (pFront == NULL){
        pFront = pInsertFront;
    }
    else{
        pInsertFront->pNext=pFront;
        pFront=pInsertFront;
    }

    //insert at end
    insertAtEnd(500, pFront);
    insertAtEnd(52, pFront);
    insertAtEnd(69, pFront);
    insertAtEnd(434, pFront);
    insertAtEnd(420, pFront);
    insertAtEnd(500, pFront);
    insertAtEnd(600, pFront);
    insertAtEnd(720, pFront);

    //inserting a node in between
    insertAfterPos(39,2,pFront);
    insertAfterPos(45,2,pFront);

    //deleting the first node
    Node *pTemp = NULL;
    if (pFront == NULL){}
    else {
        pTemp = pFront;
        pFront = pFront->pNext;
        free(pTemp);
    }

    //deleting the last node
    deleteLast(pFront);

    //deleting a specific data node
    deleteData(434,pFront);

    //printing the linked list
    printLL(pFront);

    // char str[] = "kaju op";

    return 0;
}
