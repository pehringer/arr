#ifndef DS_SET_H
#define DS_SET_H

#include <stdlib.h>
#include <string.h>

struct DS_Set {
    int capacity;
    int length;
    size_t size;
}

struct DS_Set* DS_SetAlloc(int size, int capacity);

void DS_SetDealloc(struct DS_Set *s);

struct DS_Set* DS_SetRealloc(struct DS_Set *s, int capacity);

int DS_SetCap(struct DS_Set *s);

int DS_SetLen(struct DS_Set *s);

void DS_SetAdd(struct DS_Set *s, void *source);

void DS_SetRemove(struct DS_Set *s, void *destination);

void DS_SetUnion(struct DS_Set *result, struct DS_Set *left, struct DS_Set *right);

void DS_SetInter(struct DS_Set *result, struct DS_Set *left, struct DS_Set *right);

void DS_SetDiffer(struct DS_Set *result, struct DS_Set *left, struct DS_Set *right);

int DS_SetSubset(struct DS_Set *left, struct DS_Set *right);

#endif
