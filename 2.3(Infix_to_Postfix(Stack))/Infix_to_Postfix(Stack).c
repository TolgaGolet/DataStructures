//(2+3)-(7/9)     (2+3)     (1+2)*(3+(4/5))
#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = 0;

void push(char p) {
	stack[top++] = p;
}

char pop() {
	if (top == 0) return 0;
	return stack[--top];
}

int main() {
	char input[100];
	char postfix_string[100];
	char op;
	while(1) {
	printf("Type an infix expression: ");
	scanf("%s", &input);
	int i, j;
	for (i = 0, j = 0; input[i] != '\0'; i++) {
		if (input[i] == '(') {
			continue;
		}
		else if (input[i] == ')') {
			do {
				op = pop();
				postfix_string[j] = op;
				j++;
			} while (top != 0);
		}
		else if (isdigit(input[i])) {
			postfix_string[j] = input[i];
			j++;
		}
		else {
			push(input[i]);
		}
	}

	postfix_string[j] = '\0';

	printf("%s\n", postfix_string);
	
}

	system("PAUSE");

	return 0;
}
