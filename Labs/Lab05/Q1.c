#include <stdio.h>
#include <stdlib.h>

typedef struct city{
    int num;
    int visited;
    // int time;
    int sol;
    struct city* next;   
}city;

typedef struct graph{
    int numVertices;
    struct city** adjLists;
} graph;

city *createCity(int num){
    city *newCity = (city*)malloc(sizeof(city));
    newCity->num = num;
    newCity->visited = 0;
    // newCity->time = 0;
    newCity->sol = 0;
    newCity->next = NULL;
    return newCity;
}

graph *createGraph(int vertices){
    graph *newGraph = (graph*)malloc(sizeof(graph));
    newGraph->numVertices = vertices;
    newGraph->adjLists = (city**)malloc(vertices * sizeof(city*));
    for(int i=1; i<=vertices; i++){
        newGraph->adjLists[i] = NULL;
    }
    return newGraph;
}

void addEdge(graph *graph, int src, int dest){
    city *newCity = createCity(dest);
    newCity->next = graph->adjLists[src];
    graph->adjLists[src] = newCity;
}

void printGraph(graph* graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        city* temp = graph->adjLists[i];
        printf("Adjacency list of vertex %d: ", i);
        while (temp) {
            printf("%d (sol: %d, visited: %d) -> ", temp->num, temp->sol, temp->visited);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    // for(int i=0; i<n; i++){
    //     scanf("%d", &(arr[i]->sol));
    //     arr[i]->num = i;
    // }

    graph *graph = createGraph(n);

    int sols[n];
    for(int i=0; i<n; i++){
        scanf("%d", &sols[i]);    
    }

    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addEdge(graph, a, b);
    }

    for(int i=0; i<n; i++){
        city *temp = graph->adjLists[i];
        while(temp){
            temp->sol = sols[i];
            temp = temp->next;
        }
    }


    printGraph(graph);


    return 0;
}