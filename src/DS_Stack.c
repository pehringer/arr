#include "DS_Stack.h"

struct DS_Stack* DS_StackNew(int size, int capacity);

void DS_StackDelete(struct DS_Stack *s);

struct DS_Stack* DS_StackResize(struct DS_Stack *s, int capacity);

int DS_StackCapacity(struct DS_Stack *s);

struct DS_Stack* DS_StackCopy(struct DS_Stack *s, int length, void *array);

int DS_StackEmpty(struct DS_Stack *s);

int DS_StackFull(struct DS_Stack *s);

int DS_StackLength(struct DS_Stack *s);

void* DS_StackPop(struct DS_Stack *s, void *value);

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *value);

void* DS_StackTop(struct DS_Stack *s, void *value);
