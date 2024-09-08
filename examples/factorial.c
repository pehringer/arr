#include <stdio.h>
#include "arr.h"

int factorial(int number) {
  int *n = arr_Create(0, sizeof(int));
  for(int i = 2; i <= number; i++) {
    n = arr_Append(n, &i, 1);
  }
  number = 1;
  for(int i = 0; i < arr_Length(n); i++) {
    number *= n[i];
  }
  arr_Destroy(n);
  return number;
}

int main(void) {
  printf("1! = %d\n", factorial(1));
  printf("2! = %d\n", factorial(2));
  printf("3! = %d\n", factorial(3));
  printf("4! = %d\n", factorial(4));
  printf("5! = %d\n", factorial(5));
  printf("6! = %d\n", factorial(6));
  return 0;
}
