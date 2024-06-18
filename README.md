Tired of writing the same old allocation and reallocation code whenever you want a dynamic array in C?
Sick of having a separate variable to keep track of your array's length?
This library offers simple dynamic arrays that are:
- Easy to use  (library only has five functions)
- Intuitive (behaves like normal a array)
- Lightweight (less than 50 lines of source code) 
- Generic (can hold any kind of data)
- Portable (only uses the C standard library)
- Performant (memory aligned elements and small header)
## ```void* arr_Init(size_t len, size_t size)```
Allocates and returns array
## ```void arr_Free(void *arr)```
Deallocated array (arr).
## ```size_t arr_Len(const void *arr)```
Returns arrays (arr) number of elements.
## ```size_t arr_Size(const void *arr)```
Returns arrays (arr) individual element size.
## ```void* arr_App(void *arr, const void *src, size_t len)```
Reallocates array (arr)
