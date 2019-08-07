#include <stdio.h>
#include <stdlib.h>
#define arraySize 10
 
typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}NODE;
 
typedef NODE *BTREE;
  
BTREE init_node(char d1, BTREE p1, BTREE p2)
{
    BTREE t;
 
    t = (BTREE)malloc(sizeof(NODE));
    t->data = d1;
    t->left = p1;
    t->right = p2;
    return t;
}
 
BTREE create_tree(char a[], int i, int size)
{
    if (i >= size)
        return NULL;
    else
        return(init_node(a[i], create_tree(a, 2*i+1, size), create_tree(a, 2*i+2, size)));
}
 
void preorder (BTREE root)
{
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root -> left);
        preorder(root -> right);
    }
}
 
void inorder (BTREE root)
{
    if (root != NULL) {
        inorder(root -> left);
        printf("%c ", root->data);
        inorder(root -> right);
    }
}
  
void postorder (BTREE root)
{
    if (root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        printf("%c ", root->data);
    }
}

int main()
{
    char a[arraySize] = {'g','d','i','b','f','h','j','a','c','e'};
    BTREE root;
 
    root = create_tree(a, 0, arraySize) ;
    printf("PREORDER\n");
    preorder(root);
    printf("\n");
    printf("INORDER\n");
    inorder(root);
    printf("\n");
 	printf("POSTORDER\n");
    postorder(root);
    printf("\n");
    
    system("PAUSE");
}
