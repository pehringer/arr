#ifndef CDS_STACK_H
#define CDS_STACK_H

#include <stdlib.h>
#include <string.h>

struct CDS_Stack {
    void *first;
    void *top;
    int capacity;
    int length;
    int size;
};

//System errors return null.
struct CDS_Stack* CDS_StackConstruct(struct CDS_Stack *s, int size, int capacity);

//System errors return null.
struct CDS_Stack* CDS_StackResize(struct CDS_Stack *s, int capacity);

struct CDS_Stack* CDS_StackDestruct(struct CDS_Stack *s);

struct CDS_Stack* CDS_StackFromArray(struct CDS_Stack *s, void *array, int length);

struct CDS_Stack* CDS_StackToArray(struct CDS_Stack *s, void *array, int length);

int CDS_StackCapacity(struct CDS_Stack *s);

int CDS_StackLength(struct CDS_Stack *s);

int CDS_StackEmpty(struct CDS_Stack *s);

int CDS_StackFull(struct CDS_Stack *s);

void* CDS_StackTop(struct CDS_Stack *s, void *value);

struct CDS_Stack* CDS_StackPush(struct CDS_Stack *s, void *value);

void* CDS_StackPop(struct CDS_Stack *s, void *value);

int CDS_StackContains(struct CDS_Stack *s, void *value, int (*compare)(const void*, const void*));

#endif
