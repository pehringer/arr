#include "cds_Array.h"

struct cds_Array* cds_ArrayConstruct(struct cds_Array *a, int size, int length) {
    a->first = malloc(size * length);
    if(a->first == 0) {
      return 0;
    }
    a->length = length;
    a->size = size;
    return a;
}

struct cds_Array* cds_ArrayResize(struct cds_Array *a, int length) {
    a->first = realloc(a->first, a->size * length);
    if(a->first == 0) {
      return 0;
    }
    a->length = length;
    return a;
}

struct cds_Array* cds_ArrayDestruct(struct cds_Array *a) {
    free(a->first);
    a->first = 0;
    a->length = 0;
    a->size = 0;
    return a;
}

struct cds_Array* cds_ArrayFromArray(struct cds_Array *a, int index, void *array, int length) {
    memcpy(a->first + a->size * index, array, a->size * length);
    return a;
}

struct cds_Array* cds_ArrayToArray(struct cds_Array *a, int index, void *array, int length) {
    memcpy(array, a->first + a->size * index, a->size * length);
    return a;
}

struct cds_Array* cds_ArrayFill(struct cds_Array *a, int index, void *value, int length) {
    void *element = a->first + a->size * index;
    while(length > 0) {
        memcpy(element, value, a->size);
        element += a->size;
        length--;
    }
    return a;
}

int cds_ArrayLength(struct cds_Array *a) {
    return a->length;
}

void* cds_ArrayAt(struct cds_Array *a, int index) {
    return a->first + a->size * index;
}

int cds_ArrayFirstIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*)) {
    void *element = a->first + a->size * index;
    while(index < a->length) {
        if(compare(element, value) == 0) {
            return index;
        }
        element += a->size;
        index++;
    }
    return -1;
}

int cds_ArrayLastIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*)) {
    void* element = a->first + a->size * index;
    while(index >= 0) {
        if(compare(element, value) == 0) {
            return index;
        }
        element -= a->size;
        index--;
    }
    return -1;
}

struct cds_Array* cds_ArraySort(struct cds_Array *a, int (*compare)(const void*, const void*)) {
    qsort(a->first, a->length, a->size, compare);
    return a;
}

int cds_ArrayBinarySearch(struct cds_Array *a, void *value, int (*compare)(const void*, const void*)) {
    value = bsearch(value, a->first, a->length, a->size, compare);
    if(value > 0) {
        return (value - a->first) / a->size;
    }
    return -1;
}
