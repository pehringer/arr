#include "cds_Stack.h"

struct cds_Stack* cds_StackConstruct(struct cds_Stack *s, int sizeOf, int capacity) {
    a->top = malloc(sizeOf * capacity);
    if(a->top == 0) {
      return 0;
    }
    a->top -= sizeOf;
    a->capacity = capacity;
    a->length = length;
    a->sizeOf = sizeOf;
    return a;

}

struct cds_Stack* cds_StackResize(struct cds_Stack *s, int capacity) {
    a->top -= (a->length - 1) * a->sizeOf;
    a->top = realloc(a->top, a->sizeOf * capacity);
    if(a->top == 0) {
      return 0;
    }
    a->top += (a->length - 1) * sizeOf;
    a->capacity = capacity;
    return a;

}

struct cds_Stack* cds_StackDestruct(struct cds_Stack *s) {
    a->top -= (a->length - 1) * a->sizeOf;
    free(a->top);
    a->top = 0;
    a->capacity = 0;
    a->length = 0;
    a->sizeOf = 0;
    return a;

}

struct cds_Stack* cds_StackFromArray(struct cds_Stack *s, void *array, int length);

struct cds_Stack* cds_StackToArray(struct cds_Stack *s, void *array, int length);

int cds_StackEmpty(struct cds_Stack *s);

int cds_StackFull(struct cds_Stack *s);

void* cds_StackPeek(struct cds_Stack *s);

struct cds_Stack* cds_StackPush(struct cds_Stack *s, void *value);

void* cds_StackPop(struct cds_Stack *s, void *value);

int cds_StackContains(struct cds_Stack *s, void *value, int (*compare)(const void*, const void*));

