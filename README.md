Tired of writing the same old allocation and reallocation code whenever you want a dynamic array in C?
Sick of having a separate variable to keep track of your array's length?
This library offers simple dynamic arrays that are:
- Easy to use (behaves like normal a array)
- Intuitive (library only has five functions)
- Lightweight (less than 50 lines of source code) 
- Generic (can hold any kind of data)
- Portable (only uses the C standard library)
- Performant (memory aligned elements and small headers)

# arr_Init
```
void* arr_Init(size_t len, size_t size)
```
# arr_Free
```
void arr_Free(void *arr)
```
# arr_Len
```
size_t arr_Len(const void *arr)
```
# arr_Size
```
size_t arr_Size(const void *arr)
```
# arr_App
```
void* arr_App(void *arr, const void *src, size_t len)
```
