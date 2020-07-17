#include <stdio.h>

int max(int x, int y) {
  return ((x > y) ? x : y); 
}

void
kadane(int *A, int n) {
  int max_ending_here = 0;
  int max_so_far = A[0];
  int i;
  int eIdx =  0;
  int idx = -1;
  int sIdx;

  for (i = 0; i < n; i++) {
    //   max_ending_here = max(A[i], A[i] + tmpMax);
    if (A[i] > (A[i] + max_ending_here)) {
      // if current element is greater than current val plus tmpmax (going from -ve sum to +ve)
      // - use current val
      // - start of new subArray
			idx = i;
      max_ending_here = A[i];
    } else {
      max_ending_here = A[i] + max_ending_here;
    }


    // New max_so_far?
    if (max_ending_here > max_so_far) {
      // new max_so_far
      max_so_far = max_ending_here;
      // update idx'es
      eIdx = i;
      sIdx = idx;
      printf("max_ending_here = %d, max_so_far = %d, sIdx = %d, eIdx = %d\n", max_ending_here, max_so_far,  sIdx, eIdx);
    }
  }  // end of array

  // Print results
  printf ("max_so_far = %d\n startIndx = %d endIdx = %d\n", max_so_far, sIdx, eIdx);
  for (i = sIdx; i <= eIdx; i++) {
    printf(" %d ", A[i]);
  }
  printf("\n");

  return;
}

// main function
int 
main() {
  int i;
  int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  //int arr[] = {  0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50 };
// 	int arr[] = { -2, -1, -3, -4, -1, -2, -1, -5, -4 };
	int n = sizeof(arr)/sizeof(arr[0]);

  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
	kadane(arr, n);

	return 0;
}
