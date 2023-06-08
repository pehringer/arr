#include "Test.h"
#include "cds_Array.h"

int ConstructDestructLengthZero() {
    int failed = 0;
    struct cds_Array array;
    if(cds_ArrayConstruct(&array, sizeof(int), 0) == 0 ||
        array.length != 0 || array.sizeOf != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    if(array.base != 0 ||
        array.length != 0 ||
        array.sizeOf != 0) {
        failed++;
    }
    return failed;
}

int ConstructDestructLengthNonZero() {
    int failed = 0;
    struct cds_Array array;
    if(cds_ArrayConstruct(&array, sizeof(int), 8) == 0 ||
        array.length != 8 || array.sizeOf != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    if(array.base != 0 ||
        array.length != 0 ||
        array.sizeOf != 0) {
        failed++;
    }
    return failed;
}


int FromArrayToArrayAll() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int oldArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, oldArray, 8);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || oldArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || oldArray[1] != 1 ||
        ((int*) array.base)[2] != 2 || oldArray[2] != 2 ||
        ((int*) array.base)[3] != 4 || oldArray[3] != 4 ||
        ((int*) array.base)[4] != 8 || oldArray[4] != 8 ||
        ((int*) array.base)[5] != 16 || oldArray[5] != 16 ||
        ((int*) array.base)[6] != 32 || oldArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || oldArray[7] != 64) {
        failed++;
    }
    int newArray[8];
    cds_ArrayToArray(&array, 0, newArray, 8);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || newArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || newArray[1] != 1 ||
        ((int*) array.base)[2] != 2 || newArray[2] != 2 ||
        ((int*) array.base)[3] != 4 || newArray[3] != 4 ||
        ((int*) array.base)[4] != 8 || newArray[4] != 8 ||
        ((int*) array.base)[5] != 16 || newArray[5] != 16 ||
        ((int*) array.base)[6] != 32 || newArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || newArray[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FromArrayToArrayFirstHalf() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int oldArray[4] = {-8, -4, -2, -1};
    cds_ArrayFromArray(&array, 0, oldArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != -8 || oldArray[0] != -8 ||
        ((int*) array.base)[1] != -4 || oldArray[1] != -4 ||
        ((int*) array.base)[2] != -2 || oldArray[2] != -2 ||
        ((int*) array.base)[3] != -1 || oldArray[3] != -1 ||
        ((int*) array.base)[4] != 8 || initArray[4] != 8 ||
        ((int*) array.base)[5] != 16 || initArray[5] != 16 ||
        ((int*) array.base)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 0, newArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != -8 || newArray[0] != -8 ||
        ((int*) array.base)[1] != -4 || newArray[1] != -4 ||
        ((int*) array.base)[2] != -2 || newArray[2] != -2 ||
        ((int*) array.base)[3] != -1 || newArray[3] != -1 ||
        ((int*) array.base)[4] != 8 || initArray[4] != 8 ||
        ((int*) array.base)[5] != 16 || initArray[5] != 16 ||
        ((int*) array.base)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FromArrayToArraySecondHalf() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int oldArray[4] = {-8, -4, -2, -1};
    cds_ArrayFromArray(&array, 4, oldArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.base)[2] != 2 || initArray[2] != 2 ||
        ((int*) array.base)[3] != 4 || initArray[3] != 4 ||
        ((int*) array.base)[4] != -8 || oldArray[0] != -8 ||
        ((int*) array.base)[5] != -4 || oldArray[1] != -4 ||
        ((int*) array.base)[6] != -2 || oldArray[2] != -2 ||
        ((int*) array.base)[7] != -1 || oldArray[3] != -1) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 4, newArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.base)[2] != 2 || initArray[2] != 2 ||
        ((int*) array.base)[3] != 4 || initArray[3] != 4 ||
        ((int*) array.base)[4] != -8 || newArray[0] != -8 ||
        ((int*) array.base)[5] != -4 || newArray[1] != -4 ||
        ((int*) array.base)[6] != -2 || newArray[2] != -2 ||
        ((int*) array.base)[7] != -1 || newArray[3] != -1) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FromArrayToArrayMiddle() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int oldArray[4] = {-8, -4, -2, -1};
    cds_ArrayFromArray(&array, 2, oldArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.base)[2] != -8 || oldArray[0] != -8 ||
        ((int*) array.base)[3] != -4 || oldArray[1] != -4 ||
        ((int*) array.base)[4] != -2 || oldArray[2] != -2 ||
        ((int*) array.base)[5] != -1 || oldArray[3] != -1 ||
        ((int*) array.base)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 2, newArray, 4);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.base)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.base)[2] != -8 || newArray[0] != -8 ||
        ((int*) array.base)[3] != -4 || newArray[1] != -4 ||
        ((int*) array.base)[4] != -2 || newArray[2] != -2 ||
        ((int*) array.base)[5] != -1 || newArray[3] != -1 ||
        ((int*) array.base)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.base)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FromArrayToArrayNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int oldArray[4] = {1, 1, 1, 1};
    cds_ArrayFromArray(&array, 2, oldArray, 0);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 ||
        ((int*) array.base)[1] != 1 ||
        ((int*) array.base)[2] != 2 || oldArray[0] != 1 ||
        ((int*) array.base)[3] != 4 || oldArray[1] != 1 ||
        ((int*) array.base)[4] != 8 || oldArray[2] != 1 ||
        ((int*) array.base)[5] != 16 || oldArray[3] != 1 ||
        ((int*) array.base)[6] != 32 ||
        ((int*) array.base)[7] != 64) {
        failed++;
    }
    int newArray[4] = {0, 0, 0, 0};
    cds_ArrayToArray(&array, 2, newArray, 0);
    if(array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 ||
        ((int*) array.base)[1] != 1 ||
        ((int*) array.base)[2] != 2 || newArray[0] != 0 ||
        ((int*) array.base)[3] != 4 || newArray[1] != 0 ||
        ((int*) array.base)[4] != 8 || newArray[2] != 0 ||
        ((int*) array.base)[5] != 16 || newArray[3] != 0 ||
        ((int*) array.base)[6] != 32 ||
        ((int*) array.base)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int ResizeFromZero() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 0);
    if(cds_ArrayResize(&array, 8) == 0 ||
        array.length != 8 || array.sizeOf != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int ResizeToZero(){
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    if(cds_ArrayResize(&array, 0) == 0 ||
        array.length != 0 || array.sizeOf != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int ResizeSameSize(){
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    if(cds_ArrayResize(&array, 8) == 0 ||
        array.length != 8 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 ||
        ((int*) array.base)[1] != 1 ||
        ((int*) array.base)[2] != 2 ||
        ((int*) array.base)[3] != 4 ||
        ((int*) array.base)[4] != 8 ||
        ((int*) array.base)[5] != 16 ||
        ((int*) array.base)[6] != 32 ||
        ((int*) array.base)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int ResizeBiggerSize(){
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    if(cds_ArrayResize(&array, 16) == 0 ||
        array.length != 16 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 ||
        ((int*) array.base)[1] != 1 ||
        ((int*) array.base)[2] != 2 ||
        ((int*) array.base)[3] != 4 ||
        ((int*) array.base)[4] != 8 ||
        ((int*) array.base)[5] != 16 ||
        ((int*) array.base)[6] != 32 ||
        ((int*) array.base)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int ResizeSmallerSize(){
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    if(cds_ArrayResize(&array, 4) == 0 ||
        array.length != 4 || array.sizeOf != sizeof(int) ||
        ((int*) array.base)[0] != 0 ||
        ((int*) array.base)[1] != 1 ||
        ((int*) array.base)[2] != 2 ||
        ((int*) array.base)[3] != 4) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int LengthZero() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 0);
    if(cds_ArrayLength(&array) != 0) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int LengthNonZero() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    if(cds_ArrayLength(&array) != 8) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int LengthResize() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    cds_ArrayResize(&array, 4);
    if(cds_ArrayLength(&array) != 4) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int At() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    *((int*) cds_ArrayAt(&array, 0)) = -8;
    *((int*) cds_ArrayAt(&array, 1)) = -7;
    *((int*) cds_ArrayAt(&array, 2)) = -6;
    *((int*) cds_ArrayAt(&array, 3)) = -5;
    *((int*) cds_ArrayAt(&array, 4)) = -4;
    *((int*) cds_ArrayAt(&array, 5)) = -3;
    *((int*) cds_ArrayAt(&array, 6)) = -2;
    *((int*) cds_ArrayAt(&array, 7)) = -1;
    if(*((int*) cds_ArrayAt(&array, 0)) != -8 ||
        *((int*) cds_ArrayAt(&array, 1)) != -7 ||
        *((int*) cds_ArrayAt(&array, 2)) != -6 ||
        *((int*) cds_ArrayAt(&array, 3)) != -5 ||
        *((int*) cds_ArrayAt(&array, 4)) != -4 ||
        *((int*) cds_ArrayAt(&array, 5)) != -3 ||
        *((int*) cds_ArrayAt(&array, 6)) != -2 ||
        *((int*) cds_ArrayAt(&array, 7)) != -1) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int intCompare(const void *left, const void *right) {
	return *((int*) left) - *((int*) right);
}

int FirstIndexNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 128;
    if(cds_ArrayFirstIndexOf(&array, 0, &value, intCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexStart() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 0;
    if(cds_ArrayFirstIndexOf(&array, 0, &value, intCompare) != 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexMiddle() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 4;
    if(cds_ArrayFirstIndexOf(&array, 0, &value, intCompare) != 3)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexEnd() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 64;
    if(cds_ArrayFirstIndexOf(&array, 0, &value, intCompare) != 7)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexOffsetNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 128;
    if(cds_ArrayFirstIndexOf(&array, 4, &value, intCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexOffsetStart() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 8;
    if(cds_ArrayFirstIndexOf(&array, 4, &value, intCompare) != 4)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexOffsetMiddle() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 32;
    if(cds_ArrayFirstIndexOf(&array, 4, &value, intCompare) != 6)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int FirstIndexOffsetEnd() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 64;
    if(cds_ArrayFirstIndexOf(&array, 4, &value, intCompare) != 7)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 128;
    if(cds_ArrayLastIndexOf(&array, 7, &value, intCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexStart() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 0;
    if(cds_ArrayLastIndexOf(&array, 7, &value, intCompare) != 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexMiddle() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 4;
    if(cds_ArrayLastIndexOf(&array, 7, &value, intCompare) != 3)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexEnd() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 64;
    if(cds_ArrayLastIndexOf(&array, 7, &value, intCompare) != 7)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexOffsetNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 128;
    if(cds_ArrayLastIndexOf(&array, 4, &value, intCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexOffsetStart() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 0;
    if(cds_ArrayLastIndexOf(&array, 4, &value, intCompare) != 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexOffsetMiddle() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 2;
    if(cds_ArrayLastIndexOf(&array, 4, &value, intCompare) != 2)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int LastIndexOffsetEnd() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 8;
    if(cds_ArrayLastIndexOf(&array, 4, &value, intCompare) != 4)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int main() {
    RunTests(32, (struct Test[32]) {
        (struct Test) {ConstructDestructLengthZero, "ConstructDestructLengthZero"},
        (struct Test) {ConstructDestructLengthNonZero, "ConstructDestructLengthNonZero"},
        (struct Test) {FromArrayToArrayAll, "FromArrayToArrayAll"},
        (struct Test) {FromArrayToArrayFirstHalf, "FromArrayToArrayFirstHalf"},
        (struct Test) {FromArrayToArraySecondHalf, "FromArrayToArraySecondHalf"},
        (struct Test) {FromArrayToArrayMiddle, "FromArrayToArrayMiddle"},
        (struct Test) {FromArrayToArrayNone, "FromArrayToArrayNone"},
        (struct Test) {ResizeFromZero, "ResizeFromZero"},
        (struct Test) {ResizeFromZero, "ResizeToZero"},
        (struct Test) {ResizeSameSize, "ResizeSameSize"},
        (struct Test) {ResizeSameSize, "ResizeBiggerSize"},
        (struct Test) {ResizeSameSize, "ResizeSmallerSize"},
        (struct Test) {LengthZero, "LengthZero"},
        (struct Test) {LengthNonZero, "LengthNonZero"},
        (struct Test) {LengthResize, "LengthResize"},
        (struct Test) {At, "At"},
        (struct Test) {FirstIndexNone, "FirstIndexNone"},
	(struct Test) {FirstIndexStart, "FirstIndexStart"},
	(struct Test) {FirstIndexMiddle, "FirstIndexMiddle"},
	(struct Test) {FirstIndexEnd, "FirstIndexEnd"},
	(struct Test) {FirstIndexOffsetNone, "FirstIndexOffsetNone"},
	(struct Test) {FirstIndexOffsetStart, "FirstIndexOffsetStart"},
	(struct Test) {FirstIndexOffsetMiddle, "FirstIndexOffsetMiddle"},
	(struct Test) {FirstIndexOffsetEnd, "FirstIndexOffsetEnd"},
        (struct Test) {LastIndexNone, "LastIndexNone"},
	(struct Test) {LastIndexStart, "LastIndexStart"},
	(struct Test) {LastIndexMiddle, "LastIndexMiddle"},
        (struct Test) {LastIndexEnd, "LastIndexEnd"},
	(struct Test) {LastIndexOffsetNone, "LastIndexOffsetNone"},
	(struct Test) {LastIndexOffsetStart, "LastIndexOffsetStart"},
	(struct Test) {LastIndexOffsetMiddle, "LastIndexOffsetMiddle"},
	(struct Test) {LastIndexOffsetEnd, "LastIndexOffsetEnd"}
    });
    return 0;
}
