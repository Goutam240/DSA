#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
   struct node *left;
   int data;
   struct node *right;
}*node;

void preOrder(node root)
{
 if(root==NULL)
   return;
   printf("%d\t",root->data);
   preOrder(root->left);
   preOrder(root->right);
}

void right_leftOrder(node root)
{
 if(root==NULL)
   return;
    right_leftOrder(root->right);
   printf("%d\t",root->data);
   right_leftOrder(root->left);

}
void inOrder(node root)
{
 if(root==NULL)
   return;
   inOrder(root->left);
   printf("%d\t",root->data);
   inOrder(root->right);
}

void postOrder(node root)
{
 if(root==NULL)
   return;
   postOrder(root->left);
   postOrder(root->right);
   printf("%d\t",root->data);
}
void addKey(node *root,int e)
{
  node p=(node)malloc(sizeof(struct node));
   p->left=p->right=NULL;
   p->data=e;
   if (root==NULL)
   *root=p;
   else
   {
      node cur=root;
      node prev=NULL;
      while(cur)
      {
      prev=cur;
      if(e>cur->data)
      cur=cur->right;
      else if(e<cur->data)
      cur=cur->left;
      else
      {printf("Duplicate key\n");
        free(p);
        return;}
      }
    if(e>prev->data)
    prev->right=p;
    if(e<prev->data)
    prev->left=p;
}}
int delete_node(node* root ,int e)
{
    printf("%d",e);
   //find the key with parent

   node cur =*root;
   node par=NULL;

   while(cur && e!=cur->data)
   {
       par=cur;
       if(e<cur->data)
        cur=cur->left;
       else
        cur=cur->right;
   }
   if(cur==NULL)
    return 0;

   //case 1:deletion of leaf node
   if(cur->left==NULL && cur->right==NULL)
   {
       if(cur==*root)
        *root=NULL;
       else if(par->left==cur)
        par->left=NULL;
        else if(par->right==cur)
        par->right=NULL;
        free(cur);
        return 1;
   }

   //case 2:deletion of half node
   if(cur->left==NULL && cur->right!=NULL || cur->left!=NULL && cur->right==NULL)
   {
       if(cur==*root)
       {
           if(cur->left)
            *root=cur->left;
           else
            *root=cur->right;
       }
       else if(par->right==cur)
       {
           if(cur->left)
            par->right=cur->left;
           else
            par->right=cur->right;
       }
        else if(par->left==cur)
       {
           if(cur->left)
            par->left=cur->left;
           else
            par->left=cur->right;
       }
       free(cur);
       return 1;
   }

   //Case 3 :Deletion of full node

   if(cur->left!=NULL && cur->right!=NULL)
   {
       node in=cur->right;
       node temp;
       temp=NULL;
       while(in->left)
       {
           temp=in;
           in=in->left;
       }
       if(temp!=NULL)
        temp->left=in->right;
       in->left=cur->left;

       //to avoid self loop
       if(cur->right!=in)
        in->right=cur->right;

       if(cur==*root)
        *root=in;
       else if(par->right==cur)
        par->right=in;
       else if(par->left==cur)
        par->left=in;
       free(cur);
       return 1;
   }

}


// Function to print level order traversal a tree
void printLevelOrder(struct node* root)
{
int h = height(root);
int i;
for (i = 1; i <= h; i++)
{printCurrentLevel(root, i);
printf("\n");}
}

// Print nodes at a current level
void printCurrentLevel(struct node* root, int level)
{
if (root == NULL)
return;
if (level == 1)
printf("%d     ", root->data);
else if (level > 1) {
printCurrentLevel(root->left, level - 1);
printCurrentLevel(root->right, level - 1);
}
}


int height(struct node* node)
{
if (node == NULL)
return 0;
else {

// Compute the height of each subtree
int lheight = height(node->left);
int rheight = height(node->right);

// Use the larger one
if (lheight > rheight)
return (lheight + 1);
else
return (rheight + 1);
}
}

int main()
{
int n,P,Q,a[100],b[100],i;
FILE *fp;
printf("enter n\n");
scanf("%d",&n);
printf("enter P\n");
scanf("%d",&P);
printf("Enter Q\n");
scanf("%d",&Q);
fp=fopen("input.txt","w");
for(i=0;i<n;i++)
{
   a[i]=rand()%(Q+1-P)+P;
   fprintf(fp,"%d\n",a[i]);
   printf("%d\n",a[i]);
}
fclose(fp);
node root=NULL;
  int ch ,e;
  fp=fopen("input.txt","r");
  while (1)
  {
      printf("\n1.Add the key\n");
      printf("2.Pre-Order\n");
      printf("3.In-Order\n");
      printf("4.Post-Order\n");
      printf("5.Right-node-left\n");
      printf("6.Delete node\n");
      printf("7.Level order\n");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:for(i=0;i<n;i++)
               {
               fscanf(fp,"%d",&e);
                 addKey(&root,e);
                }
               /* scanf("%d,&e");
                addKey(&root,e);*/
                break;

        case 2: preOrder(root);
                break;

        case 3: inOrder(root);
                break;

        case 4: postOrder(root);
                break;

        case 5: right_leftOrder(root);
                break;

         case 6:printf("\nEnter num to be deleted\n");
               scanf("%d",&e);
               int s;
               s=delete_node(&root,e);
               if(s==0)
                printf("Key not found\n");
               else
                printf("Key deleted\n");
               break;

        case 7:printLevelOrder(root);
                  break;

        default:printf("Invalid choice\n");
                break;

}
}fclose(fp);
}
