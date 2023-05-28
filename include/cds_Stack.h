#ifndef CDS_STACK_H
#define CDS_STACK_H

struct cds_Stack {
    void *top
    int capacity;
    int length;
    int sizeOf;
};

struct cds_Stack* cds_StackConstruct(struct cds_Stack *s, int sizeOf, int capacity);

struct cds_Stack* cds_StackResize(struct cds_Stack *s, int capacity);

void cds_StackDestruct(struct cds_Stack *s);

int cds_StackEmpty(struct cds_Stack *s);

int cds_StackFull(struct cds_Stack *s);

void* cds_StackPeek(struct cds_Stack *s);

void* cds_StackPop(struct cds_Stack *s, void *value);

struct cds_Stack* cds_StackPush(struct cds_Stack *s, void *value);

#endif
