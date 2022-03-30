#include <stdio.h>
#include <stdlib.h>

int** pascal(int A) {
	int i, j;
  int *tptr;
	int **ptr =  NULL;

  if (A == 0) return ptr;

	ptr = (int **)malloc(A*sizeof(tptr)); //, sizeof(int));
	if (!ptr) {
		printf("!ERRR\n"); return NULL; 
	}

  // Allocate space for rows;
  for (i = 0; i < A; i++) {
    ptr[i] = (int *)malloc(A*sizeof(int));
    if (ptr[i] == NULL) {
      printf("memory allocation failed \n");
    }
  }

  // Print Pascal's triangle
	for (i = 0; i < A; i++) { // number of rows
		for (j = 0; j <= i; j++) { // number of columns equal to row number
			if ((i == j) || (j == 0) ) { // first and last column is always 1
			  ptr[i][j] = 1;
			} else {
			  ptr[i][j] = ptr[i-1][j-1] + ptr[i-1][j];
			}
			printf ("%d ", ptr[i][j]);
		}
		printf("\n");
	}

  return ptr;
}

int
main(int argc, char **argv) {
  int **p = NULL;
  int i, j, len1 = 6, len2 = 4;
	if (argc != 2) {
    printf("wrong argumnet\n");
    return 0;
  }

  int k = atoi(argv[1]);
  p = pascal(k);
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
