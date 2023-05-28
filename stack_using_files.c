#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10

struct stack
{
    int data[size];
    int top;
};

int isfull(struct stack *sptr)
{
    if(sptr->top==size-1)
        return 1;
    else
        return 0;
}

int isempty(struct stack *sptr)
{
    if(sptr->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stack *sptr,int element)
{
    sptr->top++;
    sptr->data[sptr->top]=element;
}

int pop(struct stack *sptr)
{
    int element=sptr->data[sptr->top];
    sptr->top--;
    return element;
}

void display(struct stack *sptr,FILE *stack_file)
{
    if(sptr->top==-1)
        printf("STACK EMPTY\n");
    else
    {
        for(int i=sptr->top; i!=-1; i--)
        {
            printf("%d ",sptr->data[i]);
            fprintf(stack_file,"%d ",sptr->data[i]);
        }
    }
}

int main()
{
    struct stack s,*sptr=&s;
    FILE *fp1,*sk_fp,*sk_fp2,*op_file,*stack_file;

    fp1=fopen("inputfile.txt","w");
    sk_fp=fopen("push_log.txt","w");
    sk_fp2=fopen("pop_log.txt","w");
    op_file=fopen("operation.txt","w");
    stack_file=fopen("stack_file.txt","w");

    sptr->top=-1;
    int ch,element;
    int start=1,end=100;
    int num[size];
    srand(time(0));
    printf("The random numbers generated are\n");
    for (int i = 0; i < size; i++)
    {
        num[i] = rand() % (end - start + 1) + start;
        fprintf(fp1,"%d ",num[i]);
        printf("%d ", num[i]);
    }

    int k=0;
    while(1)
    {
        printf("\nSTACK MENU\n");
        printf("1.PUSH 2.POP 3.DISPLAY 4:EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if(isfull(sptr))
            {
                printf("Stack overflow\n");
            }
            else
            {
                printf("PUSHED ELEMENT IS = %d\n",num[k]);
                fprintf(op_file,"%s %d\n","pushed =",num[k]);
                fprintf(sk_fp,"%d ",num[k]);
                push(sptr,num[k]);
                k++;
            }
            break;

            case 2:
            if(isempty(sptr))
            {
                printf("Stack underflow\n");
            }
            else
            {
                element=pop(sptr);
                fprintf(op_file,"%s %d\n","popped =",element);
                fprintf(sk_fp2,"%d ",element);
                printf("POPPED ELEMENT IS = %d\n",element);
            }
            break;

            case 3:display(sptr,stack_file);
            break;

            case 4:fclose(fp1);
            fclose(op_file);
            fclose(sk_fp);
            fclose(sk_fp2);
            fclose(stack_file);
            exit(0);
            break;

            default:printf("INVALID CHOICE \n");
            break;
        }
    }
    return 0;
}
