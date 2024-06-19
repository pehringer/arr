# arr - Array
Tired of writing the same old allocation and reallocation code whenever you want a dynamic array in C?
Sick of having a separate variable to keep track of your array's length?
This library offers simple dynamic arrays that are:
- Easy to use  (library only has five functions)
  + [```void* arr_Init(size_t len, size_t size)```](#void-arr_initsize_t-len-size_t-size)
  + [```void arr_Free(void *arr)```](#void-arr_freevoid-arr)
  + [```size_t arr_Len(const void *arr)```](#size_t-arr_lenconst-void-arr)
  + [```size_t arr_Size(const void *arr)```](#size_t-arr_sizeconst-void-arr)
  + [```void* arr_App(void *arr, const void *src, size_t len)```](#void-arr_appvoid-arr-const-void-src-size_t-len)
- Intuitive (behaves like normal a array)
- Lightweight (less than 50 lines of source code) 
- Generic (can hold any kind of data)
- Portable (only uses the C standard library)
  + ```stdlib.h```
  + ```stddef.h```
  + ```string.h```
  + ```math.h```
- Performant (memory aligned elements and small header)
  + Memory Diagram:
    ```
    ________________________________________________________
    | HEADER | ALIGNMENT PADDING | 0 | 1 | 2 |  . . .  | N |
    |________|___________________|___|___|___|_________|___|
    
    ```
## Example Code
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
  printf("(bytes used: %d)\n", arr_Len(n) * arr_Size(n));
  arr_Free(n);
  return number;
}

int main(void) {
  printf("%d\n", factorial(12));
  return 0;
}
```
## ```void* arr_Init(size_t len, size_t size)```
Allocates and returns array.
NULL returned if failed to allocate. 
- ```len``` length of array.
- ```size``` size of data type.
## ```void arr_Free(void *arr)```
Deallocates array.
- ```arr``` array returned by arr_Init
## ```size_t arr_Len(const void *arr)```
Returns arrays length.
- ```arr``` array returned by arr_Init
## ```size_t arr_Size(const void *arr)```
Returns arrays data type size.
- ```arr``` array returned by arr_Init
## ```void* arr_App(void *arr, const void *src, size_t len)```
Reallocates and returns array with source elements appended.
NULL returned if failed to reallocate.
- ```arr``` array returned by arr_Init
- ```src``` source array to be copied
- ```len``` length of src

