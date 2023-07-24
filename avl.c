#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct Node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node* rotateRight(struct Node* y)
 {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node* rotateLeft(struct Node* x)
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalanceFactor(struct Node* node)
 {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* insert(struct Node* node, int value)
{

    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else
        return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    if (getBalanceFactor(node) > 1 && value < node->left->value)
        return rotateRight(node);

    if (getBalanceFactor(node) < -1 && value > node->right->value)
        return rotateLeft(node);

    if (getBalanceFactor(node) > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (getBalanceFactor(node) < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

int delete_node(struct Node** root ,int e)
{
    //printf("%d",e);
   //find the key with parent

   struct Node* cur =*root;
   struct Node* par=NULL;

   while(cur && e!=cur->value)
   {
       par=cur;
       if(e<cur->value)
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
       struct Node* in=cur->right;
       struct Node* temp;
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
{printCurrentLevel(root,i);
printf("\n");}
}

// Print nodes at a current level
void printCurrentLevel(struct Node* root, int level)
{
if (root == NULL)
return;
if (level == 1)
printf("%d     ",root->value);
else if (level > 1) {
printCurrentLevel(root->left, level - 1);
printCurrentLevel(root->right, level - 1);
}
}


int height(struct Node* node)
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

int main() {
    struct Node* root = NULL;
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
  int e;
  fp=fopen("input.txt","r");
    for(i=0;i<n;i++)
               {
               fscanf(fp,"%d",&e);
                root= insert(root,e);
                }
    fclose(fp);
    printLevelOrder(root);
    printf("\nEnter num to be deleted\n");
               scanf("%d",&e);
               int s;
               s=delete_node(&root,e);
               if(s==0)
                printf("Key not found\n");
               else
                printf("Key deleted\n");
    // Print the AVL tree in ascending order
    printf("AVL Tree \n ");
    printLevelOrder(root);
    printf("\n");
    }
