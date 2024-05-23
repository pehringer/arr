Library builds on top of the C Standared Library to provide generic data structures.
  
[```void* arr_New(size_t size, int length, int (*compare)(const void*, const void*))```](#arr_New)  
[```void  arr_Delete(void *array)```](#arr_Delete)  
[```int   arr_Length(void *array)```](#arr_Length)  
[```void* arr_Resize(void *array, int length)```](#arr_Resize)  
[```void  arr_Copy(void *array, int start, int stop, const void *source)```](#arr_Copy)  
[```void  arr_Fill(void *array, int start, int stop, const void *source)```](#arr_Fill)  
[```int   arr_Max(void *array, int start, int stop)```](#arr_Max)  
[```int   arr_Min(void *array, int start, int stop)```](#arr_Min)  
[```int   arr_Count(void *array, int start, int stop, const void *target)```](#arr_Count)  
[```int   arr_Index(void *array, int start, int stop, const void *target)```](#arr_Index)  
[```void  arr_Sort(void *array, int start, int stop)```](#arr_Sort)  
# arr_New
```
void* arr_New(size_t size, int length, int (*compare)(const void*, const void*))
```
# arr_Delete
```
void arr_Delete(void *array)
```
# arr_Length
```
int arr_Length(void *array)
```
# arr_Resize
```
void* arr_Resize(void *array, int length)
```
# arr_Copy
```
void arr_Copy(void *array, int start, int stop, const void *source)
```
# arr_Fill
```
void arr_Fill(void *array, int start, int stop, const void *source)
```
# arr_Max
```
int arr_Max(void *array, int start, int stop)
```
# arr_Min
```
int arr_Min(void *array, int start, int stop)
```
# arr_Count
```
int arr_Count(void *array, int start, int stop, const void *target)
```
# arr_Index
```
int arr_Index(void *array, int start, int stop, const void *target)
```
# arr_Sort
```
void arr_Sort(void *array, int start, int stop)
```
