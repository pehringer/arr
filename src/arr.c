#include "arr.h"

/*
Memory Allocation Format
========================

+---------+ <- Allocation start.
|Struct   |
|arr      |
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

struct arr {
    int (*compare)(const void*, const void*); // Compare two elements.
    int length;                               // Number of elements in allocation.
    size_t size;                              // Size of element.
};

void* arr_New(size_t size, int length, int (*compare)(const void*, const void*)) {
    struct arr *a = malloc(sizeof(struct arr) + length * size);
    if(a == 0) {
        return 0;
    }
    a->compare = compare;
    a->length = length;
    a->size = size;
    return a + 1;
}

void arr_Delete(void* array) {
    struct arr *a = (struct arr*) array - 1;
    free(a);
}

int arr_Length(void* array) {
    struct arr *a = (struct arr*) array - 1;
    return a->length;
}

void* arr_Resize(void *array, int length) {
    struct arr *a = (struct arr*) array - 1;
    a = realloc(a, sizeof(struct arr) + length * a->size);
    if(a == 0) {
        return 0;
    }
    a->length = length;
    return a + 1;
}

void arr_Copy(void *array, int start, int stop, const void *source) {
    struct arr *a = (struct arr*) array - 1;
    array = array + start * a->size;
    while(start < stop) {
        memcpy(array, source, a->size);
        array += a->size;
        source += a->size;
        start++;
    }
}

void arr_Fill(void *array, int start, int stop, const void *source) {
    struct arr *a = (struct arr*) array - 1;
    array = array + start * a->size;
    while(start < stop) {
        memcpy(array, source, a->size);
        array += a->size;
        start++;
    }
}

int arr_Max(void *array, int start, int stop) {
    struct arr *a = (struct arr*) array - 1;
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

int arr_Min(void *array, int start, int stop) {
    struct arr *a = (struct arr*) array - 1;
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

int arr_Count(void *array, int start, int stop, const void *target) {
    struct arr *a = (struct arr*) array - 1;
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

int arr_Index(void *array, int start, int stop, const void *target) {
    struct arr *a = (struct arr*) array - 1;
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

void arr_Sort(void *array, int start, int stop) {
    struct arr *a = (struct arr*) array - 1;
    qsort(array + start * a->size, stop - start, a->size, a->compare);
}
