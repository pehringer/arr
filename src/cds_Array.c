#include "cds_Array.h"

struct cds_Array* cds_ArrayConstruct(struct cds_Array *a, int sizeOf, int length) {
    if((a->base = malloc(sizeOf * length)) == 0) {
      return 0;
    }
    a->length = length;
    a->sizeOf = sizeOf;
    return a;
}

struct cds_Array* cds_ArrayResize(struct cds_Array *a, int length) {
    if((a->base = realloc(a->base, a->sizeOf * length)) == 0) {
      return 0;
    }
    a->length = length;
    return a;
}

struct cds_Array* cds_ArrayDestruct(struct cds_Array *a) {
    free(a->base);
    a->base = 0;
    a->length = 0;
    a->sizeOf = 0;
    return a;
}

struct cds_Array* cds_ArrayFromArray(struct cds_Array *a, int index, void *array, int length) {
    memcpy(a->base + a->sizeOf * index, array, a->sizeOf * length);
    return a;
}

struct cds_Array* cds_ArrayToArray(struct cds_Array *a, int index, void *array, int length) {
    memcpy(array, a->base + a->sizeOf * index, a->sizeOf * length);
    return a;
}

int cds_ArrayLength(struct cds_Array *a) {
    return a->length;
}

void* cds_ArrayAt(struct cds_Array *a, int index) {
    return a->base + a->sizeOf * index;
}

int cds_ArrayFirstIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*)) {
    void* element = a->base + a->sizeOf * index;
    while(index < a->length) {
        if(compare(element, value) == 0) {
            return index;
        }
        element += a->sizeOf;
        index++;
    }
    return -1;
}

int cds_ArrayLastIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*)) {
    void* element = a->base + a->sizeOf * index;
    while(index >= 0) {
        if(compare(element, value) == 0) {
            return index;
        }
        element -= a->sizeOf;
        index--;
    }
    return -1;
}

struct cds_Array* cds_ArraySort(struct cds_Array *a, int (*compare)(const void*, const void*)) {
    qsort(a->base, a->length, a->sizeOf, compare);
    return a;
}

void* cds_ArrayBinarySearch(struct cds_Array *a, void *value, int (*compare)(const void*, const void*)) {
    return bsearch(value, a->base, a->length, a->sizeOf, compare);
}
