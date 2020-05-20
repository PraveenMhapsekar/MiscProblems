#include <stdio.h>
#include <stdlib.h>


int uniquePaths(int A, int B) {
    
    if ((A == 1) || (B == 1)) return 1;
    else 
    return(uniquePaths(A-1, B) + uniquePaths(A, B -1));
}


int
main() {

   printf("unique paths %d\n", uniquePaths(8, 8));

}
