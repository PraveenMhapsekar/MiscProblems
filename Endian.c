#include <stdio.h>

int 
main() 
{
	int X = 0xAABBCCDD;
	char *p = (char *)&X; // *p is pointing to the lowest address
	if (*p == 0xAA) {
		 printf("bigEndian\n"); // Higher Byte Save at Lowest Address
	 } else {
		 printf("littleEndian\n");
   }

	return 0;
}
