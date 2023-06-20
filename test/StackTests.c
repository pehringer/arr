#include "Test.h"
#include "CDS_Stack.h"

int ConstructDestructCapacityZero() {
    int failed = 0;
    struct CDS_Stack stack;
    if(CDS_StackConstruct(&stack, sizeof(int), 0) == 0 ||
        stack.length != 0 ||
        stack.capacity != 0 ||
        stack.size != sizeof(int)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    if(stack.first != 0 ||
        stack.top != 0 ||
        stack.capacity != 0 ||
        stack.length != 0 ||
        stack.size != 0) {
        failed++;
    }
    return failed;
}

int ConstructDestructCapacityNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    if(CDS_StackConstruct(&stack, sizeof(int), 8) == 0 ||
        stack.length != 0 ||
        stack.capacity != 8 ||
        stack.size != sizeof(int)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    if(stack.first != 0 ||
        stack.top != 0 ||
        stack.capacity != 0 ||
        stack.length != 0 ||
        stack.size != 0) {
        failed++;
    }
    return failed;
}

int FromArrayToArrayNone() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int),8);
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int to[8] = {256, 512, 1024, 2048, 4096, 8192, 16382, 32768};
    CDS_StackToArray(CDS_StackFromArray(&stack, from, 0), to, 0);
    if(stack.capacity != 8 ||
        stack.length != 0 ||
        stack.size != sizeof(int) ||
        stack.top != stack.first - stack.size) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    if(to[0] != 256 ||
        to[1] != 512 ||
        to[2] != 1024 ||
        to[3] != 2048 ||
        to[4] != 4096 ||
        to[5] != 8192 ||
        to[6] != 16382 ||
        to[7] != 32768) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FromArrayToArrayAll() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int to[8] = {256, 512, 1024, 2048, 4096, 8192, 16382, 32768};
    CDS_StackToArray(CDS_StackFromArray(&stack, from, 8), to, 8);
    if(stack.capacity != 8 ||
        stack.length != 8 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 128) {
        failed++;
    }
/*
    printf("\nDebug 0: %d\n", failed);
    printf("cap: %d\n", stack.capacity);
    printf("len: %d\n", stack.length);
    printf("siz: %d\n", stack.size);
    printf("top: %d\n", *((int*) stack.top));
*/
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8 ||
        ((int*) stack.first)[4] != 16 ||
        ((int*) stack.first)[5] != 32 ||
        ((int*) stack.first)[6] != 64 ||
        ((int*) stack.first)[7] != 128) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    if(to[0] != 1 ||
        to[1] != 2 ||
        to[2] != 4 ||
        to[3] != 8 ||
        to[4] != 16 ||
        to[5] != 32 ||
        to[6] != 64 ||
        to[7] != 128) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FromArrayHalfToArrayAll() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int to[8] = {256, 512, 1024, 2048, 4096, 8192, 16382, 32768};
    CDS_StackToArray(CDS_StackFromArray(&stack, from, 4), to, 4);
    if(stack.capacity != 8 ||
        stack.length != 4 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 8) {
        failed++;
    }
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    if(to[0] != 1 ||
        to[1] != 2 ||
        to[2] != 4 ||
        to[3] != 8 ||
        to[4] != 4096 ||
        to[5] != 8192 ||
        to[6] != 16382 ||
        to[7] != 32768) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FromArrayAllToArrayHalf() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    int to[8] = {256, 512, 1024, 2048, 4096, 8192, 16382, 32768};
    CDS_StackToArray(CDS_StackFromArray(&stack, from, 8), to, 4);
    if(stack.capacity != 8 ||
        stack.length != 8 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 128) {
        failed++;
    }
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8 ||
        ((int*) stack.first)[4] != 16 ||
        ((int*) stack.first)[5] != 32 ||
        ((int*) stack.first)[6] != 64 ||
        ((int*) stack.first)[7] != 128) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    if(to[0] != 16 ||
        to[1] != 32 ||
        to[2] != 64 ||
        to[3] != 128 ||
        to[4] != 4096 ||
        to[5] != 8192 ||
        to[6] != 16382 ||
        to[7] != 32768) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int ResizeFromZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(CDS_StackResize(&stack, 8) == 0 ||
        stack.top != stack.first - stack.size ||
        stack.capacity != 8 ||
        stack.length != 0 ||
        stack.size != sizeof(int)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int ResizeToZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackResize(&stack, 0) == 0 ||
        stack.top != stack.first - stack.size ||
        stack.capacity != 0 ||
        stack.length != 0 ||
        stack.size != sizeof(int)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int ResizeSameSize() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackFromArray(CDS_StackConstruct(&stack, sizeof(int), 8), from, 8);
    if(CDS_StackResize(&stack, 8) == 0 ||
        stack.capacity != 8 ||
        stack.length != 8 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 128) {
        failed++;
    }
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8 ||
        ((int*) stack.first)[4] != 16 ||
        ((int*) stack.first)[5] != 32 ||
        ((int*) stack.first)[6] != 64 ||
        ((int*) stack.first)[7] != 128) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int ResizeBiggerSize() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackFromArray(CDS_StackConstruct(&stack, sizeof(int), 8), from, 8);
    if(CDS_StackResize(&stack, 16) == 0 ||
        stack.capacity != 16 ||
        stack.length != 8 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 128) {
        failed++;
    }
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8 ||
        ((int*) stack.first)[4] != 16 ||
        ((int*) stack.first)[5] != 32 ||
        ((int*) stack.first)[6] != 64 ||
        ((int*) stack.first)[7] != 128) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int ResizeSmallerSize() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackFromArray(CDS_StackConstruct(&stack, sizeof(int), 8), from, 8);
    if(CDS_StackResize(&stack, 4) == 0 ||
        stack.capacity != 4 ||
        stack.length != 4 ||
        stack.size != sizeof(int) ||
        *((int*) stack.top) != 8) {
        failed++;
    }
    if(((int*) stack.first)[0] != 1 ||
        ((int*) stack.first)[1] != 2 ||
        ((int*) stack.first)[2] != 4 ||
        ((int*) stack.first)[3] != 8) {
        failed++;
    }
    if(from[0] != 1 ||
        from[1] != 2 ||
        from[2] != 4 ||
        from[3] != 8 ||
        from[4] != 16 ||
        from[5] != 32 ||
        from[6] != 64 ||
        from[7] != 128) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int CapacityZeroToNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(CDS_StackCapacity(&stack) != 0) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackCapacity(&stack) != 4) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackCapacity(&stack) != 4) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int CapacityNonZeroToZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 4);
    if(CDS_StackCapacity(&stack) != 4) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackCapacity(&stack) != 4) {
        failed++;
    }
    CDS_StackResize(&stack, 0);
    if(CDS_StackCapacity(&stack) != 0) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int CapacityResizeBigger() {
   int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackCapacity(&stack) != 8) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackCapacity(&stack) != 8) {
        failed++;
    }
    CDS_StackResize(&stack, 16);
    if(CDS_StackCapacity(&stack) != 16) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int CapacityResizeSmaller() {
   int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackCapacity(&stack) != 8) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackCapacity(&stack) != 8) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackCapacity(&stack) != 4) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int LengthZeroToNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackLength(&stack) != 4) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int LengthNonZeroToZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 4);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackLength(&stack) != 4) {
        failed++;
    }
    CDS_StackResize(&stack, 0);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int LengthResizeBigger() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackLength(&stack) != 8) {
        failed++;
    }
    CDS_StackResize(&stack, 16);
    if(CDS_StackLength(&stack) != 8) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int LengthResizeSmaller() {
   int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackLength(&stack) != 0) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackLength(&stack) != 8) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackLength(&stack) != 4) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyCapacityZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyCapacityNonZeroLengthZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyLengthNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackFromArray(CDS_StackConstruct(&stack, sizeof(int), 8), from, 8);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyZeroToNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyNonZeroToZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 4);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 0);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyResizeBigger() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 16);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int EmptyResizeSmaller() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(!CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackEmpty(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullCapacityZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullCapacityNonZeroLengthZero() {
    int failed = 0;
    struct CDS_Stack stack;
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullLengthNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackFromArray(CDS_StackConstruct(&stack, sizeof(int), 8), from, 8);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullZeroToNonZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 0);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullNonZeroToZero() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[4] = {1, 2, 4, 8};
    CDS_StackConstruct(&stack, sizeof(int), 4);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 4);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 0);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullResizeBigger() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 16);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}

int FullResizeSmaller() {
    int failed = 0;
    struct CDS_Stack stack;
    int from[8] = {1, 2, 4, 8, 16, 32, 64, 128};
    CDS_StackConstruct(&stack, sizeof(int), 8);
    if(CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackFromArray(&stack, from, 8);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackResize(&stack, 4);
    if(!CDS_StackFull(&stack)) {
        failed++;
    }
    CDS_StackDestruct(&stack);
    return failed;
}



int main() {
    RunTests(33, (struct Test[33]) {
        (struct Test) {ConstructDestructCapacityZero, "ConstructDestructCapacityZero"},
        (struct Test) {ConstructDestructCapacityNonZero, "ConstructDestructCapacityNonZero"},
        (struct Test) {FromArrayToArrayAll, "FromArrayToArrayAll"},
        (struct Test) {FromArrayHalfToArrayAll, "FromArrayHalfToArrayAll"},
        (struct Test) {FromArrayAllToArrayHalf, "FromArrayAllToArrayHalf"},
        (struct Test) {FromArrayToArrayNone, "FromArrayToArrayNone"},
        (struct Test) {ResizeFromZero, "ResizeFromZero"},
        (struct Test) {ResizeFromZero, "ResizeToZero"},
        (struct Test) {ResizeSameSize, "ResizeSameSize"},
        (struct Test) {ResizeBiggerSize, "ResizeBiggerSize"},
        (struct Test) {ResizeSmallerSize, "ResizeSmallerSize"},
        (struct Test) {CapacityZeroToNonZero, "CapacityZeroToNonZero"},
        (struct Test) {CapacityNonZeroToZero, "CapacityNonZeroToZero"},
        (struct Test) {CapacityResizeBigger, "CapacityResizeBigger"},
        (struct Test) {CapacityResizeSmaller, "CapacityResizeSmaller"},
        (struct Test) {LengthZeroToNonZero, "LengthZeroToNonZero"},
        (struct Test) {LengthNonZeroToZero, "LengthNonZeroToZero"},
        (struct Test) {LengthResizeBigger, "LengthResizeBigger"},
        (struct Test) {LengthResizeSmaller, "LengthResizeSmaller"},
        (struct Test) {EmptyCapacityZero, "EmptyCapacityZero"},
        (struct Test) {EmptyCapacityNonZeroLengthZero, "EmptyCapacityNonZeroLengthZero"},
        (struct Test) {EmptyLengthNonZero, "EmptyLengthNonZero"},
        (struct Test) {EmptyZeroToNonZero, "EmptyZeroToNonZero"},
        (struct Test) {EmptyNonZeroToZero, "EmptyNonZeroToZero"},
        (struct Test) {EmptyResizeBigger, "EmptyResizeBigger"},
        (struct Test) {EmptyResizeSmaller, "EmptyResizeSmaller"},
        (struct Test) {FullCapacityZero, "FullCapacityZero"},
        (struct Test) {FullCapacityNonZeroLengthZero, "FullCapacityNonZeroLengthZero"},
        (struct Test) {FullLengthNonZero, "FullLengthNonZero"},
        (struct Test) {FullZeroToNonZero, "FullZeroToNonZero"},
        (struct Test) {FullNonZeroToZero, "FullNonZeroToZero"},
        (struct Test) {FullResizeBigger, "FullResizeBigger"},
        (struct Test) {FullResizeSmaller, "FullResizeSmaller"},
    });
    return 0;
}
