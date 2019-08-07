#include<stdio.h>

int top=0; 
char stack[100];

void push(char p) {
	stack[top]=p;
	top++;
}

void pop() {
	top--;
}

void is_correct() {
	if(top==0) printf("The expression is correct.\n\n");
	else printf("The expression is wrong.\n\n");
}

int main() {
	
	char input[100];
	while(1) {
	printf("Enter an infix expression: ");
	scanf("%s", &input);
	
	int i;
	for(i=0;input[i]!='\0';i++) {
		if(i==0&&input[i]==')') {
			top++;
			break;
		}
		else if(input[i]=='(') push(input[i]);
		else if(i>0&&input[i]==')') pop(); 
	}
	
	is_correct();
	top=0;
}
	return 0;
}
