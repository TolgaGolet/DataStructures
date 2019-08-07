#include<stdio.h>

int main() {
	int i, j, temp;
	
	int arr[9]={1, 5, 8, 12, 31, 42, 57, 65, 81};
	
	printf("Ascending order;\n");
	
	for(i=0;i<9;i++) {
		printf("%d ", arr[i]);
	}
	
	for(i=0, j=8;i<4, j>=5;i++, j--) {
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	
	printf("\nDescending order;\n");
	
	for(i=0;i<9;i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
	system("PAUSE");
	
	
	return 0;
}
