#ifndef DS_QUEUE_H
#define DS_QUEUE_H

#include <stdlib.h>
#include <string.h>

void* DS_QueueAllocate(int size, int capacity);

void DS_QueueDeallocate(void *queue);

void* DS_QueueReallocate(void *queue, int capacity);

void* DS_QueueBack(void *queue, void *destination);

int DS_QueueCapacity(void *queue);

int DS_QueueEmpty(void *queue);

void* DS_QueueFront(void *queue, void *destination);

int DS_QueueFull(void *queue);

int DS_QueueLength(void *queue);

void* DS_QueuePop(void *queue, void *destination);

void* DS_QueuePush(void *queue, void *source);

#endif
