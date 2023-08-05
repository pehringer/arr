#include "Test.h"
#include "DS_Queue.h"

int QueChk(struct DS_Queue *que, size_t size, int len, int cap) {
    int failed = 0;
    if(que->capacity != cap) failed++;
    if(que->length != len) failed++;
    if(que->size != size) failed++;
    return failed;
}

int NewDeleteZero() {
    int failed = 0;
    struct DS_Queue *que = DS_QueueConstruct(64, 0);
    if(que == 0) return ++failed;
    failed += QueChk(que, 64, 0, 0);
    DS_QueueDestruct(que);
    return failed;
}

int NewDeleteMany() {
    int failed = 0;
    struct DS_Queue *que = DS_QueueConstruct(64, 4);
    if(que == 0) return ++failed;
    failed += QueChk(que, 64, 0, 4);
    *((int*) (que + 1) + 0) = 0;
    *((int*) (que + 1) + 1) = 1;
    *((int*) (que + 1) + 2) = 2;
    *((int*) (que + 1) + 3) = 3;
    DS_QueueDestruct(que);
    return failed;
}

int ResizeBiggerEmpty() {
    int failed = 0;
    struct DS_Queue *que = DS_QueueConstruct(sizeof(int), 0);
    que = DS_QueueRestruct(que, 4);
    if(que == 0) return ++failed;
    failed += QueChk(que, sizeof(int), 0, 4);
    *((int*) (que + 1) + 0) = 0;
    *((int*) (que + 1) + 1) = 1;
    *((int*) (que + 1) + 2) = 2;
    *((int*) (que + 1) + 3) = 3;
    que = DS_QueueRestruct(que, 8);
    if(que == 0) return ++failed;
    failed += QueChk(que, sizeof(int), 0, 8);
    *((int*) (que + 1) + 4) = 4;
    *((int*) (que + 1) + 5) = 5;
    *((int*) (que + 1) + 6) = 6;
    *((int*) (que + 1) + 7) = 7;
    if(*((int*) (que + 1) + 0) != 0) failed++;
    if(*((int*) (que + 1) + 1) != 1) failed++;
    if(*((int*) (que + 1) + 2) != 2) failed++;
    if(*((int*) (que + 1) + 3) != 3) failed++;
    if(*((int*) (que + 1) + 4) != 4) failed++;
    if(*((int*) (que + 1) + 5) != 5) failed++;
    if(*((int*) (que + 1) + 6) != 6) failed++;
    if(*((int*) (que + 1) + 7) != 7) failed++;
    DS_QueueDestruct(que);
    return failed;
}

int ResizeSmallerEmpty() {
    int failed = 0;
    struct DS_Queue *que = DS_QueueConstruct(sizeof(int), 8);
    *((int*) (que + 1) + 0) = 0;
    *((int*) (que + 1) + 1) = 1;
    *((int*) (que + 1) + 2) = 2;
    *((int*) (que + 1) + 3) = 3;
    *((int*) (que + 1) + 4) = 4;
    *((int*) (que + 1) + 5) = 5;
    *((int*) (que + 1) + 6) = 6;
    *((int*) (que + 1) + 7) = 7;
    que = DS_QueueRestruct(que, 4);
    if(que == 0) failed++;
    failed += QueChk(que, sizeof(int), 0, 4);
    if(*((int*) (que + 1) + 0) != 0) failed++;
    if(*((int*) (que + 1) + 1) != 1) failed++;
    if(*((int*) (que + 1) + 2) != 2) failed++;
    if(*((int*) (que + 1) + 3) != 3) failed++;
    que = DS_QueueRestruct(que, 0);
    if(que == 0) return ++failed;
    failed += QueChk(que, sizeof(int), 0, 0);
    DS_QueueDestruct(que);
    return failed;
}

int main() {
    RunTests(4, (struct Test[4]) {
        (struct Test) {NewDeleteZero, "NewDeleteZero"},
        (struct Test) {NewDeleteMany, "NewDeleteMany"},
        (struct Test) {ResizeBiggerEmpty, "ResizeBiggerEmpty"},
        (struct Test) {ResizeSmallerEmpty, "ResizeSmallerEmpty"},
    });
}
