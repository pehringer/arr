#ifndef DS_ARRAY_H
#define DS_ARRAY_H

#include <stdlib.h>
#include <string.h>

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
