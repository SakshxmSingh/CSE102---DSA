#include <stdio.h>
#include <stdlib.h>

typedef struct BTnode{
    int data;
    struct BTnode *left;
    struct BTnode *right;
} BTnode;

typedef struct Queue{
    BTnode **items;
    int front;
    int rear;
    int size;
} Queue;

Queue* CreateQueue(int size){
    Queue* quwuw = malloc(sizeof(Queue));
    quwuw->items = malloc(sizeof(BTnode*)*size);
    quwuw->front = 0;
    quwuw->rear = -1;
    quwuw->size = size;
    return quwuw;
}

void Enqueue(Queue* queue, BTnode* node){
    if (queue->rear==queue->size-1){
        return;
    }
    else {
        queue->rear++;
        queue->items[queue->rear] = node;
        return;
    }
}

BTnode* Dequeue(Queue* queue){
    BTnode* temp = queue->items[queue->front];
    queue->front++;
    return temp;
}

void InOrderTraversal(BTnode *pRoot){
    if (pRoot!=NULL) {
        InOrderTraversal (pRoot->left);
        printf ("%d ", pRoot->data);
        InOrderTraversal (pRoot->right);
    }
}

BTnode* createTree(int *arr, int size) {
    if (size == 0) {
        return NULL;
    }
    Queue *queue = CreateQueue(size);
    BTnode *root = (BTnode*) malloc(sizeof(BTnode));
    root->data = arr[0];
    root->left = NULL;
    root->right = NULL;
    Enqueue(queue, root);
    int i = 1;
    while (i < size) {
        BTnode *parent = Dequeue(queue);
        int leftVal = arr[i++];
        if (leftVal != -1) {
            BTnode *leftChild = (BTnode*) malloc(sizeof(BTnode));
            leftChild->data = leftVal;
            leftChild->left = NULL;
            leftChild->right = NULL;
            parent->left = leftChild;
            Enqueue(queue, leftChild);
        }
        if (i < size) {
            int rightVal = arr[i++];
            if (rightVal != -1) {
                BTnode *rightChild = (BTnode*) malloc(sizeof(BTnode));
                rightChild->data = rightVal;
                rightChild->left = NULL;
                rightChild->right = NULL;
                parent->right = rightChild;
                Enqueue(queue, rightChild);
            }
        }
    }
    return root;
}

int max(int a, int b) {
    return a>=b ? a : b;
}

int height (BTnode *pRoot) {
    if (pRoot==NULL){
        return 0;}
    else{
        return 1 + max(height(pRoot->left), height (pRoot->right));}
}

int isBalanced(BTnode *pRoot) {
    if (pRoot==NULL){
        return 1;}
    else{
        return (abs(height(pRoot->left)-height(pRoot->right))<=1 && isBalanced(pRoot->left) && isBalanced(pRoot->right));}

    return 0;
}

int main(){

    int n;
    scanf("%d",&n);
    int arr[2*n+1];
    for (int i=0; i<2*n+1; i++){
        scanf("%d",&arr[i]);
    }

    BTnode* root = createTree(arr,2*n+1);

    // InOrderTraversal(root);

    if (isBalanced(root)==1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }


    return 0;
}