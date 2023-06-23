#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

typedef struct node {
    int data;
    int inDeg;
    int outDeg;
    int visited;
    struct node** adjList; 
} node;

int linearSearch(int* arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return MAX;
}


int DFS(int *start, int end, node** graph, int* path, int* pathIndex) {
    if (*start == end) {
        return 1;
    }

    graph[*start]->visited = 1;
    path[*pathIndex] = start;
    *pathIndex = *pathIndex + 1;
    for (int i = 0; i < graph[*start]->outDeg; i++) {
        if (graph[*start]->adjList[i]->visited == 0) {
            *start = graph[*start]->adjList[i]->data;
            if (*start == 1 == end){
                return 1;
            }
            else if(*start == 1){
                return 0;
            }
            if (DFS(start, end, graph, path, pathIndex)) {
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    int n;
    scanf("%d", &n);

    node** graph;
    graph = (node**)malloc((n + 1) * sizeof(node*));
    for (int i = 1; i <= n; i++) {
        graph[i] = (node*)malloc(sizeof(node));
        graph[i]->data = i;
        graph[i]->inDeg = 0;
        graph[i]->outDeg = 0;
        graph[i]->visited = 0;
        graph[i]->adjList = NULL; 
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[b]->inDeg++;
        graph[b]->outDeg++;
        graph[a]->inDeg++;
        graph[a]->outDeg++;

        graph[a]->adjList = realloc(graph[a]->adjList, graph[a]->outDeg * sizeof(node*));
        graph[b]->adjList = realloc(graph[b]->adjList, graph[b]->outDeg * sizeof(node*));
        graph[a]->adjList[graph[a]->outDeg - 1] = graph[b];
        graph[b]->adjList[graph[b]->outDeg - 1] = graph[a];
    }

    int q;
    scanf("%d", &q);

    while(q--){
        int x, y;
        char query[10];
        scanf("%s %d %d", query, &x, &y);
        if(strcmp(query, "towards")==0){
            int* path = (int*)malloc(n * sizeof(int));
            int pathIndex = 0;
            int start = x;
            if(DFS(&x, y, graph, path, &pathIndex)==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }

        else if(strcmp(query, "away")==0){

        }
        
        

        

    }




    return 0;
}