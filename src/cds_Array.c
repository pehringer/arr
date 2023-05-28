#include "cds_Array.h"

void* cds_ArrayConstruct(struct cds_Array *a, int sizeOf, int length) {
    if((a->base = malloc(sizeOf * length)) == 0) {
      return 0;
    }
    a->length = length;
    a->sizeOf = sizeOf;
    return a;
}

void* cds_ArrayResizeOf(struct cds_Array *a, int length) {
    if((a->base = realloc(a->base, a->sizeOf * length)) == 0) {
      return 0;
    }
    a->length = length;
    return a;
}

void cds_ArrayDestruct(struct cds_Array *a) {
    free(a->base);
    a->base = 0;
    a->length = 0;
    a->sizeOf = 0;
}

int cds_ArrayLength(struct cds_Array *a) {
    return a->length;
}

void* cds_ArrayAt(struct cds_Array *a, int index) {
    return a->base + a->sizeOf * index;
}

void* cds_ArrayCopy(struct cds_Array *a, int index, void *values, int length) {
    memcpy(a->base + a->sizeOf * index, values, a->sizeOf * length);
    return a;
}

void* cds_ArrayFill(struct cds_Array *a, int index, void *value, int length) {
    void* element = a->base + a->sizeOf * index;
    while(length > 0) {
        memcpy(element, value, a->sizeOf);
        element += a->sizeOf;
        length--;
    }
    return a;
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

void* cds_ArraySort(struct cds_Array *a, int (*compare)(const void*, const void*)) {
    qsort(a->base, a->length, a->sizeOf, compare);
    return a;
}

void* cds_ArrayBinarySearch(struct cds_Array *a, void *value, int (*compare)(const void*, const void*)) {
    return bsearch(value, a->base, a->length, a->sizeOf, compare);
}

#include<stdio.h>
void main() {
    printf("Hello, friend.\n");
}
