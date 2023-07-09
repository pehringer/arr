#ifndef DS_QUEUE
#define DS_QUEUE

#include <stdlib.h>
#include <string.h>

struct DS_Queue {
    void *first;
    void *end;
    void *front;
    void *rear;
    int capacity;
    int length;
    int size;
};

//System errors return null.
struct DS_Queue* DS_QueueConstruct(struct DS_Queue *q, int size, int capacity);

//System errors return null.
struct DS_Queue* DS_QueueResize(struct DS_Queue *q, int capacity);

struct DS_Queue* DS_QueueDestruct(struct DS_Queue *q);

struct DS_Queue* DS_QueueFromArray(struct DS_Queue *q, void *array, int length);

struct DS_Queue* DS_QueueToArray(struct DS_Queue *q, void *array, int length);

int DS_QueueCapacity(struct DS_Queue *q);

int DS_QueueLength(struct DS_Queue *q);

int DS_QueueEmpty(struct DS_Queue *q);

int DS_QueueFull(struct DS_Queue *q);

void* DS_QueueFront(struct DS_Queue *q, void *value);

void* DS_QueueRear(struct DS_Queue *q, void *value);

struct DS_Queue* DS_QueueEnqueue(struct DS_Queue *q, void *value);

void* DS_QueueDequeue(struct DS_Queue *q, void *value);

int DS_QueueContains(struct DS_Queue *q, void *value, int (*compare)(const void*, const void*));

#endif
