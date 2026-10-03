#include <stdio.h>
#include <stdlib.h>

#define INF 2e9 // Representing infinity

typedef struct {
    int u, v, w;
} Edge;

void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent, parent[v]);
    printf("->%d", v);
}

int main() {
    int V, E;
    if (scanf("%d %d", &V, &E) != 2) return 0;

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int *dist = (int *)malloc((V + 1) * sizeof(int));
    int *parent = (int *)malloc((V + 1) * sizeof(int));

    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
