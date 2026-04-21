#include<stdio.h>
void FloydWarshal(int V,int graph[V][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j) dist[i][j]=0;
            else if(dist[i][j]!=999) dist[i][j]=graph[i][j];
            else dist[i][j]=999;
        }
    }
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][k]!=999&&dist[k][j]!=999)
                {
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j]==999) printf("%7s", "INF");
            else printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int V;
    printf("Enter number of vertices : ");
    scanf("%d",&V);
    printf("\n Enter adjecency matrix : \n"); 
    int graph[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            printf("G[%d][%d] = ",i,j);
            scanf("%d",&graph[i][j]);
        }
    }
    FloydWarshal(V,graph);
}
