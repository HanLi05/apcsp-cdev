#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 1.1;
  float e = 1.2;
  float* ptrtod = &d;
  float* ptrtoe = &e;

  printf("The value of d is %f\n", d);
  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("The vaule of e is %f\n", e);
  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);

  float tmp = *ptrtod;
  *ptrtod = e;
  *ptrtoe = tmp;
  printf("Value of d is now %f and value of e is now %f\n", *ptrtod, *ptrtoe);
}
