#include <stdio.h>


int data[10];
int place=0;
int extra=0;
int quotient=0;


void hash(int x) {
    if(quotient==0)
        place=x%11;
    if(data[place]==-1) {
            data[place]=x;
            quotient=0;
    }
    else {
        extra=x/11;
        place=place+extra;
        if(place>10)
            place=place-11;
        quotient=1;
        hash(x);
    }
}


int main()
{
    int i;
    for(i=0;i<11;i++)
        data[i]=-1;
    hash(27);
    hash(18);
    hash(29);
    hash(28);
    hash(39);
    hash(13);
    hash(16);
    
    for(i=0;i<11;i++)
        printf("%d\n", data[i]);


    return 0;
}
