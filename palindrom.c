#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool
isPalindrome(char *n) {
	char *l = n;
	char *r = l + (strlen(n) - 1);

	while (l < r) {
			if (*l ^ *r) {
				 return false;
			}
			l++;
			r--;
	}
  return true;
}

int
main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Input error \n");
    return 0;
  }
	char *N = argv[1];
	printf("palindrome %s\n", isPalindrome(N) == true ? "true" : "false");
	return 0;
}

