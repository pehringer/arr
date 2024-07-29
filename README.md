# ***arr*** - ***ARR***ay
Tired of writing the same old allocation and reallocation code whenever you want to resize arrays in C? Sick of having separate variables to keep track of your array's length? This library offers arrays with a few extra features bolted on.
- Easy to Use (library only has four functions)
  + [```void* arr_Init(const size_t ele, const size_t len)```](#void-arr_initconst-size_t-ele-const-size_t-len)
  + [```void arr_Free(void *arr)```](#void-arr_freevoid-arr)
  + [```size_t arr_Len(const void *arr)```](#size_t-arr_lenconst-void-arr)
  + [```void* arr_App(void *arr, const void *src, size_t len)```](#void-arr_appvoid-arr-const-void-src-const-size_t-len)
- Generic (can hold any kind of data)
- Intuitive (behaves like normal a array)
- Lightweight (less than 50 lines of source code) 
- Performant (memory aligned elements)
  + Memory Diagram:
    ```
    ________________________________________________
    | ARR    | PADDING   | ELEMENT | ... | ELEMENT |       
    | STRUCT | ALIGNMENT | 0       |     | N       |
    |________|___________|_________|_____|_________|
                         ^
                         |
    arr_Init / arr_App return a pointer to the first element
    ```
- Portable (only uses the C standard library)
  + ```stdlib.h```
  + ```stddef.h```
  + ```string.h```
  + ```math.h```
- Resizable (can grow in length)
# Example Code
Compute factorial using a dynamic array:
```
#include <stdio.h>
#include "arr.h"

int factorial(int number) {
  int *n = arr_Init(0, sizeof(int));
  for(int i = 2; i <= number; i++) {
    n = arr_App(n, &i, 1);
  }
  number = 1;
  for(int i = 0; i < arr_Len(n); i++) {
    number *= n[i];
  }
  arr_Free(n);
  return number;
}

int main(void) {
  printf("%d\n", factorial(12));
  return 0;
}
```
Compile and execute:
```
$ gcc -I ./arr/include ./arr/arr.so main.c
$ ./a.out
479001600
```
# Library Functions
---
### ```void* arr_Init(const size_t ele, const size_t len)```
Allocates and returns array.  
Returns NULL if allocation failed.  
- ```ele``` size of element type.
- ```len``` length of array.
---
### ```void arr_Free(void *arr)```
Deallocates array.  
- ```arr``` array returned by arr_Init.
---
### ```size_t arr_Len(const void *arr)```
Returns arrays length.  
- ```arr``` array returned by arr_Init.
---
### ```void* arr_App(void *arr, const void *src, const size_t len)```
Reallocates and returns array with source elements appended.  
Returns NULL if reallocation failed.  
- ```arr``` array returned by arr_Init.
- ```src``` source array to be copied.
- ```len``` length of src.
---
