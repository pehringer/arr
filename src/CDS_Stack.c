#include "CDS_Stack.h"

struct CDS_Stack* CDS_StackConstruct(struct CDS_Stack *s, int size, int capacity) {
    s->first = malloc(size * capacity);
    if(s->first == 0) {
      return 0;
    }
    s->top = s->first - s->size;
    s->capacity = capacity;
    s->length = 0;
    s->size = size;
    return s;
}

struct CDS_Stack* CDS_StackResize(struct CDS_Stack *s, int capacity) {
    s->first = realloc(s->first, s->size * capacity);
    if(s->first == 0) {
      return 0;
    }
    if(s->length > capacity) {
        s->length = capacity;
    }
    s->top = s->first + (s->length - 1) * s->size;
    s->capacity = capacity;
    return s;
}

struct CDS_Stack* CDS_StackDestruct(struct CDS_Stack *s) {
    free(s->first);
    s->first = 0;
    s->top = 0;
    s->capacity = 0;
    s->length = 0;
    s->size = 0;
    return s;
}

struct CDS_Stack* CDS_StackFromArray(struct CDS_Stack *s, void *array, int length) {
    memcpy(s->first, array, s->size * length);
    s->top = s->first + (length - 1) * s->size;
    s->length = length;
    return s;
}

struct CDS_Stack* CDS_StackToArray(struct CDS_Stack *s, void *array, int length) {
    memcpy(array, s->top - (length - 1) * s->size, s->size * length);
    return s;
}

int CDS_StackCapacity(struct CDS_Stack *s) {
    return s->capacity;
}

int CDS_StackLength(struct CDS_Stack *s) {
    return s->length;
}

int CDS_StackEmpty(struct CDS_Stack *s) {
    return s->length == 0;
}

int CDS_StackFull(struct CDS_Stack *s) {
    return s->length == s->capacity;
}

void* CDS_StackTop(struct CDS_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    return value;
}

struct CDS_Stack* CDS_StackPush(struct CDS_Stack *s, void *value) {
    s->top += s->size;
    memcpy(s->top, value, s->size);
    s->length++;
    return s;
}

void* CDS_StackPop(struct CDS_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    s->top -= s->size;
    s->length--;
    return value;
}

int CDS_StackContains(struct CDS_Stack *s, void *value, int (*compare)(const void*, const void*)) {
    void *element = s->top;
    while(element >= s->first) {
        if(compare(element, value) == 0) {
            return 1;
        }
	element -= s->size;
    }
    return 0;
}


