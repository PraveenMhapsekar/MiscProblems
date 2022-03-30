#include <stdio.h>

int
fibonacci(int N) {
  int i = 0;
  int f0 = 0;
  int f1 = 1;
  int f2;
  for (i = 0; i < N; i++) {
    printf("%d ", f0);
    f2 = f0 + f1;
    f0 = f1;
    f1 = f2;
  }
  printf("\n");
}

int
main ()
{
 fibonacci(11);
 return 0;
}
