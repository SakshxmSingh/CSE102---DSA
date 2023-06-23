#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    int inDeg;
    int outDeg;
    int color;
    struct node** adjList; 
} node;

void DFS(node* u, int* isBipartite, int currentColor) {
    if (u->adjList == NULL) {
        return;
    }

    u->color = currentColor;
    for (int i = 0; i < u->outDeg; i++) {
        if (u->adjList[i]->color == -1) {
            if (u->color == 0) {
                u->adjList[i]->color = 1;
            } else if (u->color == 1) {
                u->adjList[i]->color = 0;
            }
            DFS(u->adjList[i], isBipartite, abs(currentColor - 1));
        } else if (u->adjList[i]->color == u->color) {
            *isBipartite = 0;
            return;
        }
    }
}



int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    node** graph;
    graph = (node**)malloc((n + 1) * sizeof(node*));
    for (int i = 1; i <= n; i++) {
        graph[i] = (node*)malloc(sizeof(node));
        graph[i]->data = i;
        graph[i]->inDeg = 0;
        graph[i]->outDeg = 0;
        graph[i]->color = -1;
        graph[i]->adjList = NULL; 
    }

    for (int i = 0; i < m; i++) {
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

    // stack* stuck = createStack(n);

    // push(stuck, *graph[1]);

    int isBipartite = 1;

    // graph[1]->color = 0;

    for(int i=1; i<=n; i++){
        if(graph[i]->color==-1 && isBipartite==1){
            DFS(graph[i], &isBipartite, 0);
        }
    }

    if(isBipartite==1){
        printf("YES\n");
    }
    else if(isBipartite==0){
        printf("NO\n");
    }

    return 0;
}
