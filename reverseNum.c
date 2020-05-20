#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int A) {
	long long int a = 0;
	long long int b = abs(A);
	while (b != 0)
	{
		a *= 10;
		a += (b%10);
		b /= 10;
	}

	if (A < 0)
		a *= -1;
	if (a > INT_MAX || a < INT_MIN)
		return 0;

  return a;
}


int
main() {
  int i =  -234567;
  printf("num: %d\t, reverese num =%d\t:", i, reverse(i));
  return 0;

}
