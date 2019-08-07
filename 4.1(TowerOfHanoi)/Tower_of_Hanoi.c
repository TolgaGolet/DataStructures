#include<stdio.h>

void towerOfHanoi(int d, char from, char to, char aux) {     //Recursional function.
	
	if(d==1) {
		printf("\n 1. diski %c cubugundan %c cubuguna tasi.", from, to);
		return;
	}
	towerOfHanoi(d-1, from, aux, to);
	printf("\n %d. diski %c cubugundan %c cubuguna tasi.", d, from, to);
    towerOfHanoi(d-1, aux, to, from);
}

int main()  {
	int d=3;           //Number of the disks. Smaller number means smaller disk.
	
	towerOfHanoi(d, 'A', 'C', 'B');   //Rods.
	
	printf("\n");
	
	system("PAUSE");
		
	return 0;
}
