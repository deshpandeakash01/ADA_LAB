#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};
struct subset {
    int parent;
    int rank;
};
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int myComp(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    int totalCost = 0;
    printf("\nEdge \tWeight\n");
    for (i = 0; i < e; ++i) {
        printf("%d-%d\t%d \n", result[i].src, result[i].dest, result[i].weight);
        totalCost += result[i].weight;
    }
    printf("Total Minimum Cost: %d\n", totalCost);
    
    free(subsets);
}
int main() {
    int V, E;
    
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("\nEnter edges in the format: Source Destination Weight\n");
    printf("(Note: Vertices should be numbered from 0 to %d)\n", V - 1);
    for(int i = 0; i < E; i++) {
        int u, v, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        if (u >= 0 && u < V && v >= 0 && v < V) {
            graph->edge[i].src = u;
            graph->edge[i].dest = v;
            graph->edge[i].weight = weight;
        } else {
            printf("Invalid vertices! Please enter values between 0 and %d.\n", V - 1);
            i--;
        }
    }
    printf("\nCalculating Kruskal's Minimum Spanning Tree...\n");
    KruskalMST(graph);
    free(graph->edge);
    free(graph);
    return 0;
}