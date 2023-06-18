#ifndef CDS_ARRAY_H
#define CDS_ARRAY_H

#include <stdlib.h>
#include <string.h>

struct CDS_Array {
    void *first;
    int length;
    int size;
};

//System errors return null.
struct CDS_Array* CDS_ArrayConstruct(struct CDS_Array *a, int size, int length);

//System errors return null.
struct CDS_Array* CDS_ArrayResize(struct CDS_Array *a, int length);

struct CDS_Array* CDS_ArrayDestruct(struct CDS_Array *a);

struct CDS_Array* CDS_ArrayFromArray(struct CDS_Array *a, int index, void *array, int length);

struct CDS_Array* CDS_ArrayToArray(struct CDS_Array *a, int index, void *array, int length);

struct CDS_Array* CDS_ArrayFill(struct CDS_Array *a, int index, void *value, int length);

int CDS_ArrayLength(struct CDS_Array *a);

void* CDS_ArrayAt(struct CDS_Array *a, int index);

int CDS_ArrayFirstIndexOf(struct CDS_Array *a, int index, void *value, int (*compare)(const void*, const void*));

int CDS_ArrayLastIndexOf(struct CDS_Array *a, int index, void *value, int (*compare)(const void*, const void*));

struct CDS_Array* CDS_ArraySort(struct CDS_Array *a, int (*compare)(const void*, const void*));

int CDS_ArrayBinarySearch(struct CDS_Array *a, void *value, int (*compare)(const void*, const void*));

#endif
