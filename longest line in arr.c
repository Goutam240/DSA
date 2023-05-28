#include<stdio.h>
#include<string.h>

int count_character(char line[100])
{
    int i,c=0;
    for(i=0;line[i]!='\0';i++)
    {
        c++;
    }
    return c;
}

void read_input(int n,char line[n][100])
{
    int i;
    for(i=-1;i<n;i++)
    {
       if(i==0)
        {
            gets(line[i]);
        }
        else
        {
                printf("Enter the line\n");
                gets(line[i]);
        }

    }
}

void longest(int n,char line[n][100])
{
    int m,max=0;
    char *k;
    for (int i=0;i<n;i++)
    {
        int m= count_character(line[i]);
        if ( m> max)
        {
            max = m;
            k = line[i];
        }
    }
    printf("Longest line:%s",k);
}

int main()
{
    int n;
    char line[n][100];
    printf("Enter number of lines to be selected \n");
    scanf("%d",&n);
    read_input(n,line);
    longest(n,line);
    return 0;
}
