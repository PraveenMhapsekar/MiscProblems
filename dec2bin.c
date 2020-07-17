#include <stdio.h>
/**
 * @input A : Integer
 * 
 * @Output string. Make sure the string ends with null character
 */
char* findDigitsInBinary(int A) {
	static char R[20] = {'\0'};
	int N = 0;
	int tmp = 1;
	int k = 0;
	int i;

  /* find N ==> higesht power of 2  such that tmp = 2^n < A */	
	do {
		tmp = tmp << 1;
		N++;
	} while (tmp <= A);
	 
	N--;

  /* Subtract 2^i (i --> N to 0) from A
     if there is remainder after this substraction set R[k] to 1 else 0
   */ 
	while (N >= 0) {
		if (A - (1 << N)) {
      printf("%d\n", 1 << N);
			A = A - (1 << N);
			R[k++] = '1';
		} else {
			R[k++] = '0';
		}
		N--;
  }
	 
	R[k] = '\0'; /* Terminate array */
	
	return R;
}

int
main() {
	int N = 32;
	int i;
	for (i = 0; i < N; i++) {
	  printf("Decimal %d \t==> Binary = %s\n", i, findDigitsInBinary(i));
	}

	return 0;
}
