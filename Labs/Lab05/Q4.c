#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coords{
    int x;
    int y;
    int value;
    int visited;
    int time;
}coords;

typedef struct queue{
    int front, rear, size;
    unsigned capacity;
    coords* array;
} queue;

queue* createQueue(unsigned capacity){
    queue* q = (queue*)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->array = (coords*)malloc(q->capacity * sizeof(coords));
    return q;
}

int isFull(queue* q){
    return (q->size == q->capacity);
}

int isEmpty(queue* q){
    return (q->size == 0);
}

void enqueue(queue* q, coords item){
    if (isFull(q)){
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size + 1;
    // return q;
}

coords dequeue(queue* q){
    if (isEmpty(q)){
        coords temp;
        temp.x = -1;
        temp.y = -1;
        temp.value = -1;
        temp.visited = -1;
        temp.time = -1;
        return temp;
    }
    coords item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

void BFS(coords **arr, int m, int n, queue* q){
    coords temp = dequeue(q);
    int x = temp.x;
    int y = temp.y;
    if (x-1 >= 0 && arr[x-1][y].value == 0 && arr[x-1][y].visited == 0){
        arr[x-1][y].visited = 1;
        arr[x-1][y].time = arr[x][y].time + 1;
        enqueue(q, arr[x-1][y]);
    }
    if (x+1 < m && arr[x+1][y].value == 0 && arr[x+1][y].visited == 0){
        arr[x+1][y].visited = 1;
        arr[x+1][y].time = arr[x][y].time + 1;
        enqueue(q, arr[x+1][y]);
    }
    if (y-1 >= 0 && arr[x][y-1].value == 0 && arr[x][y-1].visited == 0){
        arr[x][y-1].visited = 1;
        arr[x][y-1].time = arr[x][y].time + 1;
        enqueue(q, arr[x][y-1]);
    }
    if (y+1 < n && arr[x][y+1].value == 0 && arr[x][y+1].visited == 0){
        arr[x][y+1].visited = 1;
        arr[x][y+1].time = arr[x][y].time + 1;
        enqueue(q, arr[x][y+1]);
    }
    return;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    // coords* visited_arr = (coords*)malloc(sizeof(coords) * m * n);

    // coords arr[m][n];
    coords** arr = (coords**)malloc(sizeof(coords*) * m);
    for(int i=0; i<m; i++){
        arr[i] = (coords*)malloc(sizeof(coords) * n);
    }

    // int vis_index = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &(arr[i][j].value));
            arr[i][j].x = i;
            arr[i][j].y = j;
            arr[i][j].visited = 0;
            arr[i][j].time = 0;
        }
    }

    queue* quwuwu = createQueue(m*n);

    for(int i=0; i<m; i++){
        if (i==0 || i==m-1){
            for(int j=0; j<n; j++){
                if(arr[i][j].value == 0){
                    arr[i][j].visited = 1;
                    arr[i][j].time = 1;
                    enqueue(quwuwu, arr[i][j]);
                }
            }
        }
        else{
            if(arr[i][0].value == 0){
                arr[i][0].visited = 1;
                arr[i][0].time = 1;
                enqueue(quwuwu, arr[i][0]);
            }
            if(arr[i][n-1].value == 0){
                arr[i][n-1].visited = 1;
                arr[i][n-1].time = 1;
                enqueue(quwuwu, arr[i][n-1]);
            }
        }
    }
    while(isEmpty(quwuwu)!=1){
        BFS(arr, m, n, quwuwu);
    }

    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if (arr[x][y].value == 0 && arr[x][y].time != 0){
            printf("%d\n", arr[x][y].time);
        }
        else if (arr[x][y].value == 1 || arr[x][y].time == 0){
            printf("infinity\n");
        }
    }
    return 0;
}