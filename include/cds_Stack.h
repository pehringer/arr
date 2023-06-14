#ifndef CDS_STACK_H
#define CDS_STACK_H

#include <stdlib.h>
#include <string.h>

struct cds_Stack {
    void *top
    int capacity;
    int length;
    int sizeOf;
};

//System errors return null.
struct cds_Stack* cds_StackConstruct(struct cds_Stack *s, int sizeOf, int capacity);

//System errors return null.
struct cds_Stack* cds_StackResize(struct cds_Stack *s, int capacity);

struct cds_Stack* cds_StackDestruct(struct cds_Stack *s);

struct cds_Stack* cds_StackFromArray(struct cds_Stack *s, void *array, int length);

struct cds_Stack* cds_StackToArray(struct cds_Stack *s, void *array, int length);

int cds_StackEmpty(struct cds_Stack *s);

int cds_StackFull(struct cds_Stack *s);

void* cds_StackPeek(struct cds_Stack *s);

struct cds_Stack* cds_StackPush(struct cds_Stack *s, void *value);

void* cds_StackPop(struct cds_Stack *s, void *value);

int cds_StackContains(struct cds_Stack *s, void *value, int (*compare)(const void*, const void*));

#endif
