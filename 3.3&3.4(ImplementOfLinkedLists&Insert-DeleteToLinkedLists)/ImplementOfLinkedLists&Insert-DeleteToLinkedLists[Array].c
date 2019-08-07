#include<stdio.h>
#include<stdlib.h>
#define NN 5

struct nodeStruct {
	int data;
	struct nodeStruct* next;
};

struct nodeStruct node[NN];

void insert(int x) {
	int i=0;
	while(node[i].next!=NULL) {
		i++;
	}
	
	node[i].data=x;
	node[i+1].next=NULL;
	i++;
}

void display() {
	int i=0;
	while(node[i].next!=NULL) {
		printf("%d ", node[i].data);
		i++;
	}
}


int main() {
	node[0].next=NULL;
	
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	insert(25);
	
	display();
	
	return 0;
}
