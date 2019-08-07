#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct {
	int data;
	struct nodeStruct* left;
	struct nodeStruct* right;
}node;

int level = -1;
int found = 0;

node* insert(node* tree, int x) {
	if (tree == NULL) {
		node* root = (node*)malloc(sizeof(node));
		root->data = x;
		root->left = NULL;
		root->right = NULL;
		return root;
	}

	if (tree->data<x) {
		tree->right = insert(tree->right, x);
		return tree;
	}
	tree->left = insert(tree->left, x);
	return tree;
}

int findNode(node* tree, int x) {
	if (tree != NULL) {
		level++;
		if (tree->data == x) {
			found = 1;
			return level;
		}
		else {
			if(found != 1) findNode(tree->left, x);
			if (found != 1) findNode(tree->right, x);
			if (found != 1) level--;
		}
	}
}

void inTrav(node* tree) {
	if (tree == NULL) return;
	inTrav(tree->left);
	printf("%d ", tree->data);
	inTrav(tree->right);
}

void preTrav(node* tree) {
	if (tree == NULL) return;
	printf("%d ", tree->data);
	preTrav(tree->left);
	preTrav(tree->right);
}

void postTrav(node* tree) {
	if (tree == NULL) return;
	postTrav(tree->left);
	postTrav(tree->right);
	printf("%d ", tree->data);
}

int main() {
	int s;   //Selection.

	node* tree = NULL;

	tree = insert(tree, 38);
	tree = insert(tree, 46);
	tree = insert(tree, 2);
	tree = insert(tree, 5);
	tree = insert(tree, 18);
	tree = insert(tree, 11);
	tree = insert(tree, 27);

	printf("Binary Tree\n\n");

	while (1) {
		printf("1.In Traversal\n2.Pre Traversal\n3.Post Traversal\n4.Search Node\nSelection: ");
		scanf("%d", &s);
		switch (s) {
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
			int x = 0, a = -1;
			printf("\nEnter the number you want to search: ");
			scanf("%d", &x);
			a = findNode(tree, x);
			level = -1;
			found = 0;
			if (a == -1) printf("Number not found.\n\n");
			else printf("Number %d was found on level %d\n\n", x, a);
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