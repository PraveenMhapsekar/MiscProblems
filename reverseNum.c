#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int 
reverse(int A) {
	long long int a = 0;
	long long int b = abs(A);

	while (b != 0) {
		a = a * 10; // multiply by 10 i.e left shift to next digit
		a = (a + (b % 10)); // Extract and add last digit
		b = b / 10; // Divide number by 10
	}

  // Take care of sign
	if (A < 0) {
		a = a * -1;
  }

	if (a > INT_MAX || a < INT_MIN) {
		return 0;
  }

  return a;
}

int
main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Input error\n");
    return 1;
  }

  int i = atoi(argv[1]);

  printf("num: %d, reverese num = %d\n", i, reverse(i));
  return 0;
}
