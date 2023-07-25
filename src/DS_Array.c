#include "DS_Array.h"

struct DS_Array* DS_ArrayConstruct(size_t size, int length) {
    struct DS_Array *a = malloc(sizeof(struct DS_Array) + length * size);
    if(a == 0) {
        return 0;
    }
    a->length = length;
    a->size = size;
    return a;
}

void DS_ArrayDestruct(struct DS_Array *a) {
    free(a);
}

struct DS_Array* DS_ArrayRestruct(struct DS_Array *a, int length) {
    a = realloc(a, sizeof(struct DS_Array) + length * a->size);
    if(a == 0) {
        return 0;
    }
    a->length = length;
    return a;
}

void* DS_ArrayAt(struct DS_Array *a, int index) {
    return (void*) (a + 1) + index * a->size;
}

int DS_ArrayCount(struct DS_Array *a, int index, int length, const void *target, int (*compare)(const void*, const void*)) {
    void *element = (void*) (a + 1) + index * a->size;
    int count = 0;
    while(length > 0) {
        if(compare(element, target) == 0) {
            count++;
        }
        element += a->size;
        length--;
    }
    return count;
}

struct DS_Array* DS_ArrayFill(struct DS_Array *a, int index, int length, const void *source) {
    void *element = (void*) (a + 1) + index * a->size;
    while(length > 0) {
        memcpy(element, source, a->size);
        element += a->size;
        length--;
    }
    return a;
}

struct DS_Array* DS_ArrayFrom(struct DS_Array *a, int index, int length, const void *source) {
    void *element = (void*) (a + 1) + index * a->size;
    while(length > 0) {
        memcpy(element, source, a->size);
        element += a->size;
        source += a->size;
        length--;
    }
    return a;
}

int DS_ArrayIndex(struct DS_Array *a, int index, int length, const void *target, int (*compare)(const void*, const void*)) {
    void *element = (void*) (a + 1) + index * a->size;
    while(length > 0) {
        if(compare(element, target) == 0) {
            return index;
        }
        element += a->size;
        index++;
        length--;
    }
    return -1;
}

int DS_ArrayLen(struct DS_Array *a) {
    return a->length;
}

void* DS_ArrayMax(struct DS_Array *a, int index, int length, int (*compare)(const void*, const void*)) {
    void *element = (void*) (a + 1) + index * a->size;
    void *max = 0;
    while(length > 0) {
        if(max == 0 || compare(element, max) > 0) {
            max = element;
        }
        element += a->size;
        length--;
    }
    return max;
}

void* DS_ArrayMin(struct DS_Array *a, int index, int length, int (*compare)(const void*, const void*)) {
    void *element = (void*) (a + 1) + index * a->size;
    void *min = 0;
    while(length > 0) {
        if(min == 0 || compare(element, min) < 0) {
            min = element;
        }
        element += a->size;
        length--;
    }
    return min;
}

struct DS_Array* DS_ArraySort(struct DS_Array *a, int index, int length, int (*compare)(const void*, const void*)) {
    qsort((void*) (a + 1) + index * a->size, length, a->size, compare);
    return a;

}

struct DS_Array* DS_ArrayTo(struct DS_Array *a, int index, int length, void *destination) {
    void *element = (void*) (a + 1) + index * a->size;
    while(length > 0) {
        memcpy(destination, element, a->size);
        destination += a->size;
        element += a->size;
        length--;
    }
    return a;
}
