#include<stdio.h>

int main()
{
  int a = 545;
  char b = 'f';
  float c = 1.4;
  double d = 1.414;
  unsigned int i = 1;
  short int j = 4; 

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));
  printf("unsigned int i value: %d and size: %lu bytes\n", i, sizeof(i));
  printf("short int j value: %d and size: %lu bytes\n", j, sizeof(j));
}

