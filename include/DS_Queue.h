#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include <stdlib.h>
#include <string.h>

struct DS_Queue {
    int back;
    int capacity;
    int front;
    int length;
    size_t size;
    int wrap;
}

struct DS_Queue* DS_QueueConstruct(int size, int capacity);

void DS_QueueDestruct(struct DS_Queue *q);

struct DS_Queue* DS_QueueRestruct(struct DS_Queue *q, int capacity);

void* DS_QueueBack(struct DS_Queue *q, void *destination);

int DS_QueueCap(struct DS_Queue *q);

int DS_QueueEmpty(struct DS_Queue *q);

void* DS_QueueFront(struct DS_Queue *q, void *destination);

int DS_QueueFull(struct DS_Queue *q);

int DS_QueueLen(struct DS_Queue *q);

void* DS_QueuePop(struct DS_Queue *q, void *destination);

struct DS_Queue* DS_QueuePush(struct DS_Queue *q, void *source);

#endif
