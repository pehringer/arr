#include "DS_Array.h"

struct DS_Array DS_ArrayInit(void* array, int (*compare)(const void*, const void*), size_t size) {
    return (struct DS_Array) {
        array,
        compare,
        size,
    };
}

void DS_ArrayFill(struct DS_Array a, int start, int stop, const void *source) {
    void *element = a.array + start * a.size;
    while(start < stop) {
        memcpy(element, source, a.size);
        element += a.size;
        start++;
    }
}

void DS_ArraySet(struct DS_Array a, int start, int stop, const void *source) {
    memcpy(a.array + start * a.size, source, (stop - start) * a.size);
}

void DS_ArrayGet(struct DS_Array a, int start, int stop, void *destination) {
    memcpy(destination, a.array + start * a.size, (stop - start) * a.size);
}

int DS_ArrayCount(struct DS_Array a, int start, int stop, const void *target) {
    void *element = a.array + start * a.size;
    int count = 0;
    while(start < stop) {
        if(a.compare(element, target) == 0) {
            count++;
        }
        element += a.size;
        start++;
    }
    return count;
}

int DS_ArrayFirst(struct DS_Array a, int start, int stop, const void *target) {
    void *element = a.array + start * a.size;
    while(start < stop) {
        if(a.compare(element, target) == 0) {
            return start;
        }
        element += a.size;
        start++;
    }
    return -1;
}

int DS_ArrayLast(struct DS_Array a, int start, int stop, const void *target) {
    void *element = a.array + --stop * a.size;
    while(stop >= start) {
        if(a.compare(element, target) == 0) {
            return stop;
        }
        element -= a.size;
        stop--;
    }
    return -1;
}

int DS_ArrayMax(struct DS_Array a, int start, int stop) {
    void *element = a.array + start * a.size;
    void *max = 0;
    int index = -1;
    while(start < stop) {
        if(max == 0 || a.compare(element, max) > 0) {
            max = element;
            index = start;
        }
        element += a.size;
        start++;
    }
    return index;
}

int DS_ArrayMin(struct DS_Array a, int start, int stop) {
    void *element = a.array + start * a.size;
    void *min = 0;
    int index = -1;
    while(start < stop) {
        if(min == 0 || a.compare(element, min) < 0) {
            min = element;
            index = start;
        }
        element += a.size;
        start++;
    }
    return index;
}

void DS_ArraySort(struct DS_Array a, int start, int stop) {
    qsort(a.array + start * a.size, stop - start, a.size, a.compare);
}
