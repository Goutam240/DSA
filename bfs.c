#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int node;
    int i,n,j,m;
    int x,y,e;
    int a[100][100];
    printf("Enter no of Vertices\n");
    scanf("%d",&n);
    printf("Enter number of edges\n");
    scanf("%d",&e);

    int visited[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    printf("Enter connected edges\n");
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the vertex\n");
    scanf("%d",&m);
    visited[m] = 1;
    enqueue(&q, m);
    printf("The BFS is :\n");
    printf("%d",m);
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j <n; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
