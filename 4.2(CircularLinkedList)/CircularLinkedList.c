#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStruct {
	int data;
	struct nodeStruct* next;
}node;

void insert(node* root, int x) {
	node* iter=root;
	while(iter->next!=root) {
		iter=iter->next;
	}
	iter->next=(node*)malloc(sizeof(node));
	iter->next->data=x;
	iter->next->next=root;
	printf(" \nInserted number: '%d'\n", x);	
}

void display(node* root) {
	node* iter=root;
	printf("%d ", iter->data);
	iter=iter->next;
	while(iter!=root) {
		printf("%d ", iter->data);
		iter=iter->next;
	}	
}

int main() {
		node* root=(node*)malloc(sizeof(node));
		root->data=0;
		root->next=root;
		
		int s;
		while(1) {
			printf("\nCircular Linked List;\n1.Insert Number\n2.Delete Number\n3.Display Numbers\nYour selection: ");
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
