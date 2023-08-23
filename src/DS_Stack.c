#include "DS_Stack.h"

struct DS_Stack* DS_StackAlloc(int size, int capacity) {
    struct DS_Stack *s = malloc(sizeof(struct DS_Stack) + capacity * size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    s->length = 0;
    s->size = size;
    s->top = -size;
    return s;
}

void DS_StackDealloc(struct DS_Stack *s) {
    free(s);
}

struct DS_Stack* DS_StackRealloc(struct DS_Stack *s, int capacity) {
    s = realloc(s, sizeof(struct DS_Stack) + capacity * s->size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    if(s->length > capacity) {
        s->length = capacity;
    }
    s->top = (s->length - 1) * s->size;
    return s;
}

int DS_StackCap(struct DS_Stack *s) {
    return s->capacity;
}

int DS_StackEmpty(struct DS_Stack *s) {
    return s->length == 0;
}

int DS_StackFull(struct DS_Stack *s) {
    return s->length == s->capacity;
}

int DS_StackLen(struct DS_Stack *s) {
    return s->length;
}

void* DS_StackPop(struct DS_Stack *s, void *destination) {
    //REMOVE if block to remove out of bounds check.
    if(s->length == 0) {
        return 0;
    }
    // REMOVE ^^^^^^^^
    memcpy(destination, (void*) (s + 1) + s->top, s->size);
    s->length--;
    s->top -= s->size;
    return destination;
}

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *source) {
    // REMOVE if block to remove auto reallocation.
    if(s->length == s->capacity) {
        s = DS_StackRealloc(s, s->length * 2);
    }
    // REMOVE ^^^^^^^^
    s->length++;
    s->top += s->size;
    memcpy((void*) (s + 1) + s->top, source, s->size);
    return s;
}

void* DS_StackTop(struct DS_Stack *s, void *destination) {
    //REMOVE if block to remove out of bounds check.
    if(s->length == 0) {
        return 0;
    }
    // REMOVE ^^^^^^^^
    memcpy(destination, (void*) (s + 1) + s->top, s->size);
    return destination;
}

