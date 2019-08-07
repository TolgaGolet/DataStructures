#include<stdio.h>
 
int calculate_fibonacci(int i) {
	if(i==0) return 0;
    else if(i==1) return 1;
    else
      return (calculate_fibonacci(i-1)+calculate_fibonacci(i-2));
}
 
int main() {
   int n, i=0, c;  //Number, initializer,counter.
 
   printf("Enter the number of terms: ");
   scanf("%d",&n);
   printf("Fibonacci Series;\n");
 
   for (c=1;c<=n;c++)
   {
      printf("%d\n", calculate_fibonacci(i));
      i++; 
   }
 
   return 0;
} 
