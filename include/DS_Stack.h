#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdlib.h>
#include <string.h>

struct DS_Stack {
    void *base;
    int capacity;
    int length;
    int size;
    void *top;
};

//System errors return null.
struct DS_Stack* DS_StackConstruct(struct DS_Stack *s, int size, int capacity);

//System errors return null.
struct DS_Stack* DS_StackResize(struct DS_Stack *s, int capacity);

struct DS_Stack* DS_StackDestruct(struct DS_Stack *s);

struct DS_Stack* DS_StackFromArray(struct DS_Stack *s, void *array, int length);

struct DS_Stack* DS_StackToArray(struct DS_Stack *s, void *array, int length);

int DS_StackCapacity(struct DS_Stack *s);

int DS_StackLength(struct DS_Stack *s);

int DS_StackEmpty(struct DS_Stack *s);

int DS_StackFull(struct DS_Stack *s);

void* DS_StackTop(struct DS_Stack *s, void *value);

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *value);

void* DS_StackPop(struct DS_Stack *s, void *value);

int DS_StackContains(struct DS_Stack *s, void *value, int (*compare)(const void*, const void*));

#endif
