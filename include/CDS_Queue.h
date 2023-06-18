#ifndef CDS_QUEUE
#define CDS_QUEUE

#include <stdlib.h>
#include <string.h>

struct CDS_Queue {
    void *first;
    void *end;
    void *front;
    void *rear;
    int capacity;
    int length;
    int size;
};

//System errors return null.
struct CDS_Queue* CDS_QueueConstruct(struct CDS_Queue *q, int size, int capacity);

//System errors return null.
struct CDS_Queue* CDS_QueueResize(struct CDS_Queue *q, int capacity);

struct CDS_Queue* CDS_QueueDestruct(struct CDS_Queue *q);

struct CDS_Queue* CDS_QueueFromArray(struct CDS_Queue *q, void *array, int length);

struct CDS_Queue* CDS_QueueToArray(struct CDS_Queue *q, void *array, int length);

int CDS_QueueCapacity(struct CDS_Queue *q);

int CDS_QueueLength(struct CDS_Queue *q);

int CDS_QueueEmpty(struct CDS_Queue *q);

int CDS_QueueFull(struct CDS_Queue *q);

void* CDS_QueueFront(struct CDS_Queue *q, void *value);

void* CDS_QueueRear(struct CDS_Queue *q, void *value);

struct CDS_Queue* CDS_QueueEnqueue(struct CDS_Queue *q, void *value);

void* CDS_QueueDequeue(struct CDS_Queue *q, void *value);

int CDS_QueueContains(struct CDS_Queue *q, void *value, int (*compare)(const void*, const void*));

#endif
