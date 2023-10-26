#include "Test.h"
#include "DS_Stack.h"

int NewDeleteZero() {
    int failed = 0;
    void *stk = DS_StackAllocate(64, 0);
    if(stk == 0) return ++failed;
    DS_StackDeallocate(stk);
    return failed;
}

int NewDeleteMany() {
    int failed = 0;
    int *stk = DS_StackAllocate(64, 4);
    if(stk == 0) return ++failed;
    stk[0] = 0;
    stk[1] = 1;
    stk[2] = 2;
    stk[3] = 3;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeBiggerEmpty() {
    int failed = 0;
    int *stk = DS_StackAllocate(sizeof(int), 0);
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) return ++failed;
    stk[0] = 0;
    stk[1] = 1;
    stk[2] = 2;
    stk[3] = 3;
    stk = DS_StackReallocate(stk, 8);
    if(stk == 0) return ++failed;
    stk[4] = 4;
    stk[5] = 5;
    stk[6] = 6;
    stk[7] = 7;
    if(stk[0] != 0) failed++;
    if(stk[1] != 1) failed++;
    if(stk[2] != 2) failed++;
    if(stk[3] != 3) failed++;
    if(stk[4] != 4) failed++;
    if(stk[5] != 5) failed++;
    if(stk[6] != 6) failed++;
    if(stk[7] != 7) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeSmallerEmpty() {
    int failed = 0;
    int *stk = DS_StackAllocate(sizeof(int), 8);
    stk[0] = 0;
    stk[1] = 1;
    stk[2] = 2;
    stk[3] = 3;
    stk[4] = 4;
    stk[5] = 5;
    stk[6] = 6;
    stk[7] = 7;
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) failed++;
    if(stk[0] != 0) failed++;
    if(stk[1] != 1) failed++;
    if(stk[2] != 2) failed++;
    if(stk[3] != 3) failed++;
    stk = DS_StackReallocate(stk, 0);
    if(stk == 0) return ++failed;
    DS_StackDeallocate(stk);
    return failed;
}

int PushTopPop() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 4);
    val = 1;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 1) failed++;
    val = 2;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 2) failed++;
    val = 3;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    val = 4;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 4) failed++;
    if(*((int*) DS_StackPop(stk, &val)) != 4) failed++;
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    if(*((int*) DS_StackPop(stk, &val)) != 3) failed++;
    if(*((int*) DS_StackTop(stk, &val)) != 2) failed++;
    if(*((int*) DS_StackPop(stk, &val)) != 2) failed++;
    if(*((int*) DS_StackTop(stk, &val)) != 1) failed++;
    if(*((int*) DS_StackPop(stk, &val)) != 1) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int Capacity() {
    int failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 0);
    if(DS_StackCapacity(stk) != 0) failed++;
    stk = DS_StackReallocate(stk, 4);
    if(DS_StackCapacity(stk) != 4) failed++;
    stk = DS_StackReallocate(stk, 8);
    if(DS_StackCapacity(stk) != 8) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int Empty() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 4);
    if(DS_StackEmpty(stk) == 0) failed++;
    val = 42;
    DS_StackPush(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackEmpty(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackEmpty(stk) == 0) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int Full() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 4);
    if(DS_StackFull(stk) != 0) failed++;
    val = 42;
    DS_StackPush(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackFull(stk) == 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackFull(stk) != 0) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int Length() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 4);
    if(DS_StackLength(stk) != 0) failed++;
    val = 42;
    DS_StackPush(stk, &val);
    if(DS_StackLength(stk) != 1) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLength(stk) != 2) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLength(stk) != 3) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLength(stk) != 4) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLength(stk) != 3) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLength(stk) != 2) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLength(stk) != 1) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLength(stk) != 0) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeBiggerFull() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 0);
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) return ++failed;
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    val = 3;
    DS_StackPush(stk, &val);
    stk = DS_StackReallocate(stk, 8);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    val = 6;
    DS_StackPush(stk, &val);
    val = 7;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 7) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeSmallerFull() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 8);
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    val = 3;
    DS_StackPush(stk, &val);
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    val = 6;
    DS_StackPush(stk, &val);
    val = 7;
    DS_StackPush(stk, &val);
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    stk = DS_StackReallocate(stk, 0);
    if(stk == 0) return ++failed;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeBiggerNonEmpty() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 0);
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) return ++failed;
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    stk = DS_StackReallocate(stk, 8);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 2) failed++;
    val = 3;
    DS_StackPush(stk, &val);
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 5) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int ResizeSmallerNonEmpty() {
    int val, failed = 0;
    void *stk = DS_StackAllocate(sizeof(int), 8);
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    val = 3;
    DS_StackPush(stk, &val);
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    stk = DS_StackReallocate(stk, 4);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    DS_StackPop(stk, &val);
    DS_StackPop(stk, &val);
    stk = DS_StackReallocate(stk, 0);
    if(stk == 0) return ++failed;
    DS_StackDeallocate(stk);
    return failed;
}

int AutoResize() {
    int val, failed = 0;
    int *stk = DS_StackAllocate(sizeof(int), 2);
    val = 0;
    stk = DS_StackPush(stk, &val);
    val = 1;
    stk = DS_StackPush(stk, &val);
    val = 2;
    stk = DS_StackPush(stk, &val);
    val = 3;
    stk = DS_StackPush(stk, &val);
    val = 4;
    stk = DS_StackPush(stk, &val);
    val = 5;
    stk = DS_StackPush(stk, &val);
    if(DS_StackLength(stk) != 6) failed++;
    if(DS_StackCapacity(stk) != 8) failed++;
    if(stk[0] != 0) failed++;
    if(stk[1] != 1) failed++;
    if(stk[2] != 2) failed++;
    if(stk[3] != 3) failed++;
    if(stk[4] != 4) failed++;
    if(stk[5] != 5) failed++;
    if(*((int*) DS_StackTop(stk, &val)) != 5) failed++;
    DS_StackDeallocate(stk);
    return failed;
}

int main() {
    RunTests(14, (struct Test[14]) {
        (struct Test) {NewDeleteZero, "NewDeleteZero"},
        (struct Test) {NewDeleteMany, "NewDeleteMany"},
        (struct Test) {ResizeBiggerEmpty, "ResizeBiggerEmpty"},
        (struct Test) {ResizeSmallerEmpty, "ResizeSmallerEmpty"},
        (struct Test) {PushTopPop, "PushTopPop"},
        (struct Test) {Capacity, "Capacity"},
        (struct Test) {Empty, "Empty"},
        (struct Test) {Full, "Full"},
        (struct Test) {Length, "Length"},
        (struct Test) {ResizeBiggerFull, "ResizeBiggerFull"},
        (struct Test) {ResizeSmallerFull, "ResizeSmallerFull"},
        (struct Test) {ResizeBiggerNonEmpty, "ResizeBiggerNonEmpty"},
        (struct Test) {ResizeSmallerNonEmpty, "ResizeSmallerNonEmpty"},
        (struct Test) {AutoResize, "AutoResize"},
    });
    return 0;
}
