#include "DS_Array.h"

/*
Memory Allocation Format
========================

+---------+ <- Allocation start.
|Struct   |
|DS_Array |
|         |
+---------+ <- Pointer retured by DS_ArrayAllocate() and DS_ArrayReallocate() functions.
|Element 0|
+---------+
|Element 1|
+---------+
|Element 2|
+---------+
|Elemant 3|
+---------+
| ...     |
+---------+
|Element N|
+---------+ <- Allocation end.

*/

struct DS_Array {
    int (*compare)(const void*, const void*); // Compare two elements.
    int length;                               // Number of elements in allocation.
    size_t size;                              // Size of element.
};

void* DS_ArrayAllocate(size_t size, int length, int (*compare)(const void*, const void*)) {
    struct DS_Array *a = malloc(sizeof(struct DS_Array) + length * size);
    if(a == 0) {
        return 0;
    }
    a->compare = compare;
    a->length = length;
    a->size = size;
    return a + 1;
}

void DS_ArrayDeallocate(void* array) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    free(a);
}

int DS_ArrayLength(void* array) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    return a->length;
}

void* DS_ArrayReallocate(void *array, int length) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    a = realloc(a, sizeof(struct DS_Array) + length * a->size);
    if(a == 0) {
        return 0;
    }
    a->length = length;
    return a + 1;
}

void DS_ArrayCopy(void *array, int start, int stop, const void *source) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    array = array + start * a->size;
    while(start < stop) {
        memcpy(array, source, a->size);
        array += a->size;
        source += a->size;
        start++;
    }
}

void DS_ArrayFill(void *array, int start, int stop, const void *source) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    array = array + start * a->size;
    while(start < stop) {
        memcpy(array, source, a->size);
        array += a->size;
        start++;
    }
}

int DS_ArrayMax(void *array, int start, int stop) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    void *max = 0;
    int index = -1;
    array = array + start * a->size;
    while(start < stop) {
        if(max == 0 || a->compare(array, max) > 0) {
            max = array;
            index = start;
        }
        array += a->size;
        start++;
    }
    return index;
}

int DS_ArrayMin(void *array, int start, int stop) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    void *min = 0;
    int index = -1;
    array = array + start * a->size;
    while(start < stop) {
        if(min == 0 || a->compare(array, min) < 0) {
            min = array;
            index = start;
        }
        array += a->size;
        start++;
    }
    return index;
}

int DS_ArrayCount(void *array, int start, int stop, const void *target) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    int count = 0;
    array = array + start * a->size;
    while(start < stop) {
        if(a->compare(array, target) == 0) {
            count++;
        }
        array += a->size;
        start++;
    }
    return count;
}

int DS_ArrayIndex(void *array, int start, int stop, const void *target) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    array = array + start * a->size;
    while(start < stop) {
        if(a->compare(array, target) == 0) {
            return start;
        }
        array += a->size;
        start++;
    }
    return -1;
}

void DS_ArraySort(void *array, int start, int stop) {
    struct DS_Array *a = (struct DS_Array*) array - 1;
    qsort(array + start * a->size, stop - start, a->size, a->compare);
}
