#ifndef CDS_ARRAY_H
#define CDS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct cds_Array {
    void *base;
    int length;
    int sizeOf;
};

//System errors return null.
void* cds_ArrayConstruct(struct cds_Array *a, int sizeOf, int length);

//System errors return null.
void* cds_ArrayResizeOf(struct cds_Array *a, int length);

void cds_ArrayDestruct(struct cds_Array *a);

int cds_ArrayLength(struct cds_Array *a);

void* cds_ArrayAt(struct cds_Array *a, int index);

void* cds_ArrayCopy(struct cds_Array *a, int index, void *values, int length);

void* cds_ArrayFill(struct cds_Array *a, int index, void *value, int length);

int cds_ArrayFirstIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*));

int cds_ArrayLastIndexOf(struct cds_Array *a, int index, void *value, int (*compare)(const void*, const void*));

void* cds_ArraySort(struct cds_Array *a, int (*compare)(const void*, const void*));

void* cds_ArrayBinarySearch(struct cds_Array *a, void *value, int (*compare)(const void*, const void*));

#endif
