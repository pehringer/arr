#include "Test.h"
#include "cds_Array.h"

int ConstructDestructLengthZero() {
    int failed = 0;
    struct cds_Array array;
    if(cds_ArrayConstruct(&array, sizeof(int), 0) == 0 ||
        array.length != 0 || array.size != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    if(array.first != 0 ||
        array.length != 0 ||
        array.size != 0) {
        failed++;
    }
    return failed;
}

int ConstructDestructLengthNonZero() {
    int failed = 0;
    struct cds_Array array;
    if(cds_ArrayConstruct(&array, sizeof(int), 8) == 0 ||
        array.length != 8 || array.size != sizeof(int)) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    if(array.first != 0 ||
        array.length != 0 ||
        array.size != 0) {
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
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || oldArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || oldArray[1] != 1 ||
        ((int*) array.first)[2] != 2 || oldArray[2] != 2 ||
        ((int*) array.first)[3] != 4 || oldArray[3] != 4 ||
        ((int*) array.first)[4] != 8 || oldArray[4] != 8 ||
        ((int*) array.first)[5] != 16 || oldArray[5] != 16 ||
        ((int*) array.first)[6] != 32 || oldArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || oldArray[7] != 64) {
        failed++;
    }
    int newArray[8];
    cds_ArrayToArray(&array, 0, newArray, 8);
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || newArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || newArray[1] != 1 ||
        ((int*) array.first)[2] != 2 || newArray[2] != 2 ||
        ((int*) array.first)[3] != 4 || newArray[3] != 4 ||
        ((int*) array.first)[4] != 8 || newArray[4] != 8 ||
        ((int*) array.first)[5] != 16 || newArray[5] != 16 ||
        ((int*) array.first)[6] != 32 || newArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || newArray[7] != 64) {
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
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != -8 || oldArray[0] != -8 ||
        ((int*) array.first)[1] != -4 || oldArray[1] != -4 ||
        ((int*) array.first)[2] != -2 || oldArray[2] != -2 ||
        ((int*) array.first)[3] != -1 || oldArray[3] != -1 ||
        ((int*) array.first)[4] != 8 || initArray[4] != 8 ||
        ((int*) array.first)[5] != 16 || initArray[5] != 16 ||
        ((int*) array.first)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 0, newArray, 4);
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != -8 || newArray[0] != -8 ||
        ((int*) array.first)[1] != -4 || newArray[1] != -4 ||
        ((int*) array.first)[2] != -2 || newArray[2] != -2 ||
        ((int*) array.first)[3] != -1 || newArray[3] != -1 ||
        ((int*) array.first)[4] != 8 || initArray[4] != 8 ||
        ((int*) array.first)[5] != 16 || initArray[5] != 16 ||
        ((int*) array.first)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || initArray[7] != 64) {
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
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.first)[2] != 2 || initArray[2] != 2 ||
        ((int*) array.first)[3] != 4 || initArray[3] != 4 ||
        ((int*) array.first)[4] != -8 || oldArray[0] != -8 ||
        ((int*) array.first)[5] != -4 || oldArray[1] != -4 ||
        ((int*) array.first)[6] != -2 || oldArray[2] != -2 ||
        ((int*) array.first)[7] != -1 || oldArray[3] != -1) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 4, newArray, 4);
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.first)[2] != 2 || initArray[2] != 2 ||
        ((int*) array.first)[3] != 4 || initArray[3] != 4 ||
        ((int*) array.first)[4] != -8 || newArray[0] != -8 ||
        ((int*) array.first)[5] != -4 || newArray[1] != -4 ||
        ((int*) array.first)[6] != -2 || newArray[2] != -2 ||
        ((int*) array.first)[7] != -1 || newArray[3] != -1) {
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
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.first)[2] != -8 || oldArray[0] != -8 ||
        ((int*) array.first)[3] != -4 || oldArray[1] != -4 ||
        ((int*) array.first)[4] != -2 || oldArray[2] != -2 ||
        ((int*) array.first)[5] != -1 || oldArray[3] != -1 ||
        ((int*) array.first)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || initArray[7] != 64) {
        failed++;
    }
    int newArray[4];
    cds_ArrayToArray(&array, 2, newArray, 4);
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 || initArray[0] != 0 ||
        ((int*) array.first)[1] != 1 || initArray[1] != 1 ||
        ((int*) array.first)[2] != -8 || newArray[0] != -8 ||
        ((int*) array.first)[3] != -4 || newArray[1] != -4 ||
        ((int*) array.first)[4] != -2 || newArray[2] != -2 ||
        ((int*) array.first)[5] != -1 || newArray[3] != -1 ||
        ((int*) array.first)[6] != 32 || initArray[6] != 32 ||
        ((int*) array.first)[7] != 64 || initArray[7] != 64) {
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
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 || oldArray[0] != 1 ||
        ((int*) array.first)[3] != 4 || oldArray[1] != 1 ||
        ((int*) array.first)[4] != 8 || oldArray[2] != 1 ||
        ((int*) array.first)[5] != 16 || oldArray[3] != 1 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
        failed++;
    }
    int newArray[4] = {0, 0, 0, 0};
    cds_ArrayToArray(&array, 2, newArray, 0);
    if(array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 || newArray[0] != 0 ||
        ((int*) array.first)[3] != 4 || newArray[1] != 0 ||
        ((int*) array.first)[4] != 8 || newArray[2] != 0 ||
        ((int*) array.first)[5] != 16 || newArray[3] != 0 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
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
        array.length != 8 || array.size != sizeof(int)) {
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
        array.length != 0 || array.size != sizeof(int)) {
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
        array.length != 8 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 ||
        ((int*) array.first)[3] != 4 ||
        ((int*) array.first)[4] != 8 ||
        ((int*) array.first)[5] != 16 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
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
        array.length != 16 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 ||
        ((int*) array.first)[3] != 4 ||
        ((int*) array.first)[4] != 8 ||
        ((int*) array.first)[5] != 16 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
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
        array.length != 4 || array.size != sizeof(int) ||
        ((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 ||
        ((int*) array.first)[3] != 4) {
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

int helperCompare(const void *left, const void *right) {
	return *((int*) left) - *((int*) right);
}

int FirstIndexNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArrayConstruct(&array, sizeof(int), 8);
    int initArray[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    cds_ArrayFromArray(&array, 0, initArray, 8);
    int value = 128;
    if(cds_ArrayFirstIndexOf(&array, 0, &value, helperCompare) != -1)
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
    if(cds_ArrayFirstIndexOf(&array, 0, &value, helperCompare) != 0)
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
    if(cds_ArrayFirstIndexOf(&array, 0, &value, helperCompare) != 3)
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
    if(cds_ArrayFirstIndexOf(&array, 0, &value, helperCompare) != 7)
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
    if(cds_ArrayFirstIndexOf(&array, 4, &value, helperCompare) != -1)
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
    if(cds_ArrayFirstIndexOf(&array, 4, &value, helperCompare) != 4)
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
    if(cds_ArrayFirstIndexOf(&array, 4, &value, helperCompare) != 6)
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
    if(cds_ArrayFirstIndexOf(&array, 4, &value, helperCompare) != 7)
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
    if(cds_ArrayLastIndexOf(&array, 7, &value, helperCompare) != -1)
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
    if(cds_ArrayLastIndexOf(&array, 7, &value, helperCompare) != 0)
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
    if(cds_ArrayLastIndexOf(&array, 7, &value, helperCompare) != 3)
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
    if(cds_ArrayLastIndexOf(&array, 7, &value, helperCompare) != 7)
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
    if(cds_ArrayLastIndexOf(&array, 4, &value, helperCompare) != -1)
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
    if(cds_ArrayLastIndexOf(&array, 4, &value, helperCompare) != 0)
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
    if(cds_ArrayLastIndexOf(&array, 4, &value, helperCompare) != 2)
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
    if(cds_ArrayLastIndexOf(&array, 4, &value, helperCompare) != 4)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int helperSorted(const int *array, int length) {
    for(int index = 1; index < length; index++)
        if(array[index - 1] > array[index])
            return 0;
    return 1;
}

int SortNone() {
    int failed = 0;
    struct cds_Array array;
    cds_ArraySort(cds_ArrayConstruct(&array, sizeof(int), 0), helperCompare);
    if(helperSorted(array.first, array.length) == 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SortOne() {
    int failed = 0;
    struct cds_Array array;
    *((int*) cds_ArrayAt(cds_ArrayConstruct(&array, sizeof(int), 1), 0)) = 1;
    if(helperSorted(cds_ArraySort(&array, helperCompare)->first, array.length) == 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SortManySame() {
    int failed = 0;
    int from[8] = {42, 42, 42, 42, 42, 42, 42, 42};
    struct cds_Array array;
    cds_ArraySort(cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8), helperCompare);
    if(helperSorted(array.first, array.length) == 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SortManySorted() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    cds_ArraySort(cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8), helperCompare);
    if(helperSorted(array.first, array.length) == 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SortManyUnsorted() {
    int failed = 0;
    int from[8] = {8, -2, 9, 23, -128, 83, 1, 0};
    struct cds_Array array;
    cds_ArraySort(cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8), helperCompare);
    if(helperSorted(array.first, array.length) == 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchNone() {
    int failed = 0;
    struct cds_Array array;
    int value = 0;
    if(cds_ArrayBinarySearch(cds_ArrayConstruct(&array, sizeof(int), 0), &value, helperCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchOne() {
    int failed = 0;
    struct cds_Array array;
    *((int*) cds_ArrayAt(cds_ArrayConstruct(&array, sizeof(int), 1), 0)) = 42;
    int value = 42;
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchOneNot() {
    int failed = 0;
    struct cds_Array array;
    *((int*) cds_ArrayAt(cds_ArrayConstruct(&array, sizeof(int), 1), 0)) = 42;
    int value = 21;
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchManyNot() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != -1)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchManyStart() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 0;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != 0)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchManyMiddle() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 8;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != 4)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}

int SearchManyEnd() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 64;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    if(cds_ArrayBinarySearch(&array, &value, helperCompare) != 7)
        failed++;
    cds_ArrayDestruct(&array);
    return failed;
}










int FillNone() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    cds_ArrayFill(&array, 0, &value, 0);
    if(((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 ||
        ((int*) array.first)[3] != 4 ||
        ((int*) array.first)[4] != 8 ||
        ((int*) array.first)[5] != 16 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FillAll() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    cds_ArrayFill(&array, 0, &value, cds_ArrayLength(&array));
    if(((int*) array.first)[0] != 42 ||
        ((int*) array.first)[1] != 42 ||
        ((int*) array.first)[2] != 42 ||
        ((int*) array.first)[3] != 42 ||
        ((int*) array.first)[4] != 42 ||
        ((int*) array.first)[5] != 42 ||
        ((int*) array.first)[6] != 42 ||
        ((int*) array.first)[7] != 42) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FillFirstHalf() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    cds_ArrayFill(&array, 0, &value, 4);
    if(((int*) array.first)[0] != 42 ||
        ((int*) array.first)[1] != 42 ||
        ((int*) array.first)[2] != 42 ||
        ((int*) array.first)[3] != 42 ||
        ((int*) array.first)[4] != 8 ||
        ((int*) array.first)[5] != 16 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FillMiddle() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    cds_ArrayFill(&array, 2, &value, 4);
    if(((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 42 ||
        ((int*) array.first)[3] != 42 ||
        ((int*) array.first)[4] != 42 ||
        ((int*) array.first)[5] != 42 ||
        ((int*) array.first)[6] != 32 ||
        ((int*) array.first)[7] != 64) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int FillSecondHalf() {
    int failed = 0;
    int from[8] = {0, 1, 2, 4, 8, 16, 32, 64};
    struct cds_Array array;
    int value = 42;
    cds_ArrayFromArray(cds_ArrayConstruct(&array, sizeof(int), 8), 0, from, 8);
    cds_ArrayFill(&array, 4, &value, 4);
    if(((int*) array.first)[0] != 0 ||
        ((int*) array.first)[1] != 1 ||
        ((int*) array.first)[2] != 2 ||
        ((int*) array.first)[3] != 4 ||
        ((int*) array.first)[4] != 42 ||
        ((int*) array.first)[5] != 42 ||
        ((int*) array.first)[6] != 42 ||
        ((int*) array.first)[7] != 42) {
        failed++;
    }
    cds_ArrayDestruct(&array);
    return failed;
}

int main() {
    RunTests(49, (struct Test[49]) {
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
        (struct Test) {LastIndexOffsetEnd, "LastIndexOffsetEnd"},
        (struct Test) {SortNone, "SortNone"},
        (struct Test) {SortOne, "SortOne"},
        (struct Test) {SortManySame, "SortManySame"},
        (struct Test) {SortManySorted, "SortManySorted"},
        (struct Test) {SortManyUnsorted, "SortManyUnsorted"},
        (struct Test) {SearchNone, "SearchNone"},
        (struct Test) {SearchOne, "SearchOne"},
        (struct Test) {SearchOneNot, "SearchOneNot"},
        (struct Test) {SearchManyNot, "SearchManyNot"},
        (struct Test) {SearchManyStart, "SearchManyStart"},
        (struct Test) {SearchManyMiddle, "SearchManyMiddle"},
        (struct Test) {SearchManyEnd, "SearchManyEnd"},
        (struct Test) {FillNone, "FillNone"},
        (struct Test) {FillAll, "FillAll"},
        (struct Test) {FillFirstHalf, "FillFirstHalf"},
        (struct Test) {FillMiddle, "FillMiddle"},
        (struct Test) {FillSecondHalf, "FillSecondHalf"},
    });
    return 0;
}
