#include<stdio.h>
#include<Stdlib.h>
#include<string.h>

int Length(char *strings)
{
    int i;
    for(i=0;strings[i]!='\0';++i);

    return i;
}
void read_linesFromFile(char lines[10][100], int *num_lines)
{
    FILE *file = fopen("input.txt","r");
    if (file == NULL)
    {
        printf("Could not open file input.txt");
        return;
    }
    char line[100];
    while (*num_lines < 10 && fgets(line, 100, file) != NULL)
    {
        //fprintf(file,"%s ",*num_lines);
        strncpy(lines[*num_lines], line, 100);
        (*num_lines)++;
    }
    fclose(file);
}

void write_linesFromFile(char lines[10][100], int *num_lines)
{
    FILE *file = fopen("input.txt","w");
    char line[100];

    while (*num_lines < 10)
    {
        fprintf(file,"%s ",*lines);
        //fprintf(file,"\n");
        *lines++;
        (*num_lines)++;
    }
    fclose(file);
}
void search(char *pat,char *txt,char *change)
{
    int n=Length(txt);
    int m=Length(pat);
    int o=Length(change);
    int k=0,status,l;
    for(int i=0;i<n-m;i++)
    {
        int j;
        for( j=0;j<m;j++)
        {
            status=0;
            if(txt[i+j]!=pat[j])
            {
                status=1;
                break;
            }
        }
        if(status==0)
        {
            l=i;
         while(k!=o)
            {
                txt[l]=change[k];
                l++;
                k++;
            }
        while(k!=m)
        {
            txt[l]=' ';
            l++;
            k++;
        }
        }

         if(j==m)
                printf("%s\n",txt);

    }
}
int main()
{
 char lines[10][100];
    int num_lines = 0;
    char pat[10];//="ould";
    char change[10];
    printf("Reading from the file\n");
    read_linesFromFile(lines, &num_lines);
    printf("Enter the word you want to search in the file: ");
    printf("%s",pat);
    scanf("%s",pat);
    printf("Enter the word you want to replace: ");
    scanf("%s",change);
        for(int i=0;i<10;i++)
    {
        search(pat,lines[i],change);
    }
    write_linesFromFile(lines, &num_lines);
}
