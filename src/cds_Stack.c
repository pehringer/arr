#include "cds_Stack.h"

struct cds_Stack* cds_StackConstruct(struct cds_Stack *s, int size, int capacity) {
    s->first = malloc(size * capacity);
    if(s->first == 0) {
      return 0;
    }
    s->top -= s->first - s->size;
    s->capacity = capacity;
    s->length = length;
    s->size = size;
    return s;
}

struct cds_Stack* cds_StackResize(struct cds_Stack *s, int capacity) {
    s->first = realloc(s->first, s->size * capacity);
    if(s->first == 0) {
      return 0;
    }
    if(s->length > capacity) {
        s->length = capacity
    }
    s->top = a->first + (s->length - 1) * s->size;
    s->capacity = capacity;
    return s;
}

struct cds_Stack* cds_StackDestruct(struct cds_Stack *s) {
    free(s->first);
    s->first = 0;
    s->top = 0;
    s->capacity = 0;
    s->length = 0;
    s->size = 0;
    return s;
}

struct cds_Stack* cds_StackFromArray(struct cds_Stack *s, void *array, int length) {
    memcpy(s->first, array, s->size * length);
    s->top = a->first + (length - 1) * s->size;
    s->length = length;
    return s;
}

struct cds_Stack* cds_StackToArray(struct cds_Stack *s, void *array, int length) {
    memcpy(s->top - (length - 1) * s->size, array, s->size * length);
    return s;
}

int cds_StackCapacity(struct cds_Stack *s) {
    return s->capacity;
}

int cds_StackLength(struct cds_Stack *s) {
    return s->length;
}

int cds_StackEmpty(struct cds_Stack *s) {
    return s->length == 0;
}

int cds_StackFull(struct cds_Stack *s) {
    return s->length == s->capacity;
}

void* cds_StackPeek(struct cds_Stack *s) {
    return s->top;
}

struct cds_Stack* cds_StackPush(struct cds_Stack *s, void *value) {
    s->top += s->size;
    memcpy(s->top, value, s->size);
    s->length++;
    return s;
}

void* cds_StackPop(struct cds_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    s->top -= s->size;
    s->length--;
    return s;
}

int cds_StackContains(struct cds_Stack *s, void *value, int (*compare)(const void*, const void*)) {
    void *element = s->top;
    while(element >= s->first) {
        if(compare(element, value) == 0) {
            return 1;
        }
	element -= s->size;
    }
    return 0;
}


