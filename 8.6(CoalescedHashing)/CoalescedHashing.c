#include <stdio.h>


typedef struct table{
    int data;
    int link;
}table;


int place=0;
int R=10;


table dataTable[10];


void hash(int x) {
    place=x%11;
    if(dataTable[place].data==-1) 
        dataTable[place].data=x;
    else {
        collision(x);
    }
}


void collision(int x) {
    if(dataTable[R].data==-1) { 
            dataTable[place].link=R;
            dataTable[R].data=x;
            R--;
        }
        else {
            R--;
            collision(x);
        }
}


int main()
{
    int i;
    for(i=0;i<11;i++) {
        dataTable[i].data=-1;
        dataTable[i].link=-1;
    }
    
    hash(27);
    hash(18);
    hash(29);
    hash(28);
    hash(39);
    hash(13);
    hash(16);
    
    printf("Data Link\n");
	
	for(i=0;i<11;i++) {
        printf("%d ", dataTable[i].data);
        printf("%d\n", dataTable[i].link);
    }
    
    return 0;
}
