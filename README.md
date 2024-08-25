# ***arr*** - ***ARR***ay
Tired of writing the same old allocation and reallocation code whenever you want to resize arrays in C? Sick of having separate variables to keep track of your array's length? This library offers arrays with a few extra features bolted on.
- Easy to Use (library only has four functions)
  + [```void* arr_Create(size_t length, size_t size)```](#void-arr_createsize_t-length-size_t-size)
  + [```void arr_Destory(void *array)```](#void-arr_destroyvoid-array)
  + [```size_t arr_Length(const void *array)```](#size_t-arr_lengthconst-void-array)
  + [```void* arr_Append(void *array, const void *source, size_t length)```](#void-arr_appendvoid-array-const-void-source-size_t-length)
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
    arr_Create / arr_Append return a pointer to the first element
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
### ```void* arr_Create(size_t length, size_t size)```
Allocates and returns array.  
Returns NULL if allocation failed.  
- ```length``` length of array.
- ```size``` size of element type.
---
### ```void arr_Destroy(void *array)```
Deallocates array.  
- ```array``` array returned by arr_Create.
---
### ```size_t arr_Length(const void *array)```
Returns arrays length.  
- ```array``` array returned by arr_Create.
---
### ```void* arr_Append(void *array, const void *source, size_t length)```
Reallocates and returns array with source elements appended.  
Returns NULL if reallocation failed.  
- ```array``` array returned by arr_Create.
- ```source``` source array to be copied.
- ```length``` length of source.
---
