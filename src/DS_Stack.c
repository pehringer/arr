#include "DS_Stack.h"

struct DS_Stack* DS_StackConstruct(struct DS_Stack *s, int size, int capacity) {
    if(capacity) {
        s->base = malloc(size * capacity);
    } else {
        s->base = s;
    }
    if(s->base == 0) {
        return 0;
    }
    s->capacity = capacity;
    s->length = 0;
    s->size = size;
    s->top = s->base - size;
    return s;
}

struct DS_Stack* DS_StackResize(struct DS_Stack *s, int capacity) {
    if(capacity && s->capacity) {
        s->base = realloc(s->base, s->size * capacity);
    } else if(capacity) {
        s->base = malloc(s->size * capacity);
    } else if(s->capacity) {
        free(s->base);
        s->base = s;
    }
    if(s->base == 0) {
        return 0;
    }
    s->capacity = capacity;
    if(s->length > capacity) {
        s->length = capacity;
    }
    s->top = s->base + (s->length - 1) * s->size;
    return s;
}

struct DS_Stack* DS_StackDestruct(struct DS_Stack *s) {
    if(a->capacity) {
        free(s->base);
    }
    s->base = 0;
    s->capacity = 0;
    s->length = 0;
    s->size = 0;
    s->top = 0;
    return s;
}

struct DS_Stack* DS_StackFromArray(struct DS_Stack *s, void *array, int length) {
    memcpy(s->base, array, s->size * length);
    s->length = length;
    s->top = s->base + (length - 1) * s->size;
    return s;
}

struct DS_Stack* DS_StackToArray(struct DS_Stack *s, void *array, int length) {
    memcpy(array, s->top - (length - 1) * s->size, s->size * length);
    return s;
}

int DS_StackCapacity(struct DS_Stack *s) {
    return s->capacity;
}

int DS_StackLength(struct DS_Stack *s) {
    return s->length;
}

int DS_StackEmpty(struct DS_Stack *s) {
    return s->length == 0;
}

int DS_StackFull(struct DS_Stack *s) {
    return s->length == s->capacity;
}

void* DS_StackTop(struct DS_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    return value;
}

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *value) {
    s->length++;
    s->top += s->size;
    memcpy(s->top, value, s->size);
    return s;
}

void* DS_StackPop(struct DS_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    s->length--;
    s->top -= s->size;
    return value;
}

int DS_StackContains(struct DS_Stack *s, void *value, int (*compare)(const void*, const void*)) {
    void *element = s->top;
    while(element >= s->base && compare(element, value)) {
	element -= s->size;
    }
    return element >= s->base;
}


