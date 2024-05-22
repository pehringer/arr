Library builds on top of the C Standared Library to provide generic data structures.

[here](#ds_arrayallocate)

# DS_ArrayAllocate
```
void* DS_ArrayAllocate(size_t size, int length, int (*compare)(const void*, const void*))
```
# DS_ArrayDeallocate
```
void DS_ArrayDeallocate(void *array)
```
# DS_ArrayLength
```
int DS_ArrayLength(void *array);
```
# DS_ArrayReallocate
```
void* DS_ArrayReallocate(void *array, int length)
```
# DS_ArrayCopy
```
void DS_ArrayCopy(void *array, int start, int stop, const void *source)
```
# DS_ArrayFill
```
void DS_ArrayFill(void *array, int start, int stop, const void *source)
```
# DS_ArrayMax
```
int DS_ArrayMax(void *array, int start, int stop)
```
# DS_ArrayMin
```
int DS_ArrayMin(void *array, int start, int stop)
```
# DS_ArrayCount
```
int DS_ArrayCount(void *array, int start, int stop, const void *target)
```
# DS_ArrayIndex
```
int DS_ArrayIndex(void *array, int start, int stop, const void *target)
```
# DS_ArraySort
```
void DS_ArraySort(void *array, int start, int stop)
```
