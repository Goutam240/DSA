#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *lnode;
    struct node *rnode;
};
struct node* getnode(int key)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=key;
    newnode->rnode=NULL;
    newnode->lnode=NULL;
    return newnode;
}
struct node* insertnode(struct node *root,int key)
{
    struct node *newnode=getnode(key);
    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    else{
            if(key>root->data)
            {
               root->rnode=insertnode(root->rnode,key);
            }
            else if(key<=root->data)
            {
               root->lnode=insertnode(root->lnode,key);
            }
    }
}

int searchnode(struct node *root,int key)
{
    int status=0;
    if(root!=NULL)
    {
        if(root->data==key)
        {
            status=1;
            return 1;
        }
        else if(key>root->data)
            status=searchnode(root->rnode,key);
        else
            status=searchnode(root->lnode,key);
    }
    return status;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->lnode);
        preorder(root->rnode);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->lnode);
        postorder(root->rnode);
        printf("%d\n",root->data);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->lnode);
        printf("%d\n",root->data);
        inorder(root->rnode);
    }
}
struct node* search_delete(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("key not found\n");
    }
    else if(root->data==key)
        {
            if(root->lnode==NULL && root->rnode==NULL)
            {
                printf("%d is deleted\n",root->data);
                free(root);
                return NULL;
            }
            else if(root->lnode==NULL && root->rnode!=NULL)
            {
                struct node *temp = root->rnode;
                printf("%d is deleted\n",root->data);
                free(root);
                return temp;
            }
            else if(root->lnode!=NULL && root->rnode==NULL)
            {
                struct node *temp = root->lnode;
                printf("%d is deleted\n",root->data);
                free(root);
                return temp;
            }
            else if(root->lnode!=NULL && root->rnode!=NULL)
            {
                 struct node *cur=root,*prev=root ;
                 cur=cur->lnode;
                 while(cur->rnode!=NULL)
                 {
                     prev=cur;
                    cur=cur->rnode;
                 }
                 if(cur==root->lnode)
                 {
                     root->data=cur->data;
                     root->lnode=cur->lnode;
                     free(cur);
                 }
                 else
                {
                    root->data=cur->data;
                    prev->rnode=cur->lnode;
                    free(cur);
                 }
                 return root;
            }
        }

        else if(key>root->data)
            {
                root->rnode=search_delete(root->rnode,key);
            }

        else{
                root->lnode=search_delete(root->lnode,key);
        }

    return root;
}

int main()
{
    struct node *root=NULL;
    int ch;
    int key;
    int status;
    int level;
    int hight;
    while(1)
    {
        printf("1)insert node 2)search node 3)display 4)search and delete 5)exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter data\n");
            scanf("%d",&key);
            root=insertnode(root,key);
            break;
            case 2:printf("enter data\n");
            scanf("%d",&key);
            status=searchnode(root,key);
            if(status==1)
                printf("key found\n");
            else
                printf("key not found");
            break;
            case 3:
                inorder(root);
            break;
            case 4:printf("enter the data to be deleted\n");
            scanf("%d",&key);
            root=search_delete(root,key);
            break;
            case 5:exit(0);
            break;
            default:printf("f");
                break;
       }
  }
  return 0;
}
