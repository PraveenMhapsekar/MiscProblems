#include <stdio.h>

int
fibonacci(int N) {
  int i = 0;
  int t1 = 0;
  int t2 = 1;
  int next = 0;
  for (i = 0; i < N; i++) {
    printf("%d ", t1);
    next = t1 + t2;
    t2 = t1;
    t1 = next;
  }
}

int
main () {
 fibonacci(11);

 return 0;
}
