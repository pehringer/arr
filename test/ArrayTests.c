#include "Test.h"
#include "DS_Array.h"


int IntCmp(const void *l, const void *r) {
    return *((int*) l) - *((int*) r);
}

int Init(void) {
    int failed = 0;
    int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    if(test.array != arr) failed++;
    if(test.compare != IntCmp) failed++;
    if(test.size != sizeof(int)) failed++;
    return failed;
}

int Fill(void) {
    int failed = 0;
    int srcVal = 0;
    int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    srcVal = 128;
    DS_ArrayFill(test, 0, 4, &srcVal);
    if(arr[0] != 128) failed++;
    if(arr[1] != 128) failed++;
    if(arr[2] != 128) failed++;
    if(arr[3] != 128) failed++;
    if(arr[4] != 1) failed++;
    if(arr[5] != 64) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 0) failed++;
    srcVal = 256;
    DS_ArrayFill(test, 4, 8, &srcVal);
    if(arr[0] != 128) failed++;
    if(arr[1] != 128) failed++;
    if(arr[2] != 128) failed++;
    if(arr[3] != 128) failed++;
    if(arr[4] != 256) failed++;
    if(arr[5] != 256) failed++;
    if(arr[6] != 256) failed++;
    if(arr[7] != 256) failed++;
    srcVal = 512;
    DS_ArrayFill(test, 2, 6, &srcVal);
    if(arr[0] != 128) failed++;
    if(arr[1] != 128) failed++;
    if(arr[2] != 512) failed++;
    if(arr[3] != 512) failed++;
    if(arr[4] != 512) failed++;
    if(arr[5] != 512) failed++;
    if(arr[6] != 256) failed++;
    if(arr[7] != 256) failed++;
    srcVal = 1024;
    DS_ArrayFill(test, 0, 8, &srcVal);
    if(arr[0] != 1024) failed++;
    if(arr[1] != 1024) failed++;
    if(arr[2] != 1024) failed++;
    if(arr[3] != 1024) failed++;
    if(arr[4] != 1024) failed++;
    if(arr[5] != 1024) failed++;
    if(arr[6] != 1024) failed++;
    if(arr[7] != 1024) failed++;
    return failed;
}

int Set(void) {
   int failed = 0;
   int srcArr[8] = {-8, -7, -6, -5, -4, -3, -2, -1};
   int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
   struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
   DS_ArraySet(test, 0, 1, srcArr + 0);
   if(arr[0] != -8) failed++;
   if(arr[1] != 4) failed++;
   if(arr[2] != 2) failed++;
   if(arr[3] != 16) failed++;
   if(arr[4] != 1) failed++;
   if(arr[5] != 64) failed++;
   if(arr[6] != 32) failed++;
   if(arr[7] != 0) failed++;
   DS_ArraySet(test, 7, 8, srcArr + 1);
   if(arr[0] != -8) failed++;
   if(arr[1] != 4) failed++;
   if(arr[2] != 2) failed++;
   if(arr[3] != 16) failed++;
   if(arr[4] != 1) failed++;
   if(arr[5] != 64) failed++;
   if(arr[6] != 32) failed++;
   if(arr[7] != -7) failed++;
   DS_ArraySet(test, 0, 4, srcArr + 4);
   if(arr[0] != -4) failed++;
   if(arr[1] != -3) failed++;
   if(arr[2] != -2) failed++;
   if(arr[3] != -1) failed++;
   if(arr[4] != 1) failed++;
   if(arr[5] != 64) failed++;
   if(arr[6] != 32) failed++;
   if(arr[7] != -7) failed++;
   DS_ArraySet(test, 4, 8, srcArr);
   if(arr[0] != -4) failed++;
   if(arr[1] != -3) failed++;
   if(arr[2] != -2) failed++;
   if(arr[3] != -1) failed++;
   if(arr[4] != -8) failed++;
   if(arr[5] != -7) failed++;
   if(arr[6] != -6) failed++;
   if(arr[7] != -5) failed++;
   DS_ArraySet(test, 2, 6, srcArr + 2);
   if(arr[0] != -4) failed++;
   if(arr[1] != -3) failed++;
   if(arr[2] != -6) failed++;
   if(arr[3] != -5) failed++;
   if(arr[4] != -4) failed++;
   if(arr[5] != -3) failed++;
   if(arr[6] != -6) failed++;
   if(arr[7] != -5) failed++;
   DS_ArraySet(test, 0, 8, srcArr);
   if(arr[0] != -8) failed++;
   if(arr[1] != -7) failed++;
   if(arr[2] != -6) failed++;
   if(arr[3] != -5) failed++;
   if(arr[4] != -4) failed++;
   if(arr[5] != -3) failed++;
   if(arr[6] != -2) failed++;
   if(arr[7] != -1) failed++;
   return failed;
}

int Get(void) {
   int failed = 0;
   int dstArr[8] = {-8, -7, -6, -5, -4, -3, -2, -1};
   int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
   struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
   DS_ArrayGet(test, 0, 1, dstArr + 0);
   if(dstArr[0] != 8) failed++;
   if(dstArr[1] != -7) failed++;
   if(dstArr[2] != -6) failed++;
   if(dstArr[3] != -5) failed++;
   if(dstArr[4] != -4) failed++;
   if(dstArr[5] != -3) failed++;
   if(dstArr[6] != -2) failed++;
   if(dstArr[7] != -1) failed++;
   DS_ArrayGet(test, 1, 2, dstArr + 7);
   if(dstArr[0] != 8) failed++;
   if(dstArr[1] != -7) failed++;
   if(dstArr[2] != -6) failed++;
   if(dstArr[3] != -5) failed++;
   if(dstArr[4] != -4) failed++;
   if(dstArr[5] != -3) failed++;
   if(dstArr[6] != -2) failed++;
   if(dstArr[7] != 4) failed++;
   DS_ArrayGet(test, 0, 4, dstArr + 4);
   if(dstArr[0] != 8) failed++;
   if(dstArr[1] != -7) failed++;
   if(dstArr[2] != -6) failed++;
   if(dstArr[3] != -5) failed++;
   if(dstArr[4] != 8) failed++;
   if(dstArr[5] != 4) failed++;
   if(dstArr[6] != 2) failed++;
   if(dstArr[7] != 16) failed++;
   DS_ArrayGet(test, 4, 8, dstArr);
   if(dstArr[0] != 1) failed++;
   if(dstArr[1] != 64) failed++;
   if(dstArr[2] != 32) failed++;
   if(dstArr[3] != 0) failed++;
   if(dstArr[4] != 8) failed++;
   if(dstArr[5] != 4) failed++;
   if(dstArr[6] != 2) failed++;
   if(dstArr[7] != 16) failed++;
   DS_ArrayGet(test, 2, 6, dstArr + 2);
   if(dstArr[0] != 1) failed++;
   if(dstArr[1] != 64) failed++;
   if(dstArr[2] != 2) failed++;
   if(dstArr[3] != 16) failed++;
   if(dstArr[4] != 1) failed++;
   if(dstArr[5] != 64) failed++;
   if(dstArr[6] != 2) failed++;
   if(dstArr[7] != 16) failed++;
   DS_ArrayGet(test, 0, 8, dstArr);
   if(dstArr[0] != 8) failed++;
   if(dstArr[1] != 4) failed++;
   if(dstArr[2] != 2) failed++;
   if(dstArr[3] != 16) failed++;
   if(dstArr[4] != 1) failed++;
   if(dstArr[5] != 64) failed++;
   if(dstArr[6] != 32) failed++;
   if(dstArr[7] != 0) failed++;
   return failed;
}

int Count(void) {
    int failed = 0;
    int tarVal = 0;
    int arr[8] = {1, 2, 2, 3, 3, 3, 4, 4};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    tarVal = 0;
    if(DS_ArrayCount(test, 0, 1, &tarVal) != 0) failed++;
    tarVal = 1;
    if(DS_ArrayCount(test, 0, 1, &tarVal) != 1) failed++;
    tarVal = 0;
    if(DS_ArrayCount(test, 0, 4, &tarVal) != 0) failed++;
    tarVal = 1;
    if(DS_ArrayCount(test, 0, 4, &tarVal) != 1) failed++;
    tarVal = 2;
    if(DS_ArrayCount(test, 0, 4, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayCount(test, 0, 4, &tarVal) != 1) failed++;
    tarVal = 4;
    if(DS_ArrayCount(test, 0, 4, &tarVal) != 0) failed++;
    tarVal = 0;
    if(DS_ArrayCount(test, 4, 8, &tarVal) != 0) failed++;
    tarVal = 1;
    if(DS_ArrayCount(test, 4, 8, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayCount(test, 4, 8, &tarVal) != 0) failed++;
    tarVal = 3;
    if(DS_ArrayCount(test, 4, 8, &tarVal) != 2) failed++;
    tarVal = 4;
    if(DS_ArrayCount(test, 4, 8, &tarVal) != 2) failed++;
    tarVal = 0;
    if(DS_ArrayCount(test, 2, 6, &tarVal) != 0) failed++;
    tarVal = 1;
    if(DS_ArrayCount(test, 2, 6, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayCount(test, 2, 6, &tarVal) != 1) failed++;
    tarVal = 3;
    if(DS_ArrayCount(test, 2, 6, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayCount(test, 2, 6, &tarVal) != 0) failed++;
    tarVal = 0;
    if(DS_ArrayCount(test, 0, 8, &tarVal) != 0) failed++;
    tarVal = 1;
    if(DS_ArrayCount(test, 0, 8, &tarVal) != 1) failed++;
    tarVal = 2;
    if(DS_ArrayCount(test, 0, 8, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayCount(test, 0, 8, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayCount(test, 0, 8, &tarVal) != 2) failed++;
    return failed;
}

int First(void) {
    int failed = 0;
    int tarVal = 0;
    int arr[8] = {1, 2, 2, 3, 3, 3, 4, 4};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    tarVal = 0;
    if(DS_ArrayFirst(test, 0, 1, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayFirst(test, 0, 0, &tarVal) != -1) failed++;
    if(DS_ArrayFirst(test, 0, 1, &tarVal) != 0) failed++;
    tarVal = 0;
    if(DS_ArrayFirst(test, 0, 4, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayFirst(test, 0, 4, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayFirst(test, 0, 4, &tarVal) != 1) failed++;
    tarVal = 3;
    if(DS_ArrayFirst(test, 0, 4, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayFirst(test, 0, 4, &tarVal) != -1) failed++;
    tarVal = 0;
    if(DS_ArrayFirst(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayFirst(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 2;
    if(DS_ArrayFirst(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 3;
    if(DS_ArrayFirst(test, 4, 8, &tarVal) != 4) failed++;
    tarVal = 4;
    if(DS_ArrayFirst(test, 4, 8, &tarVal) != 6) failed++;
    tarVal = 0;
    if(DS_ArrayFirst(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayFirst(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 2;
    if(DS_ArrayFirst(test, 2, 6, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayFirst(test, 2, 6, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayFirst(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 0;
    if(DS_ArrayFirst(test, 0, 8, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayFirst(test, 0, 8, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayFirst(test, 0, 8, &tarVal) != 1) failed++;
    tarVal = 3;
    if(DS_ArrayFirst(test, 0, 8, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayFirst(test, 0, 8, &tarVal) != 6) failed++;
    return failed;
}

int Last(void) {
    int failed = 0;
    int tarVal = 0;
    int arr[8] = {1, 2, 2, 3, 3, 3, 4, 4};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    tarVal = 0;
    if(DS_ArrayLast(test, 0, 1, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayLast(test, 0, 0, &tarVal) != -1) failed++;
    if(DS_ArrayLast(test, 0, 1, &tarVal) != 0) failed++;
    tarVal = 0;
    if(DS_ArrayLast(test, 0, 4, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayLast(test, 0, 4, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayLast(test, 0, 4, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayLast(test, 0, 4, &tarVal) != 3) failed++;
    tarVal = 4;
    if(DS_ArrayLast(test, 0, 4, &tarVal) != -1) failed++;
    tarVal = 0;
    if(DS_ArrayLast(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayLast(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 2;
    if(DS_ArrayLast(test, 4, 8, &tarVal) != -1) failed++;
    tarVal = 3;
    if(DS_ArrayLast(test, 4, 8, &tarVal) != 5) failed++;
    tarVal = 4;
    if(DS_ArrayLast(test, 4, 8, &tarVal) != 7) failed++;
    tarVal = 0;
    if(DS_ArrayLast(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayLast(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 2;
    if(DS_ArrayLast(test, 2, 6, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayLast(test, 2, 6, &tarVal) != 5) failed++;
    tarVal = 4;
    if(DS_ArrayLast(test, 2, 6, &tarVal) != -1) failed++;
    tarVal = 0;
    if(DS_ArrayLast(test, 0, 8, &tarVal) != -1) failed++;
    tarVal = 1;
    if(DS_ArrayLast(test, 0, 8, &tarVal) != 0) failed++;
    tarVal = 2;
    if(DS_ArrayLast(test, 0, 8, &tarVal) != 2) failed++;
    tarVal = 3;
    if(DS_ArrayLast(test, 0, 8, &tarVal) != 5) failed++;
    tarVal = 4;
    if(DS_ArrayLast(test, 0, 8, &tarVal) != 7) failed++;
    return failed;
}

int Max(void) {
    int failed = 0;
    int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    if(DS_ArrayMax(test, 0, 0) != -1) failed++;
    if(DS_ArrayMax(test, 0, 1) != 0) failed++;
    if(DS_ArrayMax(test, 0, 2) != 0) failed++;
    if(DS_ArrayMax(test, 0, 3) != 0) failed++;
    if(DS_ArrayMax(test, 0, 4) != 3) failed++;
    if(DS_ArrayMax(test, 2, 6) != 5) failed++;
    if(DS_ArrayMax(test, 4, 8) != 5) failed++;
    if(DS_ArrayMax(test, 0, 8) != 5) failed++;
    return failed++;
}

int Min(void) {
    int failed = 0;
    int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    if(DS_ArrayMin(test, 0, 0) != -1) failed++;
    if(DS_ArrayMin(test, 0, 1) != 0) failed++;
    if(DS_ArrayMin(test, 0, 2) != 1) failed++;
    if(DS_ArrayMin(test, 0, 3) != 2) failed++;
    if(DS_ArrayMin(test, 0, 4) != 2) failed++;
    if(DS_ArrayMin(test, 2, 6) != 4) failed++;
    if(DS_ArrayMin(test, 4, 8) != 7) failed++;
    if(DS_ArrayMin(test, 0, 8) != 7) failed++;
    return failed++;
}

int Sort(void) {
    int failed = 0;
    int arr[8] = {8, 4, 2, 16, 1, 64, 32, 0};
    struct DS_Array test = DS_ArrayInit(arr, IntCmp, sizeof(int));
    DS_ArraySort(test, 0, 0);
    if(arr[0] != 8) failed++;
    if(arr[1] != 4) failed++;
    if(arr[2] != 2) failed++;
    if(arr[3] != 16) failed++;
    if(arr[4] != 1) failed++;
    if(arr[5] != 64) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 0) failed++;
    DS_ArraySort(test, 2, 6);
    if(arr[0] != 8) failed++;
    if(arr[1] != 4) failed++;
    if(arr[2] != 1) failed++;
    if(arr[3] != 2) failed++;
    if(arr[4] != 16) failed++;
    if(arr[5] != 64) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 0) failed++;
    DS_ArraySort(test, 0, 4);
    if(arr[0] != 1) failed++;
    if(arr[1] != 2) failed++;
    if(arr[2] != 4) failed++;
    if(arr[3] != 8) failed++;
    if(arr[4] != 16) failed++;
    if(arr[5] != 64) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 0) failed++;
    if(arr[7] != 0) failed++;
    DS_ArraySort(test, 4, 8);
    if(arr[0] != 1) failed++;
    if(arr[1] != 2) failed++;
    if(arr[2] != 4) failed++;
    if(arr[3] != 8) failed++;
    if(arr[4] != 0) failed++;
    if(arr[5] != 16) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 64) failed++;
    DS_ArraySort(test, 0, 8);
    if(arr[0] != 0) failed++;
    if(arr[1] != 1) failed++;
    if(arr[2] != 2) failed++;
    if(arr[3] != 4) failed++;
    if(arr[4] != 8) failed++;
    if(arr[5] != 16) failed++;
    if(arr[6] != 32) failed++;
    if(arr[7] != 64) failed++;
    return failed;
}

int main() {
    RunTests(10, (struct Test[10]) {
        (struct Test) {Init, "Init"},
        (struct Test) {Fill, "Fill"},
        (struct Test) {Set, "Set"},
        (struct Test) {Get, "Get"},
        (struct Test) {Count, "Count"},
        (struct Test) {First, "First"},
        (struct Test) {Last, "Last"},
        (struct Test) {Max, "Max"},
        (struct Test) {Min, "Min"},
        (struct Test) {Sort, "Sort"},
    });
    return 0;
}
