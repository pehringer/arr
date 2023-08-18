#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include <stdlib.h>
#include <string.h>

/*
Memory Allocation Format
========================

+-------+ <-- Header is located at the start of the allocation (pointer to
|DS     |     struct is retured by Alloc and Realloc functions).
|Struct |
|       |
+-------+ <-- Data is located after header in the allocation.
|Index 0|
+-------+
|Index 1|
+-------+
|Index 2|
+-------+
|Index 3|
+-------+
| ...   |
+-------+
|Index N|
+-------+
*/

struct DS_Queue {
    int back;     // Offset from end of header to start of back element.
    int capacity; // Number of elements in allocation.
    int front;    // Offset from end of header to start of front element.
    int length;   // Elements being used in allocation.
    size_t size;  // Size of element.
    int wrap;     // Offset from end of header to end of allocation.
};

struct DS_Queue* DS_QueueAlloc(int size, int capacity);

void DS_QueueDealloc(struct DS_Queue *q);

struct DS_Queue* DS_QueueRealloc(struct DS_Queue *q, int capacity);

void* DS_QueueBack(struct DS_Queue *q, void *destination);

int DS_QueueCap(struct DS_Queue *q);

int DS_QueueEmpty(struct DS_Queue *q);

void* DS_QueueFront(struct DS_Queue *q, void *destination);

int DS_QueueFull(struct DS_Queue *q);

int DS_QueueLen(struct DS_Queue *q);

void* DS_QueuePop(struct DS_Queue *q, void *destination);

struct DS_Queue* DS_QueuePush(struct DS_Queue *q, void *source);

#endif
