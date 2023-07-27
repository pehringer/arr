#include "DS_Stack.h"

struct DS_Stack* DS_StackConstruct(int size, int capacity) {
    struct DS_Stack *s = malloc(sizeof(struct DS_Stack) + capacity * size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    s->length = 0;
    s->size = size;
    s->top = sizeof(struct DS_Stack) - size;
    return s;
}

void DS_StackDestruct(struct DS_Stack *s) {
    free(s);
}

struct DS_Stack* DS_StackRestruct(struct DS_Stack *s, int capacity) {
    s = realloc(s, sizeof(struct DS_Stack) + capacity * s->size);
    if(s == 0) {
        return 0;
    }
    s->capacity = capacity;
    if(s->length > capacity) {
        s->length = capacity;
        s->top = sizeof(struct DS_Stack) + (capacity - 1) * s->size;
    }
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
    return s->capacity;
}

void* DS_StackPop(struct DS_Stack *s, void *destination) {
    memcpy(destination, (void*) s + s->top, s->size);
    s->length--;
    s->top -= s->size;
    return destination;
}

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *source) {
    s->length++;
    s->top += s->size;
    memcpy((void*) s + s->top, source, s->size);
    return s;
}

void* DS_StackTop(struct DS_Stack *s, void *destination) {
    memcpy(destination, (void*) s + s->top, s->size);
    return destination;
}

