#include <stdio.h>



int 
main() {
  
  int X = 0xAABBCCDD;
  char *p = (char *)&X;
  if (*p == 0xAA)
     printf("bigEndian\n");
  else
     printf("littleEndian\n");


  return 0;
}
