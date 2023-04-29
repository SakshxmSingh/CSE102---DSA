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

    // for(int i=0;i<q;i++){
    //     char str[10];
    //     if()

    // }

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
    }
    return 0;
}
