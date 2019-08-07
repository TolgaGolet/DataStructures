#include<stdio.h>

int data[10];
int place=0;
int extra=0;
int collision=0;
int temp;

void hash(int x) {
    if(collision==0)
        place=x%11;
    if(data[place]==-1) {
            data[place]=x;
            collision=0;
    }
    else {
        if(collision==0) {
        	extra=x/11;
        	place=place+extra;
        	if(place>10)
            	place=place-11;
        	collision=1;
        	hash(x);
		}
		else {
			temp=data[place];
			data[place]=x;
			extra=temp/11;
			place=place+extra;
        	if(place>10)
            	place=place-11;
            data[place]=temp;
		}
    }
}

int main() {
	int i;
	for(i=0; i<11; i++)
		data[i]=-1;
	
	hash(27);
	hash(18);
	hash(29);
	hash(28);
	hash(39);
	hash(13);
	
	for(i=0; i<11; i++) {
		printf("%d\n", data[i]);
	}
	
	return 0;
}
