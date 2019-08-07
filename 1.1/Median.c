#include<stdio.h>

int main() {
	
	int arr[9]={1, 5, 8, 12, 31, 42, 57, 65, 81};
	
	int i, temp;
	
	for(i=0;i<9;i++) {
		printf("%d ", arr[i]);
	}
	
	for(i=0; i<10/2; i++) {
		if(arr[i]<arr[i+1]) 
		temp=arr[i];
	}
	printf("\nMedian: %d\n", temp);
	
	system("PAUSE");		
	return 0;
}
