#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *link;
}*NODE;
NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("MEMORY NOT ALLOCATED \n");
        exit(0);
    }
    printf("ENTER DATA \n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}
NODE insert_front(NODE head)
{
    NODE newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
NODE insert_spc(NODE head)
{
    NODE prev,cur;
    int pos;
    NODE newnode=create_node();
    int count=count_chars(head);
    printf("ENTER THE POSITION \n");
    scanf("%d",&pos);
    if(pos==1 && head==NULL)
    {
        head=newnode;
    }
    else if (pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos==count+1)
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    else if(pos>1 && pos<=count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=newnode;
        newnode->link=cur;
    }
    return head;

}
void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("SINGLY LINKED LIST IS EMPTY \n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}
NODE delete_end(NODE head)
{
    NODE prev,cur;
    if(head==NULL)
    {
        printf("EMPTY NODE \n");
    }
    else if(head->link==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;
}
NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("EMPTY NODE \n");
    }
    else if(head->link==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;
}
NODE delete_spc(NODE head)
{
    NODE prev,cur;
    int pos;
    int count=count_chars(head);
    printf("ENTER THE POSITION \n");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("SINGLY LINKED LIST IS EMPTY \n");
        exit(0);
    }
    else if (pos==1 && head->link==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
         head=NULL;
    }
    else if(pos==1)
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    else if(pos==count)
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("DELETED DATA IS %d\n",cur->data);
        free(cur);
    }
    else if(pos>1 && pos<count)
    {
        prev=NULL;
        cur=head;
        for(int i=0;i<pos-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;
}

NODE reverse_list(NODE head)
{
    NODE prev=NULL;
    NODE cur=head;
    NODE next=NULL;
    while(cur!=NULL)
    {
        next=cur->link;
        cur->link=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
int count_chars(NODE head)
{

    int count=0;
    NODE cur;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }

    }
    return count;
}
int main()
{
    NODE head=NULL;
    int status,ch,chars;
    while(1)
    {
        printf("\nSINGLY LINKED LIST MENU \n");
        printf("1:Adding end 2:Appending at beginning 3:Adding specific pos 4:Display 5:Delete end 6:Delete front 7:Delete specific 8:Reverse list pos 8:exit \n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
                   break;
            case 2:head=insert_front(head);
                   break;
            case 3:head=insert_spc(head);
                   break;
            case 4:display(head);
                   break;
            case 5:head=delete_end(head);
                   break;
            case 6:head=delete_front(head);
                   break;
            case 7:head=delete_spc(head);
                   break;
            case 8:head=reverse_list(head);
                    break;
            case 9:exit(0);
                    break;
            default:printf("INVALID CHOICE \n");
                    break;
        }
    }
    return 0;
}
