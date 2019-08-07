#include<stdio.h>
#define MAX 10

int queueArray[MAX];
int front=-1, rear=-1;   

int isEmpty() {
	if(front==-1&&rear==-1) return 1;
	else return 0;
}

void insertElement(int a) {
	if(rear==MAX-1) printf("Error: The queue is full.\n");
	else if(isEmpty()) {
		front=0;
		queueArray[++rear]=a;
	}
	else {
		queueArray[++rear]=a;
	}
}

void deleteElement() {
	if(isEmpty()||front>rear) printf("Error: The queue is already empty.\n");
	else {
		printf("Item deleted: '%d'\n", queueArray[front]);
		front++;
	}
}

void listElements() {
	int i;
	if(isEmpty()) printf("Error: The queue is empty.");
	else {
		for(i=front;i<=rear;i++) printf("%d ", queueArray[i]);
		printf("\n");
	}
}

int main() {
	
	int choice;
	while(1) {
		printf("1.Insert an element.\n2.Delete an element.\n3.List the elements.\nWhich one do you want to do: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1: {
				int a;
				printf("Enter the number you want to insert: ");
				scanf("%d", &a);
				insertElement(a);
				break;
			}
				
			case 2: {
				deleteElement();
				break;
			}
			case 3: {
				listElements();
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
