#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(struct node *root, int key)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *createTree(struct node *root, int key)
{
    if (root == NULL)
    {
        root = createNode(root, key);
        return root;
    }

    if (root->data > key)
    {
        root->left = createTree(root->left, key);
        return root;
    }

    if (root->data < key)
    {
        root->right = createTree(root->right, key);
        return root;
    }
}

void postorderDisplay(struct node *root, FILE *outputFile)
{
    if (root == NULL)
    {
        return;
    }

    postorderDisplay(root->left, outputFile);
    postorderDisplay(root->right, outputFile);
    fprintf(outputFile, "%d ", root->data);
}

void inorderDisplay(struct node *root, FILE *outputFile)
{
    if (root == NULL)
    {
        return;
    }

    inorderDisplay(root->left, outputFile);
    fprintf(outputFile, "%d ", root->data);
    inorderDisplay(root->right, outputFile);
}

void preorderDisplay(struct node *root, FILE *outputFile)
{
    if (root == NULL)
    {
        return;
    }
    fprintf(outputFile, "%d ", root->data);
    preorderDisplay(root->left, outputFile);
    preorderDisplay(root->right, outputFile);
}

int main()
{
    struct node *root = NULL;
    int n, key;
    FILE *inputFile, *inorderFile, *postorderFile, *preorderFile;

    // Open input.txt file for writing
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    fprintf(inputFile, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        key = rand() % 100; // Generate a random number between 0 and 99
        fprintf(inputFile, "%d\n", key);
    }

    fclose(inputFile);

    inputFile = fopen("input.txt", "r");
    inorderFile = fopen("inorder.txt", "w");
    postorderFile = fopen("postorder.txt", "w");
    preorderFile = fopen("preorder.txt", "w");

    if (inputFile == NULL || inorderFile == NULL || postorderFile == NULL || preorderFile == NULL)
    {
        printf("Error opening files.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%d", &key);
        root = createTree(root, key);
    }

    fprintf(postorderFile, "Postorder display:\n");
    postorderDisplay(root, postorderFile);
    fprintf(preorderFile, "Preorder display:\n");
    preorderDisplay(root, preorderFile);
    fprintf(inorderFile, "Inorder display:\n");
    inorderDisplay(root, inorderFile);

    fclose(inputFile);
    fclose(inorderFile);
    fclose(postorderFile);
    fclose(preorderFile);

   // printf("Output has been written to inorder.txt, postorder.txt, and preorder.txt.\n");

    return 0;
}
