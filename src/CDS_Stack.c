#include "CDS_Stack.h"

struct CDS_Stack* CDS_StackConstruct(struct CDS_Stack *s, int size, int capacity) {
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

struct CDS_Stack* CDS_StackResize(struct CDS_Stack *s, int capacity) {
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

struct CDS_Stack* CDS_StackDestruct(struct CDS_Stack *s) {
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

struct CDS_Stack* CDS_StackFromArray(struct CDS_Stack *s, void *array, int length) {
    memcpy(s->base, array, s->size * length);
    s->length = length;
    s->top = s->base + (length - 1) * s->size;
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
    s->length++;
    s->top += s->size;
    memcpy(s->top, value, s->size);
    return s;
}

void* CDS_StackPop(struct CDS_Stack *s, void *value) {
    memcpy(value, s->top, s->size);
    s->length--;
    s->top -= s->size;
    return value;
}

int CDS_StackContains(struct CDS_Stack *s, void *value, int (*compare)(const void*, const void*)) {
    void *element = s->top;
    while(element >= s->base && compare(element, value)) {
	element -= s->size;
    }
    return element >= s->base;
}


