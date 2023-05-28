#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n=20;
    int a[n];
    srand(time(0));
    int start=1,end=100,count=20;
    FILE *fp;
    fp=fopen("random_file.txt","w");

    printf("\nEnter array elements\n");
    for(int i=0;i<n;i++)
    {
        a[i]=(rand()%(end-start+1))+start;
        printf("%d ",a[i]);
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);

    int duplicate=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==a[j])
            duplicate++;
        }
        printf("\nThe number %d is duplicated for %d times\n",a[i],duplicate);
        duplicate = 0;
    }
    return 0;
}
