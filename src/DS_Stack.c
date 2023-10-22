#include "DS_Stack.h"

/*
Memory Allocation Format
========================

+---------+ <- Allocation start.
|Struct   |
|DS_Stack |
|         |
+---------+ <- Pointer retured by DS_StackAllocate(), DS_StackReallocate(),
|Element 0|    and DS_StackPush() functions.
+---------+
|Element 1|
+---------+
|Element 2|
+---------+
|Elemant 3|
+---------+
| ...     |
+---------+
|Element N|
+---------+ <- Allocation end.

*/

struct DS_Stack {
    int capacity; // Number of elements in allocation.
    int length;   // Elements being used in allocation.
    size_t size;  // Size of element.
    int top;      // Offset from end of header to start of top element.
};

void* DS_StackAllocate(int size, int capacity) {
    struct DS_Stack *s = malloc(sizeof(struct DS_Stack) + capacity * size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    s->length = 0;
    s->size = size;
    s->top = -size;
    return s + 1;
}

void DS_StackDeallocate(void *stack) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    free(s);
}

void* DS_StackReallocate(void *stack, int capacity) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    s = realloc(s, sizeof(struct DS_Stack) + capacity * s->size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    if(s->length > capacity) {
        s->length = capacity;
    }
    s->top = (s->length - 1) * s->size;
    return s + 1;
}

int DS_StackCapacity(void *stack) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    return s->capacity;
}

int DS_StackEmpty(void *stack) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    return s->length == 0;
}

int DS_StackFull(void *stack) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    return s->length == s->capacity;
}

int DS_StackLength(void *stack) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    return s->length;
}

void* DS_StackPop(void* stack, void *destination) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    //REMOVE if block to remove out of bounds check.
    if(s->length == 0) {
        return 0;
    }
    // REMOVE ^^^^^^^^
    memcpy(destination, stack + s->top, s->size);
    s->length--;
    s->top -= s->size;
    return destination;
}

void* DS_StackPush(void *stack, void *source) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    // REMOVE if block to remove auto reallocation.
    if(s->length == s->capacity) {
        stack = DS_StackReallocate(s, s->length * 2);
        s = (struct DS_Stack*) stack - 1;
    }
    // REMOVE ^^^^^^^^
    s->length++;
    s->top += s->size;
    memcpy(stack + s->top, source, s->size);
    return s;
}

void* DS_StackTop(void *stack, void *destination) {
    struct DS_Stack *s = (struct DS_Stack*) stack - 1;
    //REMOVE if block to remove out of bounds check.
    if(s->length == 0) {
        return 0;
    }
    // REMOVE ^^^^^^^^
    memcpy(destination, stack + s->top, s->size);
    return destination;
}

