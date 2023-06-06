#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int nData;
    struct Node *pNext;
} Node;

void insertAtEnd(int val, Node **pFront){
    Node *pInsertEnd = NULL, *pPoint=NULL;
    pInsertEnd = (Node *)malloc(sizeof(Node));
    pInsertEnd->nData=val;
    pInsertEnd->pNext=NULL;

    if (*pFront==NULL){
        *pFront = pInsertEnd;
    }
    else{
        pPoint = *pFront;
        while (pPoint->pNext != NULL){
            pPoint = pPoint->pNext;}
        pPoint->pNext=pInsertEnd;
    }
}

void reverseList(Node **pFront){
    Node *prev = NULL, *cur = NULL, *next = NULL;
    cur = *pFront;
    while (cur != NULL) {
        next = cur->pNext;
        cur->pNext = prev;
        prev = cur;
        cur = next; }
    *pFront = prev;
}

void printLL(Node *pFront){
    if(pFront==NULL){
        printf("EMPTY\n");
        return;
    }
    Node *pPoint = NULL;
    pPoint = pFront;
    while (pPoint!=NULL){
        printf("%d ",pPoint->nData);
        pPoint = pPoint->pNext;
    }
    printf("\n");

}

int lengthLL(Node *pFront){
    int n = 0;
    while (pFront!=NULL){
        pFront = pFront->pNext;
        n+=1;
    }
    return n;
}

int KthNode(Node *pFront, int k){
    int len = lengthLL(pFront);
    if (k < 1 || k > len) {
        return -1;
    }
    for(int i=0; i<k-1; i++){
        pFront = pFront->pNext;
    }
    return pFront->nData;
}

void deleteKthNode(Node **pFront, int k) {
    int len = lengthLL(*pFront);
    if (k < 1 || k > len) {
        printf("-1\n");
        return;
    }
    Node *prev = NULL;
    Node *cur = *pFront;
    int i = 1;
    while (cur != NULL && i < k) {
        prev = cur;
        cur = cur->pNext;
        i++;
    }
    int val = cur->nData;
    if (prev == NULL) {
        *pFront = cur->pNext;
    } else {
        prev->pNext = cur->pNext;
    }
    free(cur);
}

void AddtoKthNode(Node *pFront, int k, int x){
    int len = lengthLL(pFront);
    if (k < 1 || k > len) {
        printf("-1\n");
        return;
    }
    for(int i=0; i<k-1; i++){
        pFront = pFront->pNext;
    }
    pFront->nData += x;
    return;
}

void SubtoKthNode(Node *pFront, int k, int x){
    int len = lengthLL(pFront);
    if (k < 1 || k > len) {
        printf("-1\n");
        return;
    }
    for(int i=0; i<k-1; i++){
        pFront = pFront->pNext;
    }
    pFront->nData -= x;
    return;
}

void XORoflastKnodes(Node *pFront, int k, int size){
    if (k < 1 || k > size) {
        printf("-1\n");
        return;
    }
    int XOR = 0;
    for(int i=0; i<size-k; i++){
        pFront = pFront->pNext;
    }
    for(int i=0; i<k; i++){
        XOR ^= pFront->nData;
        pFront = pFront->pNext;
    }
    printf("%d\n", XOR);
    return;
}

int main(){
    int n, q;
    scanf("%d %d",&n, &q);

    Node *pStart=NULL;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n;i++){
        insertAtEnd(arr[i], &pStart);
    }

    while(q--) {
        char query[15];
        scanf("%s", query);

        if(strcmp(query, "Reverse") == 0) {
            reverseList(&pStart);
        }
        else if(strcmp(query, "Print") == 0) {
            if(pStart == NULL) {
                printf("EMPTY\n");
            } else {
                printLL(pStart);
            }
        }
        else if(strcmp(query, "Length") == 0) {
            printf("%d\n", lengthLL(pStart));
        }
        else if(strcmp(query, "KthNode") == 0) {
            int k;
            scanf("%d", &k);
            int kthNode = KthNode(pStart, k);
            if(kthNode == -1) {
                printf("-1\n");
            } else {
                printf("%d\n", kthNode);
            }
        }
        else if(strcmp(query, "Delete") == 0) {
            int k;
            scanf("%d", &k);
            deleteKthNode(&pStart, k);
        }
        else if(strcmp(query, "Add") == 0){
            int k, val;
            scanf("%d %d", &k, &val);
            AddtoKthNode(pStart, k, val);
        }
        else if(strcmp(query, "Subtract") == 0){
            int k, val;
            scanf("%d %d", &k, &val);
            SubtoKthNode(pStart, k, val);
        }
        else if(strcmp(query, "Xor") == 0){
            int k;
            scanf("%d", &k);
            XORoflastKnodes(pStart, k, lengthLL(pStart));
        }
    }
    return 0;
}
