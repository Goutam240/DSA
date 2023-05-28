#include<stdio.h>
#define ROW 10
#define COL 10

int main()
{
    {
    int i,j;
    int key=1;
     int r,c;
     int matrix[ROW][COL];
     printf("Enter rows and columns for a 2d array\n ");
     scanf("%d%d",&r,&c);
    printf("Enter matrix elements\n");
    for(i=0;i<r;i++)
    {
         for(j=0;j<c;j++)
         {
             scanf("%d",&matrix[i][j]);
         }
    }
     for(i=0;i<r;i++)
    {
         for(j=0;j<c;j++)
         {
             if(matrix[i][j]!=matrix[j][i])
             {
                  key=0;
             }

         }
    }
    if(key==1)
    {
       printf("It is Symmetric ");
    }
    else
    {
        printf("It is not Symmetric ");
    }
    }
    return 0;
}

