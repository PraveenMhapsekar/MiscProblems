#include <stdio.h>

int 
fib (int n) {
  int f0 = 0;
  int f1 = 1;
  int sum;

   while (n ) {
    printf("%d ", f0);
    sum = f0 + f1;
    f0 = f1;
    f1 = sum;
    n--;
   }
   printf("\n");
   return 0;
}

int main () {

 printf("5 is \n");
 fib(5);
 printf("6 is \n");
 fib(6);
 printf("0 is \n");
 fib(0);
 printf("1 is \n");
 fib(1);
 printf("2 is \n");
 fib(2);

  return 0;;

}
