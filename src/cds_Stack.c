#include "cds_Stack.h"

struct cds_Stack* cds_StackConstruct(struct cds_Stack *s, int size, int capacity) {
    s->top = malloc(size * capacity);
    if(s->top == 0) {
      return 0;
    }
    s->top -= size;
    s->capacity = capacity;
    s->length = length;
    s->size = size;
    return s;

}

struct cds_Stack* cds_StackResize(struct cds_Stack *s, int capacity) {
    s->top = realloc(s->top - (s->length - 1) * s->size, s->size * capacity);
    if(s->top == 0) {
      return 0;
    }
    s->top += (s->length - 1) * size;
    s->capacity = capacity;
    return s;

}

struct cds_Stack* cds_StackDestruct(struct cds_Stack *s) {
    free(s->top - (s->length - 1) * s->size);
    s->top = 0;
    s->capacity = 0;
    s->length = 0;
    s->size = 0;
    return s;

}

struct cds_Stack* cds_StackFromArray(struct cds_Stack *s, void *array, int length) {
    memcpy(s->top - (s->length - 1) * s->size, array, s->size * length);
    s->top += (length - 1) * size;
    s->length = length;
    return s;
}

struct cds_Stack* cds_StackToArray(struct cds_Stack *s, void *array, int length) {
    memcpy(array, s->top - (s->length - 1) * s->size,  s->size * s->length);
    return s;
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

struct cds_Stack* cds_StackPush(struct cds_Stack *s, void *value);

void* cds_StackPop(struct cds_Stack *s, void *value);

int cds_StackContains(struct cds_Stack *s, void *value, int (*compare)(const void*, const void*));

