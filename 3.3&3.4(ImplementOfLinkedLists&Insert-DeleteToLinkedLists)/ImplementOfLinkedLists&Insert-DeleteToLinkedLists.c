#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct {
	int data;
	struct nodeStruct* next;
}node;

void insert(node* root, int x) {
	while(root->next!=NULL) {
	root=root->next;
	}
	
	root->next=(node*)malloc(sizeof(node));
	root->next->data=x;
	root->next->next=NULL;
	printf(" \nInserted number: '%d'\n\n", x);
}

void display(node* root) {
	while(root!=NULL) {
		printf("%d ", root->data);
		root=root->next;
	}
}


int main() {
	node* root=(node*)malloc(sizeof(node));
	root->data=100;
	root->next=NULL;
	
	int s;
	while(1) {
	printf("\nLinked List;\n1.Insert Number\n2.Delete Number\n3.Display Numbers\nYour selection: ");
	scanf("%d", &s);
	switch(s) {
		case 1: {
			int x;
			printf("Enter the number: ");
			scanf("%d", &x);
			insert(root, x);
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
