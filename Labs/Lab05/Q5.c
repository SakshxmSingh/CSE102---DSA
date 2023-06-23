#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coords{
    int x;
    int y;
    char value;
    int visited;
    int dist;
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
        temp.dist = -1;
        return temp;
    }
    coords item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int main(){
    int n;
    scanf("%d", &n);
    coords** arr = (coords**)malloc(n * sizeof(coords*));
    for (int i = 0; i < n; i++){
        arr[i] = (coords*)malloc(n * sizeof(coords));
    }

    queue* quwuwu = createQueue(n*n);

    int treasureCount = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf(" %c", &arr[i][j].value);
            arr[i][j].x = i;
            arr[i][j].y = j;
            arr[i][j].visited = 0;
            arr[i][j].dist = 0;

            if(arr[i][j].value == 'p'){
                arr[i][j].visited = 1;
                arr[i][j].dist = 0;
                enqueue(quwuwu, arr[i][j]);
            }

            if(arr[i][j].value == 't'){
                // arr[i][j].visited = 1;
                treasureCount++;
            }
        }
    }

    coords treasurez[treasureCount];
    int locTres = 0;

    while(isEmpty(quwuwu) == 0 && treasureCount > 0){
        // bfsTreasureHunt(arr, n, quwuwu, treasureCount);
        coords temp = dequeue(quwuwu);
        int x = temp.x;
        int y = temp.y;

        // int locTres = 0;

        // coords treasurez[treasureCount];

        if(x-1 >= 0 && arr[x-1][y].value != '#' && arr[x-1][y].visited == 0){
            arr[x-1][y].visited = 1;
            arr[x-1][y].dist = arr[x][y].dist + 1;

            if(arr[x-1][y].value == 't'){
                treasurez[locTres] = arr[x-1][y];
                locTres++;
                // treasureCount--;
                arr[x-1][y].value = '.';
            }
            enqueue(quwuwu, arr[x-1][y]);
        }

        if(x+1 < n && arr[x+1][y].value != '#' && arr[x+1][y].visited == 0){
            arr[x+1][y].visited = 1;
            arr[x+1][y].dist = arr[x][y].dist + 1;

            if(arr[x+1][y].value == 't'){
                treasurez[locTres] = arr[x+1][y];
                locTres++;
                // treasureCount--;
                arr[x+1][y].value = '.';
            }
            enqueue(quwuwu, arr[x+1][y]);
        }

        if(y-1 >= 0 && arr[x][y-1].value != '#' && arr[x][y-1].visited == 0){
            arr[x][y-1].visited = 1;
            arr[x][y-1].dist = arr[x][y].dist + 1;

            if(arr[x][y-1].value == 't'){
                treasurez[locTres] = arr[x][y-1];
                locTres++;
                // treasureCount--;
                arr[x][y-1].value = '.';
            }
            enqueue(quwuwu, arr[x][y-1]);
        }

        if(y+1 < n && arr[x][y+1].value != '#' && arr[x][y+1].visited == 0){
            arr[x][y+1].visited = 1;
            arr[x][y+1].dist = arr[x][y].dist + 1;

            if(arr[x][y+1].value == 't'){
                treasurez[locTres] = arr[x][y+1];
                locTres++;
                // treasureCount--;
                arr[x][y+1].value = '.';
            }
            enqueue(quwuwu, arr[x][y+1]);
        }

        if(treasureCount == locTres){
            printf("%d\n", arr[x][y].dist + 1);
            break;
        }

    }

    if (treasureCount != locTres){
        printf("-1\n");
    }

    for(int i=0; i<=locTres; i++){
        printf("%d %d %d %d\n", treasurez[i].x, treasurez[i].y, treasurez[i].dist, treasurez[i].visited);
    }


    return 0;
}