#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ops{
    char op[20];
    int k;
} ops;

typedef struct quwuw{
    int front, rear, size;
    unsigned capacity;
    int* arr;
} quwuw;

void Push(quwuw *stack, int ele){
    stack=(quwuw*)realloc(stack, sizeof(stack)+sizeof(quwuw));
    // stack[0]->arr
    return;
}
int Pop(int **stack){
    return 0;
}
void Enqueue(int stack[][100], int ele){
    return;
}
int Dequeue(int stack[][100]){
    return 0;
}
int MaxSumPairs(int stack[][100], int ele){
    return 0;
}
 
int main(){
    int S[100][100], n;
    ops ops_arr[n]; 

    quwuw *Stack = (quwuw*)malloc(sizeof(quwuw));
    // Stack[0] = (int*)malloc(sizeof(int));

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", &ops_arr[i].op);
        if (strcmp(ops_arr[i].op, "Push")==0 || strcmp(ops_arr[i].op, "Enqueue")==0 || strcmp(ops_arr[i].op, "MaxSumPairs")==0){
            scanf("%d", &ops_arr[i].k);
        }
        else ops_arr[i].k = 0;
    }
    // for(int i=0; i<n; i++){
    //     printf("%s %d\n", ops_arr[i].op, ops_arr[i].k);
    // }

    for(int i=0; i<n; i++){
        if(strcmp(ops_arr[i].op, "Push")==0) Push(S,ops_arr[i].k);
        else if(strcmp(ops_arr[i].op, "Enqueue")==0) Enqueue(S,ops_arr[i].k);
        else if(strcmp(ops_arr[i].op, "MaxSumPairs")==0) MaxSumPairs(S,ops_arr[i].k);
        else if(strcmp(ops_arr[i].op, "Pop")==0) Pop(S);
        else if(strcmp(ops_arr[i].op, "Dequeue")==0) Dequeue(S);
    }

    return 0;
}