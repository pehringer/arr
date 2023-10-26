#include "Test.h"
#include "DS_Queue.h"

int NewDeleteZero() {
    int failed = 0;
    void *que = DS_QueueAllocate(64, 0);
    if(que == 0) return ++failed;
    DS_QueueDeallocate(que);
    return failed;
}

int NewDeleteMany() {
    int failed = 0;
    int *que = DS_QueueAllocate(64, 4);
    if(que == 0) return ++failed;
    que[0] = 0;
    que[1] = 1;
    que[2] = 2;
    que[3] = 3;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeBiggerEmpty() {
    int failed = 0;
    int *que = DS_QueueAllocate(sizeof(int), 0);
    que = DS_QueueReallocate(que, 4);
    if(que == 0) return ++failed;
    que[0] = 0;
    que[1] = 1;
    que[2] = 2;
    que[3] = 3;
    que = DS_QueueReallocate(que, 8);
    if(que == 0) return ++failed;
    que[4] = 4;
    que[5] = 5;
    que[6] = 6;
    que[7] = 7;
    if(que[0] != 0) failed++;
    if(que[1] != 1) failed++;
    if(que[2] != 2) failed++;
    if(que[3] != 3) failed++;
    if(que[4] != 4) failed++;
    if(que[5] != 5) failed++;
    if(que[6] != 6) failed++;
    if(que[7] != 7) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeSmallerEmpty() {
    int failed = 0;
    int *que = DS_QueueAllocate(sizeof(int), 8);
    que[0] = 0;
    que[1] = 1;
    que[2] = 2;
    que[3] = 3;
    que[4] = 4;
    que[5] = 5;
    que[6] = 6;
    que[7] = 7;
    que = DS_QueueReallocate(que, 4);
    if(que == 0) failed++;
    if(que[0] != 0) failed++;
    if(que[1] != 1) failed++;
    if(que[2] != 2) failed++;
    if(que[3] != 3) failed++;
    que = DS_QueueReallocate(que, 0);
    if(que == 0) return ++failed;
    DS_QueueDeallocate(que);
    return failed;
}

int PushFrontBackPop() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 4);
    val = 1;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 1) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 1) failed++;
    val = 2;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 1) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 2) failed++;
    val = 3;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 1) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 3) failed++;
    val = 4;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 1) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 4) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 1) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 2) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 4) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 2) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 3) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 4) failed++;
    val = 5;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 3) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 5) failed++;
    val = 6;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueueFront(que, &val)) != 3) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 6) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 3) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 4) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 6) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 4) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 5) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 6) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 5) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 6) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 6) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 6) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int Capacity() {
    int failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 0);
    if(DS_QueueCapacity(que) != 0) failed++;
    que = DS_QueueReallocate(que, 4);
    if(DS_QueueCapacity(que) != 4) failed++;
    que = DS_QueueReallocate(que, 8);
    if(DS_QueueCapacity(que) != 8) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int Empty() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 4);
    if(DS_QueueEmpty(que) == 0) failed++;
    val = 42;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) == 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueEmpty(que) == 0) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int Full() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 4);
    if(DS_QueueFull(que) != 0) failed++;
    val = 42;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) == 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) != 0) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueFull(que) == 0) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int Length() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 4);
    if(DS_QueueLength(que) != 0) failed++;
    val = 42;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 1) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 2) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 3) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 4) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 3) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 2) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 3) failed++;
    DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 4) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 3) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 2) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 1) failed++;
    DS_QueuePop(que, &val);
    if(DS_QueueLength(que) != 0) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeBiggerFull() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 0);
    que = DS_QueueReallocate(que, 2);
    if(que == 0) return ++failed;
    val = 0;
    DS_QueuePush(que, &val);
    val = 1;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 4);
    if(que == 0) return ++failed;
    val = 2;
    DS_QueuePush(que, &val);
    val = 3;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 0) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 1) failed++;
    val = 4;
    DS_QueuePush(que, &val);
    val = 5;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 6);
    if(que == 0) return ++failed;
    val = 6;
    DS_QueuePush(que, &val);
    val = 7;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 2) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 3) failed++;
    val = 8;
    DS_QueuePush(que, &val);
    val = 9;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 4) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 5) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 6) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 7) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 8) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 9) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeSmallerFull() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 6);
    if(que == 0) return failed++;
    val = 0;
    DS_QueuePush(que, &val);
    val = 1;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 0) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 1) failed++;
    val = 2;
    DS_QueuePush(que, &val);
    val = 3;
    DS_QueuePush(que, &val);
    val = 4;
    DS_QueuePush(que, &val);
    val = 5;
    DS_QueuePush(que, &val);
    val = 6;
    DS_QueuePush(que, &val);
    val = 7;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 4);
    if(que == 0) return failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 2) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 3) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 4) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 5) failed++;
    val = 8;
    DS_QueuePush(que, &val);
    val = 9;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 8) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 9) failed++;
    val = 10;
    DS_QueuePush(que, &val);
    val = 11;
    DS_QueuePush(que, &val);
    val = 12;
    DS_QueuePush(que, &val);
    val = 13;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 2);
    if(que == 0) return failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 10) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 11) failed++;
    val = 14;
    DS_QueuePush(que, &val);
    val = 15;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 0);
    if(que == 0) return failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeHalfFullBigger() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 0);
    que = DS_QueueReallocate(que, 2);
    if(que == 0) return ++failed;
    val = 0;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 4);
    if(que == 0) return ++failed;
    val = 1;
    DS_QueuePush(que, &val);
    val = 2;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 0) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 1) failed++;
    val = 3;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 6);
    if(que == 0) return ++failed;
    val = 4;
    DS_QueuePush(que, &val);
    val = 5;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 2) failed++;
    que = DS_QueueReallocate(que, 8);
    if(que == 0) return ++failed;
    if(*((int*) DS_QueuePop(que, &val)) != 3) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 4) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 5) failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int ResizeHalfFullSmaller() {
    int val, failed = 0;
    void *que = DS_QueueAllocate(sizeof(int), 6);
    if(que == 0) return failed++;
    val = 0;
    DS_QueuePush(que, &val);
    val = 1;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 0) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 1) failed++;
    val = 2;
    DS_QueuePush(que, &val);
    val = 3;
    DS_QueuePush(que, &val);
    val = 4;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 4);
    if(que == 0) return failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 2) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 3) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 4) failed++;
    val = 8;
    DS_QueuePush(que, &val);
    val = 9;
    DS_QueuePush(que, &val);
    val = 10;
    DS_QueuePush(que, &val);
    if(*((int*) DS_QueuePop(que, &val)) != 8) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 9) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 10) failed++;
    val = 11;
    DS_QueuePush(que, &val);
    val = 12;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 2);
    if(que == 0) return failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 11) failed++;
    if(*((int*) DS_QueuePop(que, &val)) != 12) failed++;
    val = 14;
    DS_QueuePush(que, &val);
    que = DS_QueueReallocate(que, 0);
    if(que == 0) return failed++;
    DS_QueueDeallocate(que);
    return failed;
}

int AutoResize() {
    int val, failed = 0;
    int *que = DS_QueueAllocate(sizeof(int), 2);
    val = 0;
    que = DS_QueuePush(que, &val);
    val = 1;
    que = DS_QueuePush(que, &val);
    val = 2;
    que = DS_QueuePush(que, &val);
    val = 3;
    que = DS_QueuePush(que, &val);
    val = 4;
    que = DS_QueuePush(que, &val);
    val = 5;
    que = DS_QueuePush(que, &val);
    if(DS_QueueLength(que) != 6) failed++;
    if(DS_QueueCapacity(que) != 8) failed++;
    if(que[0] != 0) failed++;
    if(que[1] != 1) failed++;
    if(que[2] != 2) failed++;
    if(que[3] != 3) failed++;
    if(que[4] != 4) failed++;
    if(que[5] != 5) failed++;
    if(*((int*) DS_QueueFront(que, &val)) != 0) failed++;
    if(*((int*) DS_QueueBack(que, &val)) != 5) failed++;
    DS_QueueDeallocate(que);
    return failed;
}


int main() {
    RunTests(14, (struct Test[14]) {
        (struct Test) {NewDeleteZero, "NewDeleteZero"},
        (struct Test) {NewDeleteMany, "NewDeleteMany"},
        (struct Test) {ResizeBiggerEmpty, "ResizeBiggerEmpty"},
        (struct Test) {ResizeSmallerEmpty, "ResizeSmallerEmpty"},
        (struct Test) {PushFrontBackPop, "PushFrontBackPop"},
        (struct Test) {Capacity, "Capacity"},
        (struct Test) {Empty, "Empty"},
        (struct Test) {Full, "Full"},
        (struct Test) {Length, "Length"},
        (struct Test) {ResizeBiggerFull, "ResizeBiggerFull"},
        (struct Test) {ResizeSmallerFull, "ResizeSmallerFull"},
        (struct Test) {ResizeHalfFullBigger, "ResizeHalfFullBigger"},
        (struct Test) {ResizeHalfFullSmaller, "ResizeHalfFullSmaller"},
        (struct Test) {AutoResize, "AutoResize"},
    });
}
