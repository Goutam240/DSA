#include<stdio.H>
#include<stdlib.h>
#define v 6
#define INF 999
struct EDGE
{
    int s,d,w;
};
typedef struct EDGE edge;

int A[v];

int min_index(int d[v],int vis[v])
{
    int i,min=INF,minindex;
    for(i=0;i<v;i++)
    {
        if(!vis[i]&&d[i]<min)
        {
            min=d[i];
            minindex=i;
        }
    }
    return minindex;
}
void dijkstra(int source,int G[v][v])
{
    int vis[v],d[v],i,j,min;
    for(i=0;i<v;i++)
    {
        vis[i]=0;
        d[i]=INF;
    }
    d[source]=0;
    for(i=0;i<v;i++)
    {
        min=min_index(d,vis);
        vis[min]=1;
        for(j=0;j<v;j++)
        {
            if(!vis[j]&&d[min]!=INF&&G[min][j]&&d[min]+G[min][j]<d[j])
            {
                d[j]=d[min]+G[min][j];
            }
        }
    }
    printf("Distance From source %d to all cities\n",source);
    for(i=0;i<v;i++)
    {
        printf("%d-%d\n",i,d[i]);
    }
}

int main()
{
    int graph[v][v],e,i,j,source;
    printf("No of edges\n");
    scanf("%d",&e);
    edge E[e];
    for(i=0;i<v;i++)
        A[i]=i;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
            graph[i][j]=0;
            else
                graph[i][j]=INF;
        }
    }
    printf("Enter source,destination and weights of %d edges\n",e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d%d",&E[i].s,&E[i].d,&E[i].w);
        graph[E[i].s][E[i].d]=E[i].w;
        graph[E[i].d][E[i].s]=E[i].w;
    }
    //display_G(graph);
    while(1)
    {
        printf("\n1.shortest path from 1 source to all the cities\n2.Exit\n");
        int ch;
        printf("\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
          /*  case 0:display_G(graph);
            break;
            case 1:display_edges(e,E);
            break;*/
            case 1:printf("Enter source\n");
                   scanf("%d",&source);
                   dijkstra(source,graph);
            break;
            case 2:exit(0);
            break;
            default: printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}
/*

INPUT

6
0 1 10
1 2 9
5 0 12
2 3 11
3 4 8
4 5 6




*/
