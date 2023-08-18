#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct DS_Array {
    void *array;                              // Existing array.
    int (*compare)(const void*, const void*); // Compare two elements.
    size_t size;                              // Size of element.
};

struct DS_Array DS_ArrayInit(void* array, int (*compare)(const void*, const void*), size_t size);

void DS_ArrayFill(struct DS_Array a, int start, int stop, const void *source);

void DS_ArraySet(struct DS_Array a, int start, int stop, const void *source);

void DS_ArrayGet(struct DS_Array a, int start, int stop, void *destination);

int DS_ArrayCount(struct DS_Array a, int start, int stop, const void *target);

int DS_ArrayFirst(struct DS_Array a, int start, int stop, const void *target);

int DS_ArrayLast(struct DS_Array a, int start, int stop, const void *target);

int DS_ArrayMax(struct DS_Array a, int start, int stop);

int DS_ArrayMin(struct DS_Array a, int start, int stop);

void DS_ArraySort(struct DS_Array a, int start, int stop);

#endif
