Tired of writing the same old allocation and reallocation code whenever you want a dynamic array in C?
Sick of having a separate variable to keep track of your array's length?
This library offers simple dynamic arrays that are:
- Easy to use  (library only has five functions)
- Intuitive (behaves like normal a array)
- Lightweight (less than 50 lines of source code) 
- Generic (can hold any kind of data)
- Portable (only uses the C standard library)
- Performant (memory aligned elements and small header)
## Example code
```

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

