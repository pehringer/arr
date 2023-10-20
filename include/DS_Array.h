#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

/*
Memory Allocation Format
========================

+-------+ <-- Header is located at the start of the allocation.
|DS     |
|Struct |
|       |
+-------+ <-- Data is located after header in the allocation (pointer to
|Index 0|     data is retured by DS_ArrayNew and DS_ArrayResize functions).
+-------+
|Index 1|
+-------+
|Index 2|
+-------+
|Index 3|
+-------+
| ...   |
+-------+
|Index N|
+-------+
*/

struct DS_Array {
    int (*compare)(const void*, const void*); // Compare two elements.
    int length;                               // Number of elements in allocation.
    size_t size;                              // Size of element.
};

//Allocation And Configuration

void* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*));

void DS_ArrayDelete(void *array);

int DS_ArrayLength(void *array);

void* DS_ArrayResize(void *array, int length);

//Accessors

void DS_ArrayCopy(void *array, int start, int stop, const void *source);

void DS_ArrayFill(void *array, int start, int stop, const void *source);

//Search

int DS_ArrayMax(void *array, int start, int stop);

int DS_ArrayMin(void *array, int start, int stop);

int DS_ArrayCount(void *array, int start, int stop, const void *target);

int DS_ArrayIndex(void *array, int start, int stop, const void *target);

//Sort

void DS_ArraySort(void *array, int start, int stop);

#endif
