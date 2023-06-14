#ifndef CDS_ARRAY_H
#define CDS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct cds_Array {
    void *first;
    int length;
    int sizeOf;
};

//System errors return null.
struct cds_Array* cds_ArrayConstruct(struct cds_Array *a, int sizeOf, int length);

//System errors return null.
struct cds_Array* cds_ArrayResize(struct cds_Array *a, int length);

struct cds_Array* cds_ArrayDestruct(struct cds_Array *a);

struct cds_Array* cds_ArrayFromArray(struct cds_Array *a, int index, void *array, int length);

struct cds_Array* cds_ArrayToArray(struct cds_Array *a, int index, void *array, int length);

struct cds_Array* cds_ArrayFill(struct cds_Array *a, int index, void *value, int length);

int cds_ArrayLength(struct cds_Array *a);

void* cds_ArrayAt(struct cds_Array *a, int index);

int cds_ArrayFirstIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*));

int cds_ArrayLastIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*));

struct cds_Array* cds_ArraySort(struct cds_Array *a, int (*compare)(const void*, const void*));

int cds_ArrayBinarySearch(struct cds_Array *a, void *value, int (*compare)(const void*, const void*));

#endif
