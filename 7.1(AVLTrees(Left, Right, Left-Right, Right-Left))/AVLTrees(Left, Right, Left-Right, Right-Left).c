#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
}node;
 
int height(node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int max(int a, int b)
{
    return (a > b)? a : b;
}
 
/* Function that allocates a new node with the given key and
    NULL left and right pointers. */
node* newNode(int data)
{
    node* root = (node*)malloc(sizeof(node));
    root->data   = data;
    root->left   = NULL;
    root->right  = NULL;
    root->height = 1;
    return(root);
}
 
// Function to right rotate subtree rooted with y
node* rightRotate(node* y)
{
    node* x = y->left;
    node* T2 = x->right;
 
    // Rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// Function to left rotate subtree rooted with x
node* leftRotate(node* x)
{
    node* y = x->right;
    node* T2 = y->left;
 
    // Rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
node* insert(node* node, int data)
{
    if (node == NULL)
        return(newNode(data));
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
 
    /* Update height of the node */
    node->height = 1 + max(height(node->left), height(node->right));
 
    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced
    // there are 4 cases
 
    // Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
 
    // Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
	
    return node;
}
 
void preOrder(node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main()
{
  node* root = NULL;
 
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
 
  printf("Preorder traversal;\n");
  preOrder(root);
 
  return 0;
}
