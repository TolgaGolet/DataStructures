//23+5*   245+*

#include<stdio.h>
#include<ctype.h>

int stack[100];
int top=0;

void push(int p) {
	stack[top]=p;
	top++;
}

int pop() {
	top--;
	return stack[top];
}

int main() {
		char input[100];
		int x, y, z, num;
		while(1) {
		printf("Type a postfix expression: ");
		scanf("%s", &input);
		
		int i;
		for(i=0;input[i]!='\0';i++) {
			if(isdigit(input[i])) {
				num=input[i]-48;    
				push(num);
			}
			else {
				x=pop();
				y=pop();
				switch(input[i]) {
					case '+': {
						z=x+y;
						break;
					}
					case '-': {
						z=x-y;
						break;
					}
					case '*': {
						z=x*y;
						break;
					}
					case '/': {
						z=x/y;
						break;
					}
				}
				push(z);
			}
		}
		
		printf("Result: %d\n", pop());
}
	return 0;
}
