#include "DS_Array.h"

void* DS_ArrayNew(size_t size, int length, int (*compare)(const void*, const void*)) {
    struct DS_Array *ds = malloc(sizeof(struct DS_Array) + length * size);
    if(ds == 0) {
        return 0;
    }
    ds->compare = compare;
    ds->length = length;
    ds->size = size;
    return ds + 1;
}

void DS_ArrayDelete(void* array) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    free(ds);
}

int DS_ArrayLength(void* array) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    return ds->length;
}

void* DS_ArrayResize(void *array, int length) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    ds = realloc(ds, sizeof(struct DS_Array) + length * ds->size);
    if(ds == 0) {
        return 0;
    }
    ds->length = length;
    return ds + 1;
}

void DS_ArrayCopy(void *array, int start, int stop, const void *source) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    array = array + start * ds->size;
    while(start < stop) {
        memcpy(array, source, ds->size);
        array += ds->size;
        source += ds->size;
        start++;
    }
}

void DS_ArrayFill(void *array, int start, int stop, const void *source) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    array = array + start * ds->size;
    while(start < stop) {
        memcpy(array, source, ds->size);
        array += ds->size;
        start++;
    }
}

int DS_ArrayMax(void *array, int start, int stop) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    void *max = 0;
    int index = -1;
    array = array + start * ds->size;
    while(start < stop) {
        if(max == 0 || ds->compare(array, max) > 0) {
            max = array;
            index = start;
        }
        array += ds->size;
        start++;
    }
    return index;
}

int DS_ArrayMin(void *array, int start, int stop) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    void *min = 0;
    int index = -1;
    array = array + start * ds->size;
    while(start < stop) {
        if(min == 0 || ds->compare(array, min) < 0) {
            min = array;
            index = start;
        }
        array += ds->size;
        start++;
    }
    return index;
}

int DS_ArrayCount(void *array, int start, int stop, const void *target) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    int count = 0;
    array = array + start * ds->size;
    while(start < stop) {
        if(ds->compare(array, target) == 0) {
            count++;
        }
        array += ds->size;
        start++;
    }
    return count;
}

int DS_ArrayIndex(void *array, int start, int stop, const void *target) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    array = array + start * ds->size;
    while(start < stop) {
        if(ds->compare(array, target) == 0) {
            return start;
        }
        array += ds->size;
        start++;
    }
    return -1;
}

void DS_ArraySort(void *array, int start, int stop) {
    struct DS_Array *ds = (struct DS_Array*) array - 1;
    qsort(array + start * ds->size, stop - start, ds->size, ds->compare);
}
