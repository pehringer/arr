#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdlib.h>
#include <string.h>

struct DS_Stack {
    int capacity;
    int length;
    size_t size;
    int top;
};

struct DS_Stack* DS_StackConstruct(int size, int capacity);

void DS_StackDestruct(struct DS_Stack *s);

struct DS_Stack* DS_StackRestruct(struct DS_Stack *s, int capacity);

int DS_StackCap(struct DS_Stack *s);

int DS_StackEmpty(struct DS_Stack *s);

struct DS_Stack* DS_StackFrom(struct DS_Stack *s, int length, void *source);

int DS_StackFull(struct DS_Stack *s);

int DS_StackLen(struct DS_Stack *s);

void* DS_StackPop(struct DS_Stack *s, void *destination);

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *source);

struct DS_Stack* DS_StackTo(struct DS_Stack *s, int length, void *destination);

void* DS_StackTop(struct DS_Stack *s, void *destination);

#endif
