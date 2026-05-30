#include <stdio.h>
#define INF 999
void dijkstra(int n, int cost[][100], int src) {
    int dis[100], vis[100];
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        vis[i] = 0;
    }
    dis[src] = 0;
    for (int i = 0; i < n; i++) {
        int min = INF, u = -1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) {
            break;
        }
        vis[u] = 1;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && cost[u][j] != INF && dis[u] + cost[u][j] < dis[j]) {
                dis[j] = dis[u] + cost[u][j];
            }
        }
    }
    printf("\nShortest paths from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dis[i] == INF) {
            printf("%d -> %d = INF\n", src, i);
        } else {
            printf("%d -> %d = %d\n", src, i, dis[i]);
        }
    }
}
int main() {
    int src, n, cost[100][100];
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Enter the source vertex:\n");
    scanf("%d", &src);
    dijkstra(n, cost, src);
}