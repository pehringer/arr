#include <stdio.h>
#include "arr.h"

int main(void) {
  int factorial = 12;
  int *n = arr_Create(0, sizeof(int));

  for(int i = 2; i <= factorial; i++) {
    n = arr_Append(n, &i, 1);
  }
  factorial = 1;
  for(int i = 0; i < arr_Length(n); i++) {
    factorial *= n[i];
  }

  arr_Destroy(n);
  printf("%d\n", factorial);
  return 0;
}

