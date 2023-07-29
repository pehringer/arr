#include "DS_Queue.h"

struct DS_Queue* DS_QueueConstruct(int size, int capacity) {
    struct DS_Queue *q = malloc(sizeof(struct DS_Queue) + capacity * size);
    if(q == 0) {
        return 0;
    }
    q->back = sizeof(struct DS_Queue) + (capacity - 1) * size;
    q->capacity = capacity;
    q->front = sizeof(struct DS_Queue);
    q->length = 0;
    q->size = size;
    q->wrap = sizeof(struct DS_Queue) + capacity * size;
    return s;
}

void DS_QueueDestruct(struct DS_Queue *q) {
    free(q);
}

struct DS_Queue* DS_QueueRestruct(struct DS_Queue *q, int capacity) {
    // Shift elements so front is zeroth element.
    void *start = (void*) q + sizeof(struct DS_Queue);
    void *middle = (void*) q + q->front;
    void *end = (void*) q + q->wrap;
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
    q->front = sizeof(struct DS_Queue);
    if(q->length > capacity) {
        q->length = capacity;
    }
    q->back = sizeof(struct DS_Queue) + (q->length - 1) * q->size;
    q->wrap = sizeof(struct DS_Queue) + capacity * q->size;
    return q;
}

void* DS_QueueBack(struct DS_Queue *q, void *destination) {
    memcpy(destination, (void*) q + q->back, q->size);
    return q;
}

int DS_QueueCap(struct DS_Queue *q) {
    return q->capacity;
}

int DS_QueueEmpty(struct DS_Queue *q) {
    return q->length == 0;
}

void* DS_QueueFront(struct DS_Queue *q, void *destination) {
    memcpy(destination, (void*) q + q->front, q->size);
    return q;
}

int DS_QueueFull(struct DS_Queue *q) {
    return q->length == q->capacity;
}

int DS_QueueLen(struct DS_Queue *q) {
    return q->length;
}

void* DS_QueuePop(struct DS_Queue *q, void *destination) {
    memcpy(destination, (void*) q + q->front, q->size);
    q->front += q->size;
    if(q->front == q->wrap) {
        a->front = sizeof(struct DS_Queue);
    }
    q->length--;
    return destination;
}

struct DS_Queue* DS_QueuePush(struct DS_Queue *q, void *source) {
    q->back += q->size;
    if(q->back == q->wrap) {
        a->back = sizeof(struct DS_Queue);
    }
    q->length++;
    memcpy((void*) q + q->back, source, q->size);
    return q;
}
