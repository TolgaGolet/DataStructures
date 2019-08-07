#include<stdio.h>

int main() {
	/* 90-100  A
	   80-89   B
	   70-79   C
	   60-69   D
	           F  */
	int grade, value;
	
	char letters[]={"FFFFFFDCBAA"};
	
	do {
	printf("Enter the grade: ");
	scanf("%d", &grade);
	value=grade/10;
	printf("Letter Grade: %c\n", letters[value]);
} while(1);

	return 0;
}
