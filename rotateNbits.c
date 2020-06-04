#include <stdio.h>


int rotate(int *A, int n) {
	int arr[n];
	int k = n - 1;
	int temp;
	int i;
	for (i = 0; i < n; i++) {
	 memcpy(&temp, &A[i], 4);
	 wordRotate(&temp, 32);
	 arr[k--] = temp;
	}

	for (i = 0; i < n; i++) {
	 memcpy(A+i, &arr[i], 4);
	}
}

int
wordRotate(unsigned int *A, int n) {
	int x = *A;
	int temp;
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	temp = ((x >> 16) | (x << 16));
	*A = temp;
  return 0;
}

int
main () {
 int i; 
 int N[3] = {1, 2, 3};
//	N = 1 << i;
//		printf(" N = 0x%x ", N);
		rotate(N, 3);
 // }

  for (i = 0; i < 3; i++) {
		printf("rotated number = 0x%2x\n", N[i]);
  }

  return 0;
}
