#include "DS_Array.h"

struct DS_Array* DS_ArrayConstruct(size_t size, int length, int (*compare)(const void*, const void*)) {
    struct DS_Array *a = malloc(sizeof(struct DS_Array) + length * size);
    if(a == 0) {
        return 0;
    }
    a->base = a + 1;
    a->compare = compare;
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
    a->base = a + 1;
    a->length = length;
    return a;
}

void* DS_ArrayAt(struct DS_Array *a, int index) {
    return (void*) (a + 1) + index * a->size;
}

int DS_ArrayCount(struct DS_Array *a, int start, int end, const void *value) {
    void *element = a + 1;
    element += start * a->size;
    int count = 0;
    while(start < end) {
        if(a->compare(element, value) == 0) {
            count++;
        }
        element += a->size;
        start++;
    }
    return count;
}

struct DS_Array* DS_ArrayFill(struct DS_Array *a, int start, int end, const void *value) {
    void *element = a + 1;
    element += start * a->size;
    while(start < end) {
        memcpy(element, value, a->size);
        element += a->size;
        start++;
    }
    return a;
}

struct DS_Array* DS_ArrayFrom(struct DS_Array *a, int start, int end, const void *array) {
    void *element = a + 1;
    element += start * a->size;
    while(start < end) {
        memcpy(element, array, a->size);
        array += a->size;
        element += a->size;
        start++;
    }
    return a;
}

int DS_ArrayIndex(struct DS_Array *a, int start, int end, const void *value) {
    void *element = a + 1;
    element += start * a->size;
    while(start < end) {
        if(a->compare(element, value) == 0) {
            return start;
        }
        element += a->size;
        start++;
    }
    return -1;
}

int DS_ArrayLen(struct DS_Array *a) {
    return a->length;
}

void* DS_ArrayMax(struct DS_Array *a, int start, int end) {
    void *element = a + 1;
    element += start * a->size;
    void *max = 0;
    while(start < end) {
        if(max == 0 || a->compare(element, max) > 0) {
            max = element;
        }
        element += a->size;
        start++;
    }
    return max;
}

void* DS_ArrayMin(struct DS_Array *a, int start, int end) {
    void *element = a + 1;
    element += start * a->size;
    void *min = 0;
    while(start < end) {
        if(min == 0 || a->compare(element, min) < 0) {
            min = element;
        }
        element += a->size;
        start++;
    }
    return min;
}

struct DS_Array* DS_ArraySort(struct DS_Array *a, int start, int end) {
    void *base = a + 1;
    base += start * a->size;
    qsort(base, end - start, a->size, a->compare);
    return a;

}

struct DS_Array* DS_ArrayTo(struct DS_Array *a, int start, int end, void *array) {
    void *element = a + 1;
    element += start * a->size;
    while(start < end) {
        memcpy(array, element, a->size);
        array += a->size;
        element += a->size;
        start++;
    }
    return a;
}
