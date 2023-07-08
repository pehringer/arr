#include "DS_Array.h"

struct DS_Array* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*)) {
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

void DS_ArrayDelete(struct DS_Array *a) {
    free(a);
}

struct DS_Array* DS_ArrayResize(struct DS_Array *a, int length) {
    a = realloc(a, sizeof(struct DS_Array) + length * a->size);
    if(a == 0) {
        return 0;
    }
    a->base = a + 1;
    a->length = length;
    return a;
}

void* DS_ArrayAt(struct DS_Array *a, int index) {
    return a->base + index * a->size;
}

void DS_ArrayCopy(struct DS_Array *a, int start, int end, const void *array) {
    void *element = a->base + start * a->size;
    while(start < end) {
        memcpy(element, array, a->size);
        array += a->size;
        element += a->size;
        start++;
    }
}

int DS_ArrayCount(struct DS_Array *a, int start, int end, const void *value) {
    void *element = a->base + start * a->size;
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

void DS_ArrayFill(struct DS_Array *a, int start, int end, const void *value) {
    void *element = a->base + start * a->size;
    while(start < end) {
        memcpy(element, value, a->size);
        element += a->size;
        start++;
    }
}

int DS_ArrayIndex(struct DS_Array *a, int start, int end, const void *value) {
    int index = (value - a->base) / a->size;
    if(index >= start && index < end) {
        return index;
    }
    void *element = a->base + start * a->size;
    while(start < end) {
        if(a->compare(element, value) == 0) {
            return start;
        }
        element += a->size;
        start++;
    }
    return -1;
}

int DS_ArrayLength(struct DS_Array *a) {
    return a->length;
}

void* DS_ArrayMax(struct DS_Array *a, int start, int end) {
    void *element = a->base + start * a->size;
    void *max = element;
    while(start < end) {
        if(a->compare(element, max) < 0) {
            max = element;
        }
        element += a->size;
        start++;
    }
    return max;
}

void* DS_ArrayMin(struct DS_Array *a, int start, int end) {
    void *element = a->base + start * a->size;
    void *min = element;
    while(start < end) {
        if(a->compare(element, min) > 0) {
            min = element;
        }
        element += a->size;
        start++;
    }
    return min;
}




