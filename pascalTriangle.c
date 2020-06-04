#include <stdio.h>
#include <stdlib.h>

int** pascal(int A) {
	int **ptr;
	int i;
	int j;
  int *tptr;
  ptr = (int **)malloc(A*sizeof(int)); //, sizeof(int));
	if (!ptr) { printf("!ERRR\n"); return NULL; }

  for (i = 0; i < A; i++) {
    tptr = (int *)malloc(A*sizeof(int));
    if (tptr == NULL) {
      printf("memory allocation failed \n");
    } else {
      printf("%d --> %p\n", i, tptr);
      ptr[i] = tptr;
    }
  }

	for (i = 0; i < A; i++) {
		for (j = 0; j <= i; j++) {
			if ((i == j) || (j == 0) || (i == 0)) {
			  ptr[i][j] = 1;
			  printf ("%d ", 1);
			} else {
			  ptr[i][j] = ptr[i-1][j-1] + ptr[i-1][j];
			  printf ("%d ", ptr[i][j]);
			}
		}
		printf("\n");
	}
  return ptr;
}

int
main() {
  int **p;
  int i, j, len1 = 6, len2 = 4;
  int k = 18;
  p = pascal(k);
  if (!*p) return 0;
#if 0
   for (i = 0; i < len1; i++) {
     for(j = 0; j < len2; j++) {
           printf(" %d ", ptr[i][j]);
      }
      printf("\n");
    }
    printf("\n");
#endif
  return 0;
}
