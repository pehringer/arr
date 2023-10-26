#include "DS_Queue.h"

/*
Memory Allocation Format
========================

+---------+ <- Allocation start.
|Struct   |
|DS_Queue |
|         |
+---------+ <- Pointer retured by DS_QueueAllocate(), DS_QueueDeallocate(),
|Element 0|    and DS_QueuePush() functions.
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


void* DS_QueueAllocate(int size, int capacity) {
    struct DS_Queue *q = malloc(sizeof(struct DS_Queue) + capacity * size);
    if(q == 0) {
        return 0;
    }
    q->back = -size;
    q->capacity = capacity;
    q->front = 0;
    q->length = 0;
    q->size = size;
    q->wrap = capacity * size;
    return q + 1;
}

void DS_QueueDeallocate(void *queue) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    free(q);
}

void* DS_QueueReallocate(void *queue, int capacity) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    // Shift elements so front is zeroth element.
    void *start = queue;
    void *middle = queue + q->front;
    void *end = queue + q->wrap;
    void *next = middle;
    while(start != next) {
        // XOR swap elements. Increment start and next.
        for(int byte = 0; byte < q->size; byte++) {
            *((char*) start) = *((char*) start) ^ *((char*) next);
            *((char*) next) = *((char*) start) ^ *((char*) next);
            *((char*) start) = *((char*) start) ^ *((char*) next);
            start++;
            next++;
        }
        // Shift logic.
        if(next == end) {
            next = middle;
        } else if(start == middle) {
            middle = next;
        }
    }
    // Now reallocate queue.
    q = realloc(q, sizeof(struct DS_Queue) + capacity * q->size);
    if(q == 0) {
        return 0;
    }
    q->capacity = capacity;
    q->front = 0;
    if(q->length > capacity) {
        q->length = capacity;
    }
    q->back = (q->length - 1) * q->size;
    q->wrap = capacity * q->size;
    return q + 1;
}

void* DS_QueueBack(void *queue, void *destination) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    //REMOVE if block to remove out of bounds check.
    if(q->length == 0) {
        return 0;
    }
    // ^^^^^^^^
    memcpy(destination, queue + q->back, q->size);
    return destination;
}

int DS_QueueCapacity(void *queue) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    return q->capacity;
}

int DS_QueueEmpty(void *queue) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    return q->length == 0;
}

void* DS_QueueFront(void *queue, void *destination) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    //REMOVE if block to remove out of bounds check.
    if(q->length == 0) {
        return 0;
    }
    // ^^^^^^^^
    memcpy(destination, queue + q->front, q->size);
    return destination;
}

int DS_QueueFull(void *queue) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    return q->length == q->capacity;
}

int DS_QueueLength(void *queue) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    return q->length;
}

void* DS_QueuePop(void *queue, void *destination) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    //REMOVE if block to remove out of bounds check.
    if(q->length == 0) {
        return 0;
    }
    // ^^^^^^^^
    memcpy(destination, queue + q->front, q->size);
    q->front += q->size;
    if(q->front == q->wrap) {
        q->front = 0;
    }
    q->length--;
    return destination;
}

void* DS_QueuePush(void *queue, void *source) {
    struct DS_Queue *q = (struct DS_Queue*) queue - 1;
    // REMOVE if block to remove auto reallocation.
    if(q->length == q->capacity) {
        queue = DS_QueueReallocate(queue, q->length * 2);
        q = (struct DS_Queue*) queue - 1;
    }
    // REMOVE ^^^^^^^^
    q->back += q->size;
    if(q->back == q->wrap) {
        q->back = 0;
    }
    q->length++;
    memcpy(queue + q->back, source, q->size);
    return queue;
}
