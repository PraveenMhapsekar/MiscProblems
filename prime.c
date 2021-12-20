#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
bool
isPrime(int A) {
	int i;
	if ( A < 1) 
    return 0;
	
	if (A == 1)
		return 0;

  // 2 to N-1, for all i < N, if N is divisible by i then number in not Prime number. 					
	for (i = 2; i < A / 2; i++) {
		if ((A % i) == 0) {
			return false;
		}
	}
	return true;
}

/*
  Mark all i (0 to N) prime.
  0 - is not prime
  1 - is not prime
  2 - N : If (N % i) == 0 , all multiples of i are not prime
*/
void
printPrime(int N) {
  bool A[N];
  int i;
  int k;

  // Handle Base cases
  A[0] = false;
  A[1] = false;
  // Set all numbers as prime 
  for (i = 0; i < N; i++) {
    A[i] = isPrime(i);
  }

#if 0
  for (i = 2; i < N; i++) {
    if ((N % i) == 0) {
      k = i;
      // mark all multiples of i as non-prime
      do {
			  k = k + i;
        A[k] = false;
      } while (k < N);
    }
  }
#endif
  // Print prime numbers
  for (i = 0; i < N; i++) {
    if (A[i] == true) {
      printf("%d ", i);
    }
  }

  printf("\n");

  return;
}

int 
main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Error in input\n"); 
    return 0;
  }

  int i = atoi(argv[1]); //500;
  printPrime(i);
  return 0;
}
