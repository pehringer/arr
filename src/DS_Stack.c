#include "DS_Stack.h"

struct DS_Stack* DS_StackConstruct(int size, int capacity);

void DS_StackDestruct(struct DS_Stack *s);

struct DS_Stack* DS_StackRestruct(struct DS_Stack *s, int capacity);

int DS_StackCap(struct DS_Stack *s);

int DS_StackEmpty(struct DS_Stack *s);

int DS_StackFull(struct DS_Stack *s);

int DS_StackLen(struct DS_Stack *s);

void* DS_StackPop(struct DS_Stack *s, void *destination);

struct DS_Stack* DS_StackPush(struct DS_Stack *s, void *source);

void* DS_StackTop(struct DS_Stack *s, void *destination);

