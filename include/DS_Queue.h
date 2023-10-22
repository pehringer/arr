#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include <stdlib.h>
#include <string.h>

/*
Memory Allocation Format
========================

+---------+ <- Allocation start.
|Struct   |
|DS_Queue |
|         |
+---------+ <- Pointer retured by DS_QueueAllocate() and DS_QueueDeallocate() functions.
|Element 0|
+---------+
|Element 1|
+---------+
|Element 2|
+---------+
|Elemant 3|
+---------+
| ...     |
+---------+
|Element N|
+---------+ <- Allocation end.

*/

struct DS_Queue {
    int back;     // Offset from end of header to start of back element.
    int capacity; // Number of elements in allocation.
    int front;    // Offset from end of header to start of front element.
    int length;   // Elements being used in allocation.
    size_t size;  // Size of element.
    int wrap;     // Offset from end of header to end of allocation.
};

struct DS_Queue* DS_QueueAllocate(int size, int capacity);

void DS_QueueDeallocate(struct DS_Queue *q);

struct DS_Queue* DS_QueueReallocate(struct DS_Queue *q, int capacity);

void* DS_QueueBack(struct DS_Queue *q, void *destination);

int DS_QueueCapacity(struct DS_Queue *q);

int DS_QueueEmpty(struct DS_Queue *q);

void* DS_QueueFront(struct DS_Queue *q, void *destination);

int DS_QueueFull(struct DS_Queue *q);

int DS_QueueLength(struct DS_Queue *q);

void* DS_QueuePop(struct DS_Queue *q, void *destination);

struct DS_Queue* DS_QueuePush(struct DS_Queue *q, void *source);

#endif
