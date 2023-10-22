#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdlib.h>
#include <string.h>

void* DS_StackAllocate(int size, int capacity);

void DS_StackDeallocate(void *stack);

void* DS_StackReallocate(void *stack, int capacity);

int DS_StackCapacity(void *stack);

int DS_StackEmpty(void *stack);

int DS_StackFull(void *stack);

int DS_StackLength(void *stack);

void* DS_StackPop(void *stack, void *destination);

void* DS_StackPush(void *stack, void *source);

void* DS_StackTop(void *stack, void *destination);

#endif
