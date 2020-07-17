#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int i);
/**
 * @input A : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* 
allFactors(int A, int *len1) {
	int K[5000];
	int i;
	int cnt = 0;
	int *retArr;
	if (A == 0) {
		*len1 = 0;
		return NULL; 
	}
	for (i = 1; i <= A/2; i++) {
		if ((A % i) == 0) {
			K[cnt++] = i;   
		}
	}
	K[cnt] = A;
	retArr = malloc(cnt * sizeof(int));
	for (i = 0; i < cnt; i++) {
		retArr[i] = K[i];
	}
	
	*len1 = cnt;
  //  printf("len = %d\n", *len1);
	return retArr;
}

bool
isPrime(int N) {
  int i;
  if (N < 2) {
    return false;
  } else {
    for (i = 2; i < N; i++) {
      if ((N % i) == 0) {
        return false;
      }
    }
    return true;  
  }
}

int* 
primeFactors(int A, int *len1) {
	int K[5000];
	int i;
	int cnt = 0;
	int *retArr;

  /* if NULL array , return */
	if (A == 0) {
		*len1 = 0;
		return NULL; 
	}

  /* for i = 1 -> N/2
       if N / i division results into remainder zero, i is factor of N
       check if 'i' is prime number ( if this number can be divided only by 1 and number itself)
   */
	for (i = 1; i <= A/2; i++) {
		if ((A % i) == 0) {
      if (isPrime(i)) {
		  	K[cnt++] = i;   
      }
		}
	}

	K[cnt] = A;
	retArr = malloc(cnt * sizeof(int));
	for (i = 0; i < cnt; i++) {
		retArr[i] = K[i];
	}
	
	*len1 = cnt;
  //  printf("len = %d\n", *len1);
	return retArr;
}

int
main() {
  int max = 32;
  int len;
  int * arr;
  for (int i = 1; i < max; i++) {
		printf("Factors of %d \t:", i);
		//arr = allFactors(i, &len);

		arr = primeFactors(i, &len);
		if (arr != NULL) {
			for (int k = 0; k < len; k++) {
				printf(" %d ", arr[k]);
			}
			free(arr);
		}
		printf("\n");
  }
}

