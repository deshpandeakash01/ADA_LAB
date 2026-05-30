#include <stdio.h>
int queue[100];
int front = 0, rear = -1;
void enqueue(int x) 
{
    queue[++rear] = x;
}
int dequeue() 
{
    return queue[front++];
}
int isEmpty() {
    return front > rear;
}
void topologicalOrder(int A[100][100], int n) {
    int indeg[100] = {0};
    int i, j;
    // Step 1: Calculate indegree of each vertex
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[j][i] == 1) {
                indeg[i]++;
            }
        }
    }
    // Step 2: Enqueue all vertices with indegree 0
    for (i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            enqueue(i);
        }
    }
    // Step 3: Process the queue
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        for (j = 0; j < n; j++) {
            if (A[u][j] == 1) {
                indeg[j]--;
                if (indeg[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }
}
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int A[100][100];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Topological Order: ");
    topologicalOrder(A, n);
    return 0;
}
