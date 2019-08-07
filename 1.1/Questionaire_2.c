#include<stdio.h>

int main() {
	int start=1, counter=1;
	char c;
	int results[3][3]={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};	
	int p1=0, p2=0, p3=0, p4=0, p5=0, p6=0, p7=0, p8=0;
	while(start==1) {
		printf("What is the genre of this person?\na)Male\nb)Female\nAnswer: ");
		scanf("%c", &c);
		if(c=='a') results[0][0]++;
		else if(c=='b') results[0][1]++;
		fflush(stdin);
		printf("What is your education level?\na)Primary School\nb)High School\nc)University\nAnswer: ");
		scanf("%c", &c);
		if(c=='a') results[1][0]++;
		else if(c=='b') results[1][1]++;
		else if(c=='c') results[1][2]++;
		fflush(stdin);
		printf("What is your best foreign language?\na)English\nb)German\nc)French\nAnswer: ");
		scanf("%c", &c);
		if(c=='a') results[2][0]++;
		else if(c=='b') results[2][1]++;
		else if(c=='c') results[2][2]++;
		fflush(stdin);
		printf("Enter 1 for one more time, 2 to finish: ");
		scanf("%d", &start);
		if(start==1) counter++;
		fflush(stdin);
	}
	
	if(results[0][0]!=0) p1=(results[0][0]*100)/counter;
	if(results[0][1]!=0) p2=(results[0][1]*100)/counter;
	if(results[1][0]!=0) p3=(results[1][0]*100)/counter;
	if(results[1][1]!=0) p4=(results[1][1]*100)/counter;
	if(results[1][2]!=0) p5=(results[1][2]*100)/counter;
	if(results[2][0]!=0) p6=(results[2][0]*100)/counter;
	if(results[2][1]!=0) p7=(results[2][1]*100)/counter;
	if(results[2][2]!=0) p8=(results[2][2]*100)/counter;
	
	printf("\n	RESULTS\nWhat is the genre of this person?\na)Male            %d__%d%%\nb)Female          %d__%d%%", results[0][0], p1, results[0][1], p2);
	printf("\nWhat is your education level?\na)Primary School  %d__%d%%\nb)High School     %d__%d%%\nc)University      %d__%d%%", results[1][0], p3, results[1][1], p4, results[1][2], p5);
	printf("\nWhat is your best foreign language?\na)English         %d__%d%%\nb)German          %d__%d%%\nc)French          %d__%d%%\n", results[2][0], p6, results[2][1], p7, results[2][2], p8);
	
	system("PAUSE");
	
	return 0;
}
