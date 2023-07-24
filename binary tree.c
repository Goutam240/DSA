#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createnode(struct node *root,int key)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* createtree(struct node *root,int key)
{
    if(root==NULL)
    {
        root=createnode(root,key);
        return root;
    }
    if(root->data>key)
    {
        root->left=createtree(root->left,key);
        return root;
    }
    if(root->data<key)
    {
        root->right=createtree(root->right,key);
        return root;
    }

};
void postorderdisplay(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }

    postorderdisplay(root->left);
    postorderdisplay(root->right);
    printf("%d ",root->data);
}
void inorderdisplay(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }

    inorderdisplay(root->left);
    printf("%d ",root->data);
    inorderdisplay(root->right);

}
void preorderdisplay(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    printf("%d ",root->data);
    preorderdisplay(root->left);
    preorderdisplay(root->right);

}
int main()
{
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    int i,key;
    int x;
    for(i=0;i<n;i++)
    {
        x=rand()%100;
        root=createtree(root,x);
    }
    printf("Postorder display\n");
    postorderdisplay(root);
    printf("\nPreorder display\n");
    preorderdisplay(root);
    printf("\nInorder display\n");
    inorderdisplay(root);

}
