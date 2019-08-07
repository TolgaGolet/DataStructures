#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct {
	struct nodeStruct* prev;
	int data;
	struct nodeStruct* next;
}node;

node* root = NULL;

node* insert(node* root, int x) {
	node* iter = root;

	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		iter = root;
		root->data = x;
		root->prev = NULL;
		root->next = NULL;
		return root;  //Changed
	}
	while (iter->next != NULL) {
		iter = iter->next;
	}

	iter->next = (node*)malloc(sizeof(node));
	iter->next->prev = iter;
	iter->next->data = x;
	iter->next->next = NULL;
}

void display(node* root) {
	node* iter = root;
	while (iter != NULL) {
		printf("%d ", iter->data);
		iter = iter->next;
	}
}

int main() {
	int s;
	while (1) {
		printf("\nDoubly Linked List;\n1.Insert Number\n2.Delete Number\n3.Display Numbers\nYour selection: ");
		scanf("%d", &s);
		switch (s) {
		case 1: {
			int x;
			printf("Enter the number: ");
			scanf("%d", &x);
			root=insert(root, x);
			break;
		}
		case 2: {

			break;
		}
		case 3: {
			display(root);
			break;
		}
		default: {
			printf("Typed wrongly. Try again.\n");
			break;
		}
		}
	}

	return 0;
}
