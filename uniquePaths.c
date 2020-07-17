#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int X, int Y) {
	if ((X == 0) && (Y == 0)) {
    return 0; 
  }

	if ((X == 1) || (Y == 1)) {
    return 1;
	} else { 
		return (uniquePaths(X-1, Y) + uniquePaths(X, Y -1));
  }
}

int
main() {
  printf("unique paths %d\n", uniquePaths(8, 8));
  return 0;
}
