#include <stdio.h>
#include <stdlib.h>

typedef struct BTnode{
    char data;
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
        printf ("%c ", pRoot->data);
        InOrderTraversal (pRoot->right);
    }
}

BTnode* createTree(char *arr, int size) {
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

int power(int a, int b){
    int res = 1;
    for (int i=0; i<b; i++){
        res *= a;
    }
    return res;
}

int isPalindrome(char arr[], int size){
    for (int i=0; i<size/2; i++){
        if (arr[i]!=arr[size-i-1]){
            return 0;
        }
    }
    return 1;
}


int main() {
    int n;
    scanf("%d", &n);
    int size = power(2, n+1) - 1;
    char arr[size];

    // Consume the newline character from the previous scanf
    // getchar();

    for (int i = 0; i < size; i++) {
        scanf(" %c", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }

    BTnode* root = createTree(arr, size);

    InOrderTraversal(root);

    return 0;
}
