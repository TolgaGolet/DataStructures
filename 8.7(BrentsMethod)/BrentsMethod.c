#include <stdio.h>


int data[10];
int place=0;
int move=0;
int collision=0;


void hash(int x) {
    if(collision==0)
        place=x%11;
    if(data[place]==-1) {
            data[place]=x;
            collision=0;
    }
    else {
        move=x/11;
        place=place+move;
        if(place>10)
            place=place-11;
        collision=1;
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
