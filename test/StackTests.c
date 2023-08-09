#include "Test.h"
#include "DS_Stack.h"

int StkChk(struct DS_Stack *stk, size_t size, int len, int cap) {
    int failed = 0;
    if(stk->capacity != cap) failed++;
    if(stk->length != len) failed++;
    if(stk->size != size) failed++;
    return failed;
}

int NewDeleteZero() {
    int failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(64, 0);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, 64, 0, 0);
    DS_StackDealloc(stk);
    return failed;
}

int NewDeleteMany() {
    int failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(64, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, 64, 0, 4);
    *((int*) (stk + 1) + 0) = 0;
    *((int*) (stk + 1) + 1) = 1;
    *((int*) (stk + 1) + 2) = 2;
    *((int*) (stk + 1) + 3) = 3;
    DS_StackDealloc(stk);
    return failed;
}

int ResizeBiggerEmpty() {
    int failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 0);
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 4);
    *((int*) (stk + 1) + 0) = 0;
    *((int*) (stk + 1) + 1) = 1;
    *((int*) (stk + 1) + 2) = 2;
    *((int*) (stk + 1) + 3) = 3;
    stk = DS_StackRealloc(stk, 8);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 8);
    *((int*) (stk + 1) + 4) = 4;
    *((int*) (stk + 1) + 5) = 5;
    *((int*) (stk + 1) + 6) = 6;
    *((int*) (stk + 1) + 7) = 7;
    if(*((int*) (stk + 1) + 0) != 0) failed++;
    if(*((int*) (stk + 1) + 1) != 1) failed++;
    if(*((int*) (stk + 1) + 2) != 2) failed++;
    if(*((int*) (stk + 1) + 3) != 3) failed++;
    if(*((int*) (stk + 1) + 4) != 4) failed++;
    if(*((int*) (stk + 1) + 5) != 5) failed++;
    if(*((int*) (stk + 1) + 6) != 6) failed++;
    if(*((int*) (stk + 1) + 7) != 7) failed++;
    DS_StackDealloc(stk);
    return failed;
}

int ResizeSmallerEmpty() {
    int failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 8);
    *((int*) (stk + 1) + 0) = 0;
    *((int*) (stk + 1) + 1) = 1;
    *((int*) (stk + 1) + 2) = 2;
    *((int*) (stk + 1) + 3) = 3;
    *((int*) (stk + 1) + 4) = 4;
    *((int*) (stk + 1) + 5) = 5;
    *((int*) (stk + 1) + 6) = 6;
    *((int*) (stk + 1) + 7) = 7;
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) failed++;
    failed += StkChk(stk, sizeof(int), 0, 4);
    if(*((int*) (stk + 1) + 0) != 0) failed++;
    if(*((int*) (stk + 1) + 1) != 1) failed++;
    if(*((int*) (stk + 1) + 2) != 2) failed++;
    if(*((int*) (stk + 1) + 3) != 3) failed++;
    stk = DS_StackRealloc(stk, 0);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 0);
    DS_StackDealloc(stk);
    return failed;
}

int PushTopPop() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 4);
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
    failed += StkChk(stk, sizeof(int), 0, 4);
    DS_StackDealloc(stk);
    return failed;
}

int Capacity() {
    int failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 0);
    if(DS_StackCap(stk) != 0) failed++;
    failed += StkChk(stk, sizeof(int), 0, 0);
    stk = DS_StackRealloc(stk, 4);
    if(DS_StackCap(stk) != 4) failed++;
    failed += StkChk(stk, sizeof(int), 0, 4);
    stk = DS_StackRealloc(stk, 8);
    if(DS_StackCap(stk) != 8) failed++;
    failed += StkChk(stk, sizeof(int), 0, 8);
    DS_StackDealloc(stk);
    return failed;
}

int Empty() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 4);
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
    failed += StkChk(stk, sizeof(int), 0, 4);
    DS_StackDealloc(stk);
    return failed;
}

int Full() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 4);
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
    failed += StkChk(stk, sizeof(int), 0, 4);
    DS_StackDealloc(stk);
    return failed;
}

int Length() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 4);
    if(DS_StackLen(stk) != 0) failed++;
    val = 42;
    DS_StackPush(stk, &val);
    if(DS_StackLen(stk) != 1) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLen(stk) != 2) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLen(stk) != 3) failed++;
    DS_StackPush(stk, &val);
    if(DS_StackLen(stk) != 4) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLen(stk) != 3) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLen(stk) != 2) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLen(stk) != 1) failed++;
    DS_StackPop(stk, &val);
    if(DS_StackLen(stk) != 0) failed++;
    failed += StkChk(stk, sizeof(int), 0, 4);
    DS_StackDealloc(stk);
    return failed;
}

int ResizeBiggerFull() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 0);
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 4);
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    val = 3;
    DS_StackPush(stk, &val);
    stk = DS_StackRealloc(stk, 8);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    failed += StkChk(stk, sizeof(int), 4, 8);
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    val = 6;
    DS_StackPush(stk, &val);
    val = 7;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 7) failed++;
    failed += StkChk(stk, sizeof(int), 8, 8);
    DS_StackDealloc(stk);
    return failed;
}

int ResizeSmallerFull() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 8);
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
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 4, 4);
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    stk = DS_StackRealloc(stk, 0);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 0);
    DS_StackDealloc(stk);
    return failed;
}

int ResizeBiggerNonEmpty() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 0);
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 4);
    val = 0;
    DS_StackPush(stk, &val);
    val = 1;
    DS_StackPush(stk, &val);
    val = 2;
    DS_StackPush(stk, &val);
    stk = DS_StackRealloc(stk, 8);
    if(stk == 0) return ++failed;
    if(*((int*) DS_StackTop(stk, &val)) != 2) failed++;
    failed += StkChk(stk, sizeof(int), 3, 8);
    val = 3;
    DS_StackPush(stk, &val);
    val = 4;
    DS_StackPush(stk, &val);
    val = 5;
    DS_StackPush(stk, &val);
    if(*((int*) DS_StackTop(stk, &val)) != 5) failed++;
    failed += StkChk(stk, sizeof(int), 6, 8);
    DS_StackDealloc(stk);
    return failed;
}

int ResizeSmallerNonEmpty() {
    int val, failed = 0;
    struct DS_Stack *stk = DS_StackAlloc(sizeof(int), 8);
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
    stk = DS_StackRealloc(stk, 4);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 4, 4);
    if(*((int*) DS_StackTop(stk, &val)) != 3) failed++;
    DS_StackPop(stk, &val);
    DS_StackPop(stk, &val);
    stk = DS_StackRealloc(stk, 0);
    if(stk == 0) return ++failed;
    failed += StkChk(stk, sizeof(int), 0, 0);
    DS_StackDealloc(stk);
    return failed;
}

int main() {
    RunTests(13, (struct Test[13]) {
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
    });
    return 0;
}
