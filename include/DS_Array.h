#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct DS_Array {
    int (*compare)(const void*, const void*);
    int length;
    size_t size;
};

struct DS_Array* DS_ArrayConstruct(size_t size, int length, int (*compare)(const void*, const void*));

void DS_ArrayDestruct(struct DS_Array *a);

struct DS_Array* DS_ArrayRestruct(struct DS_Array *a, int length);

void* DS_ArrayAt(struct DS_Array *a, int index);

int DS_ArrayCount(struct DS_Array *a, int start, int end, const void *value);

struct DS_Array* DS_ArrayFill(struct DS_Array *a, int start, int end, const void *value);

struct DS_Array* DS_ArrayFrom(struct DS_Array *a, int start, int end, const void *array);

int DS_ArrayIndex(struct DS_Array *a, int start, int end, const void *value);

int DS_ArrayLen(struct DS_Array *a);

void* DS_ArrayMax(struct DS_Array *a, int start, int end);

void* DS_ArrayMin(struct DS_Array *a, int start, int end);

struct DS_Array* DS_ArraySort(struct DS_Array *a, int start, int end);

struct DS_Array* DS_ArrayTo(struct DS_Array *a, int start, int end, void *array);

#endif
