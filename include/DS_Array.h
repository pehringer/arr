#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct DS_Array {
    void *base;
    int (*compare)(const void*, const void*);
    int length;
    size_t size;
};

struct DS_Array* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*));

void DS_ArrayDelete(struct DS_Array *a);

struct DS_Array* DS_ArrayResize(struct DS_Array *a, int length);

void* DS_ArrayAt(struct DS_Array *a, int index);

void DS_ArrayCopy(struct DS_Array *a, int start, int end, const void *array);

int DS_ArrayCount(struct DS_Array *a, int start, int end, const void *value);

void DS_ArrayFill(struct DS_Array *a, int start, int end, const void *value);

int DS_ArrayIndex(struct DS_Array *a, int start, int end, const void *value);

int DS_ArrayLength(struct DS_Array *a);

void* DS_ArrayMax(struct DS_Array *a, int start, int end);

void* DS_ArrayMin(struct DS_Array *a, int start, int end);

#endif
