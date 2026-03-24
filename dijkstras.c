#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void dijkstra(int n,int cost[][100],int src)
{
    int dis[100],vis[100],u;
    for(int i=1;i<=n;i++)
    {
        dis[i]=cost[src][i];
        vis[i]=0;
    }
    dis[src]=0;
    vis[src]=1;
    for(int i=1;i<=n;i++)
    {
        int min=999;
        u=-1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0&&dis[j]<min)
            {
                min=dis[j];
                u=j;
            }
        }
        vis[u]=1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==0&&(dis[u]+cost[u][j]<dis[j]))
            {
                dis[j]=dis[u]+cost[u][j];
            }
        }
    }
    printf("Shortest paths from vertex %d:\n", src);
    for (int i = 1; i <= n; i++) {
        if (dis[i]==999)
            printf("%d -> %d = INF\n",src,i);
        else
            printf("%d -> %d = %d\n",src,i,dis[i]);
    }
}
int main()
{
    int src,j,cost[100][100],n,i;
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("enter the cost adjacency matrix\n");
    for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
	  scanf("%d",&cost[i][j]);
    printf("enter the source vertex\n");
    scanf("%d",&src);
    dijkstra(n,cost,src);
}