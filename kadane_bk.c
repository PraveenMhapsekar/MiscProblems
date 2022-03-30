#include <stdio.h>

int max(int x, int y) {
  return ((x > y) ? x : y); 
}

void
kadane(int *A, int n) {
  int meh = 0; // Max Ending Here
  int msf = A[0]; // Max So Far
  int i;
  int eIdx =  0;
  int idx = -1;
  int sIdx;

  for (i = 0; i < n; i++) {
    //  meh = max(A[i], A[i] + meh)
    if (A[i] > (A[i] + meh)) {
      // if cur_val is greater than cur_val plus meh 
      // (aka, meh was negative and meh is about to transistion from -ve to +ve

      // record index
		 	sIdx = i;

      // reset meh
      meh = A[i];
    } else {
      meh = A[i] + meh;
    }

    if (meh > msf) {
      // new msf
      msf = meh;
      // update end idx
      eIdx = i;
    }
  }

  // Print results
  printf ("msf = %d\n", msf);
  for (i = sIdx; i <= eIdx; i++) {
    printf("A[%d] = %d \n", i,  A[i]);
  }
  printf("\n");

  return;
}

// main function
int 
main() {
  //int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
//  int arr[] = {  0, -461, -125, -404, -59, -322, -495, -288, -341, -449, -313, -192, -214, -389, -202, -183, -72, -416, -455, -187, -242, -416, 39, -198, -338, -465, -248, -25, -398, -97, -461, -214, -423, -407, -77, -190, -67, -178, -410, -160, 72, -350, -31, -85, -247, -319, -462, -303, -48, -354, -110, 17, 60, 19, 80, -218, -28, -426, -366, -140, 50 };
  	int arr[] = { -2, -1, -3, -4, -1, -2, -1, -5, -4 };
	int n = sizeof(arr)/sizeof(arr[0]);
  int i;
  printf ("input array\n");
  for (i = 0; i < n ; i++) {
    printf(" %d ", arr[i]);
  }
  printf("\n");

	kadane(arr, n);

	return 0;
}
