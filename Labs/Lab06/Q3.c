#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    int inDeg;
    int outDeg;
    struct node** adjList; 
} node;

typedef struct queue{
    int front, rear, size;
    unsigned capacity;
    node* array;
} queue;

queue* createQueue(unsigned capacity){
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (node*)malloc(q->capacity * sizeof(node));
    return q;
}

int isFull(queue* q){
    return (q->size == q->capacity);
}

int isEmpty(queue* q){
    return (q->size == 0);
}

void enqueue(queue* q, node item){
    if (isFull(q)){
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size + 1;
    // return q;
}

node dequeue(queue* q){
    if (isEmpty(q)){
        node temp;
        temp.data = -1;
        // temp.visited = -1;
        // temp.time = -1;
        return temp;
    }
    node item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    node** graph;
    graph = (node**)malloc((n + 1) * sizeof(node*));
    for (int i = 1; i <= n; i++) {
        graph[i] = (node*)malloc(sizeof(node));
        graph[i]->data = i;
        graph[i]->inDeg = 0;
        graph[i]->outDeg = 0;
        graph[i]->adjList = NULL; 
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[b]->inDeg++;
        graph[a]->outDeg++;

        graph[a]->adjList = realloc(graph[a]->adjList, graph[a]->outDeg * sizeof(node*));
        graph[a]->adjList[graph[a]->outDeg - 1] = graph[b];
    }

    queue* quwuwu = createQueue(n);

    for (int i = 1; i <= n; i++) {
        if (graph[i]->inDeg == 0) {
            enqueue(quwuwu, *graph[i]);
        }
    }

    int count = 0;

    while(isEmpty(quwuwu) == 0) {
        node temp = dequeue(quwuwu);
        count++;
        for (int i = 0; i < temp.outDeg; i++) {
            temp.adjList[i]->inDeg--;
            if (temp.adjList[i]->inDeg == 0) {
                enqueue(quwuwu, *temp.adjList[i]);
            }
        }
    }

    if (count == n) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }



    return 0;
}
