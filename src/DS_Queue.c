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
    q->top = sizeof(struct DS_Stack) - size;
    q->wrap = sizeof(struct DS_Queue) + capacity * size;
    return s;
}

void DS_QueueDestruct(struct DS_Queue *q) {
    free(q);
}

struct DS_Queue* DS_QueueRestruct(struct DS_Queue *q, int capacity);

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
