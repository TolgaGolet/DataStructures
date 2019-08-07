#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct {
	int data;
	struct nodeStruct* left;
	struct nodeStruct* right;
	struct nodeStruct* thread;
}node;

node* insert(node* tree, int x) {
	if(tree==NULL) {
		node* root=(node*)malloc(sizeof(node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	
	if(tree->data<x) {
		tree->right=insert(tree->right, x);
		return tree;
	}
	tree->left=insert(tree->left, x);
	return tree;
}

void inTrav(node* tree) {
	if(tree==NULL) return;
	inTrav(tree->left);
	printf("%d ", tree->data);
	inTrav(tree->right);
}

void preTrav(node* tree) {
	if(tree==NULL) return;
	printf("%d ", tree->data);
	preTrav(tree->left);
	preTrav(tree->right);
}

void postTrav(node* tree) {
	if(tree==NULL) return;
	postTrav(tree->left);
	postTrav(tree->right);
	printf("%d ", tree->data);
}

int max(node* tree) {
	while(tree->right!=NULL) tree=tree->right;
	return tree->data;
}

int min(node* tree) {
	while(tree->left!=NULL) tree=tree->left;
	return tree->data;
}

node* deleteNumber(node* tree, int x) {
	if(tree==NULL) return NULL;
	if(tree->data==x) {
		if(tree->left==NULL&&tree->right==NULL) return NULL;
		if(tree->right!=NULL) {
			tree->data=min(tree->right);
			tree->right=deleteNumber(tree->right, min(tree->right));
			return tree;
		}
		tree->data=max(tree->left);
		tree->left=deleteNumber(tree->left, max(tree->left));
		return tree;
	}	
	if(tree->data<x) {
		tree->right=deleteNumber(tree->right, x);
		return tree;
	}
	
	tree->left=deleteNumber(tree->left, x);
	return tree;
}

int main(){
	int s;
	node* tree=NULL;
	
	tree=insert(tree, 38);
	tree=insert(tree, 46);
	tree=insert(tree, 2);
	tree=insert(tree, 5);
	tree=insert(tree, 18);
	tree=insert(tree, 11);
	tree=insert(tree, 27);
	
	printf("Threaded Binary Tree\n\n");
	
	while(1) {
		printf("1.In Traversal\n2.Pre Traversal\n3.Post Traversal\n4.Delete Number\nSelection: ");
		scanf("%d", &s);
		switch(s) {
			case 1: {
				printf("\nIn Treversal;\n");
				inTrav(tree);
				printf("\n\n");
				break;
			}
			case 2: {
				printf("\nPre Treversal;\n");
				preTrav(tree);
				printf("\n\n");
				break;
			}
			case 3: {
				printf("\nPost Traversal;\n");
				postTrav(tree);
				printf("\n\n");
				break;
			}
			case 4: {
				printf("\nNumber to delete: ");
				scanf("%d", &s);
				tree=deleteNumber(tree, s);
				printf("Deleted number: %d\n\n", s);
				break;
			}
			default: {
				printf("\n");
				printf("Wrong selection. Try again.\n\n");
				break;
			}
		}
	}
		
	return 0;
}
