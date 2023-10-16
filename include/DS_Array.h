#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

/*
Memory Allocation Format
========================

+-------+ <-- Header is located at the start of the allocation (pointer to
|DS     |     struct is retured by Alloc and Realloc functions).
|Struct |
|       |
+-------+ <-- Data is located after header in the allocation.
|Index 0|
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

struct DS_Array* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*));

void DS_ArrayDelete(struct DS_Array *a);

int DS_ArrayLength(struct DS_Array *a);

struct DS_Array* DS_ArrayResize(struct DS_Array *a, int length);

//Accessors

void* DS_ArrayAt(struct DS_Array *a, int index);

void DS_ArrayGet(struct DS_Array *a, int index, void *destination);

void DS_ArraySet(struct DS_Array *a, int index, const void *source);

void DS_ArrayCopy(struct DS_Array *a, int start, int stop, const void *source);

void DS_ArrayFill(struct DS_Array *a, int start, int stop, const void *source);

//Search

int DS_ArrayMax(struct DS_Array *a, int start, int stop);

int DS_ArrayMin(struct DS_Array *a, int start, int stop);

int DS_ArrayCount(struct DS_Array *a, int start, int stop, const void *target);

int DS_ArrayIndex(struct DS_Array *a, int start, int stop, const void *target);

//Sort

void DS_ArraySort(struct DS_Array *a, int start, int stop);

#endif
