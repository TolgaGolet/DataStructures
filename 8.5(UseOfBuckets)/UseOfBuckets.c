#include <stdio.h>

int data0[10];
int data1[10];
int place=0;

void hash(int x) {
    place=x%11;
    if(data0[place]==-1) 
        data0[place]=x;
    else {
        data1[place]=x;
}
}

int main()
{    
	int i;
	for(i=0; i<11; i++) {
		data0[i]=-1;
		data1[i]=-1;	
	}
	
    hash(27);
    hash(18);
    hash(29);
    hash(28);
    hash(39);
    hash(13);
    hash(16);
    
    for(i=0;i<11;i++) {
     	printf("%d %d\n", data0[i], data1[i]);
    }

    return 0;
}
