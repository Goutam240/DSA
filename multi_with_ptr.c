#include<stdio.h>
#include<stdlib.h>
#define row 3
#define col 3

void read(int mat[row][col])
{
   int i,j;
   for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
       {
           scanf("%d",(*(mat+i)+j));
       }
   }
}

void display(int mat[row][col])
{
     int i,j;
   for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
       {
           printf("%d",*(*(mat+i)+j));
       }
       printf("\n");
   }
}

void mult(int mat1[row][col],int mat2[row][col])
{
   int i,j,k,sum=0,res[row][col];
   for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
       {
          for(k=0;k<col;k++)
           {
             sum=sum+((*(*(mat1+i)+k)) * (*(*(mat2+k)+j)));
           }
           printf("%d\t",sum);
           *(*(res+i)+j)=sum;
           sum=0;
       }
   }
   printf("\n");
}

void main()
{
    int mat1[row][col],mat2[row][col];
    printf("enter the elements for 1st matrix\n");
    read(mat1);
    display(mat1);
     printf("enter the elements for 2nd matrix\n");
    read(mat2);
    display(mat2);
    mult(mat1,mat2);
}
