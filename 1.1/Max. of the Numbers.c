#include<stdio.h>

int main() {
	int numbers[10]={5, 3, 8, 7, 2, 9, 4, 6, 1, 5};
	
	int n=10, max, i;
	
	for(i=0;i<10;i++) printf("%d ", numbers[i]);
	
	max=numbers[0];
	
	for(i=0;i<n;i++) {
		if(max<numbers[i])
			max=numbers[i];
	}
	
	printf("\nMaximum Number is %d.\n", max);
	
	system("PAUSE");
		
	return 0;
}
