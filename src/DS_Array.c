#include "DS_Array.h"

struct DS_Array* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*)) {
    struct DS_Array *a = malloc(sizeof(struct DS_Array) + length * size);
    if(a == 0) {
        return 0;
    }
    a->compare = compare;
    a->length = length;
    a->size = size;
    return a;
}

void DS_ArrayDelete(struct DS_Array *a) {
    free(a);
}

int DS_ArrayLength(struct DS_Array *a) {
    return a->length;
}

struct DS_Array* DS_ArrayResize(struct DS_Array *a, int length) {
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

void DS_ArrayGet(struct DS_Array *a, int index, void *destination) {
    memcpy(destination, (void*) (a + 1) + index * a->size, a->size);
}

void DS_ArraySet(struct DS_Array *a, int index, const void *source) {
    memcpy((void*) (a + 1) + index * a->size, source, a->size);
}

void DS_ArrayCopy(struct DS_Array *a, int start, int stop, const void *source) {
    void *element = (void*) (a + 1) + start * a->size;
    while(start < stop) {
        memcpy(element, source, a->size);
        element += a->size;
        source += a->size;
        start++;
    }
}

void DS_ArrayFill(struct DS_Array *a, int start, int stop, const void *source) {
    void *element = (void*) (a + 1) + start * a->size;
    while(start < stop) {
        memcpy(element, source, a->size);
        element += a->size;
        start++;
    }
}

int DS_ArrayMax(struct DS_Array *a, int start, int stop) {
    void *element = (void*) (a + 1) + start * a->size;
    void *max = 0;
    int index = -1;
    while(start < stop) {
        if(max == 0 || a->compare(element, max) > 0) {
            max = element;
            index = start;
        }
        element += a->size;
        start++;
    }
    return index;
}

int DS_ArrayMin(struct DS_Array *a, int start, int stop) {
    void *element = (void*) (a + 1) + start * a->size;
    void *min = 0;
    int index = -1;
    while(start < stop) {
        if(min == 0 || a->compare(element, min) < 0) {
            min = element;
            index = start;
        }
        element += a->size;
        start++;
    }
    return index;
}

int DS_ArrayCount(struct DS_Array *a, int start, int stop, const void *target) {
    void *element = (void*) (a + 1) + start * a->size;
    int count = 0;
    while(start < stop) {
        if(a->compare(element, target) == 0) {
            count++;
        }
        element += a->size;
        start++;
    }
    return count;
}

int DS_ArrayIndex(struct DS_Array *a, int start, int stop, const void *target) {
    void *element = (void*) (a + 1) + start * a->size;
    while(start < stop) {
        if(a->compare(element, target) == 0) {
            return start;
        }
        element += a->size;
        start++;
    }
    return -1;
}

void DS_ArraySort(struct DS_Array *a, int start, int stop) {
    qsort((void*) (a + 1) + start * a->size, stop - start, a->size, a->compare);
}
