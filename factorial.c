#include <stdio.h>
#if 0
// recursive solution
int 
factorial(int N) {
  if (N < 2)
      return 1;
   return (N * factorial(N-1));
}
#endif

// iterative solution
int 
factorial(int N) {
  int fact = N;

  if (N < 1)
    return 1;

  while (N > 1) {
    fact = fact * (N - 1);
    N--;
  }

  return fact;
}

int 
main () {
  for (int i = 0; i < 6; i++) {
		printf("factorial of %d is %d\n", i, factorial(i));
  }
	return 0;
}
