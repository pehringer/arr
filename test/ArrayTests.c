#include "Test.h"
#include "DS_Array.h"


int IntCmp(const void *l, const void *r) {
    return *((int*) l) - *((int*) r);
}

int NewDeleteLength(void) {
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 0, IntCmp);
    if(test == 0) failed++;
    if(DS_ArrayLength(test) != 0) failed++;
    DS_ArrayDelete(test);
    test = DS_ArrayNew(sizeof(int), 4, IntCmp);
    if(test == 0) failed++;
    if(DS_ArrayLength(test) != 4) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int ResizeAt(void) {
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 0, IntCmp);
    test = DS_ArrayResize(test, 4);
    if(test == 0) failed++;
    *((int*) DS_ArrayAt(test, 0)) = 3;
    *((int*) DS_ArrayAt(test, 1)) = 2;
    *((int*) DS_ArrayAt(test, 2)) = 1;
    *((int*) DS_ArrayAt(test, 3)) = 0;
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 0) failed++;
    if(DS_ArrayLength(test) != 4) failed++;
    test = DS_ArrayResize(test, 8);
    if(test == 0) failed++;
    *((int*) DS_ArrayAt(test, 4)) = 7;
    *((int*) DS_ArrayAt(test, 5)) = 6;
    *((int*) DS_ArrayAt(test, 6)) = 5;
    *((int*) DS_ArrayAt(test, 7)) = 4;
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 0) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 4) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    test = DS_ArrayResize(test, 4);
    if(test == 0) failed++;
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 0) failed++;
    if(DS_ArrayLength(test) != 4) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Get(void) {
    int value = -1;
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 4, IntCmp);
    *((int*) DS_ArrayAt(test, 0)) = 3;
    *((int*) DS_ArrayAt(test, 1)) = 2;
    *((int*) DS_ArrayAt(test, 2)) = 1;
    *((int*) DS_ArrayAt(test, 3)) = 0;
    DS_ArrayGet(test, 0, &value);
    if(value != 3) failed++;
    DS_ArrayGet(test, 1, &value);
    if(value != 2) failed++;
    DS_ArrayGet(test, 2, &value);
    if(value != 1) failed++;
    DS_ArrayGet(test, 3, &value);
    if(value != 0) failed++;
    if(DS_ArrayLength(test) != 4) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Set(void) {
    int value = -1;
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 4, IntCmp);
    value = 3;
    DS_ArrayGet(test, 0, &value);
    value = 2;
    DS_ArrayGet(test, 1, &value);
    value = 1;
    DS_ArrayGet(test, 2, &value);
    value = 0;
    DS_ArrayGet(test, 3, &value);
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 0) failed++;
    if(DS_ArrayLength(test) != 4) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Copy(void) {
    int array[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 4, 8, array);
    DS_ArrayCopy(test, 0, 4, array + 4);
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 0) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 4) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayCopy(test, 2, 6, array);
    if(*((int*) DS_ArrayAt(test, 0)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 4) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 4) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Fill(void) {
    int value = 0;
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    value = 5;
    DS_ArrayFill(test, 4, 8, &value);
    value = 6;
    DS_ArrayFill(test, 0, 4, &value);
    if(*((int*) DS_ArrayAt(test, 0)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 5) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    value = 7;
    DS_ArrayFill(test, 2, 6, &value);
    if(*((int*) DS_ArrayAt(test, 0)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 5) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Max(void) {
    int array[8] = {2, 4, 3, 1, 0, 5, 7, 6};
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 0, 8, array);
    if(DS_ArrayMax(test, 0, 0) != -1) failed++;
    if(DS_ArrayMax(test, 0, 1) != 0) failed++;
    if(DS_ArrayMax(test, 0, 2) != 1) failed++;
    if(DS_ArrayMax(test, 0, 3) != 1) failed++;
    if(DS_ArrayMax(test, 0, 4) != 1) failed++;
    if(DS_ArrayMax(test, 1, 5) != 1) failed++;
    if(DS_ArrayMax(test, 2, 6) != 5) failed++;
    if(DS_ArrayMax(test, 3, 7) != 6) failed++;
    if(DS_ArrayMax(test, 4, 8) != 6) failed++;
    if(DS_ArrayMax(test, 5, 8) != 6) failed++;
    if(DS_ArrayMax(test, 6, 8) != 6) failed++;
    if(DS_ArrayMax(test, 7, 8) != 7) failed++;
    if(DS_ArrayMax(test, 8, 8) != -1) failed++;
    if(DS_ArrayMax(test, 0, 8) != 6) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Min(void) {
    int array[8] = {2, 4, 3, 1, 0, 5, 7, 6};
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 0, 8, array);
    if(DS_ArrayMin(test, 0, 0) != -1) failed++;
    if(DS_ArrayMin(test, 0, 1) != 0) failed++;
    if(DS_ArrayMin(test, 0, 2) != 0) failed++;
    if(DS_ArrayMin(test, 0, 3) != 0) failed++;
    if(DS_ArrayMin(test, 0, 4) != 3) failed++;
    if(DS_ArrayMin(test, 1, 5) != 4) failed++;
    if(DS_ArrayMin(test, 2, 6) != 4) failed++;
    if(DS_ArrayMin(test, 3, 7) != 4) failed++;
    if(DS_ArrayMin(test, 4, 8) != 4) failed++;
    if(DS_ArrayMin(test, 5, 8) != 5) failed++;
    if(DS_ArrayMin(test, 6, 8) != 7) failed++;
    if(DS_ArrayMin(test, 7, 8) != 7) failed++;
    if(DS_ArrayMin(test, 8, 8) != -1) failed++;
    if(DS_ArrayMin(test, 0, 8) != 4) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Count(void) {
    int array[8] = {1, 2, 0, 0, 2, 1, 0, 1};
    int target = -1;
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 0, 8, array);
    target = 0;
    if(DS_ArrayCount(test, 0, 4, &target) != 2) failed++;
    if(DS_ArrayCount(test, 4, 8, &target) != 1) failed++;
    if(DS_ArrayCount(test, 2, 6, &target) != 2) failed++;
    if(DS_ArrayCount(test, 0, 8, &target) != 3) failed++;
    target = 1;
    if(DS_ArrayCount(test, 0, 4, &target) != 1) failed++;
    if(DS_ArrayCount(test, 4, 8, &target) != 2) failed++;
    if(DS_ArrayCount(test, 2, 6, &target) != 1) failed++;
    if(DS_ArrayCount(test, 0, 8, &target) != 3) failed++;
    target = 2;
    if(DS_ArrayCount(test, 0, 4, &target) != 1) failed++;
    if(DS_ArrayCount(test, 4, 8, &target) != 1) failed++;
    if(DS_ArrayCount(test, 2, 6, &target) != 1) failed++;
    if(DS_ArrayCount(test, 0, 8, &target) != 2) failed++;
    target = 3;
    if(DS_ArrayCount(test, 0, 4, &target) != 0) failed++;
    if(DS_ArrayCount(test, 4, 8, &target) != 0) failed++;
    if(DS_ArrayCount(test, 2, 6, &target) != 0) failed++;
    if(DS_ArrayCount(test, 0, 8, &target) != 0) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Index(void) {
    int array[8] = {1, 2, 0, 0, 2, 1, 0, 1};
    int target = -1;
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 0, 8, array);
    target = 0;
    if(DS_ArrayIndex(test, 0, 4, &target) != 2) failed++;
    if(DS_ArrayIndex(test, 4, 8, &target) != 6) failed++;
    if(DS_ArrayIndex(test, 2, 6, &target) != 2) failed++;
    if(DS_ArrayIndex(test, 0, 8, &target) != 2) failed++;
    target = 1;
    if(DS_ArrayIndex(test, 0, 4, &target) != 0) failed++;
    if(DS_ArrayIndex(test, 4, 8, &target) != 5) failed++;
    if(DS_ArrayIndex(test, 2, 6, &target) != 5) failed++;
    if(DS_ArrayIndex(test, 0, 8, &target) != 0) failed++;
    target = 2;
    if(DS_ArrayIndex(test, 0, 4, &target) != 1) failed++;
    if(DS_ArrayIndex(test, 4, 8, &target) != 4) failed++;
    if(DS_ArrayIndex(test, 2, 6, &target) != 4) failed++;
    if(DS_ArrayIndex(test, 0, 8, &target) != 1) failed++;
    target = 3;
    if(DS_ArrayIndex(test, 0, 4, &target) != -1) failed++;
    if(DS_ArrayIndex(test, 4, 8, &target) != -1) failed++;
    if(DS_ArrayIndex(test, 2, 6, &target) != -1) failed++;
    if(DS_ArrayIndex(test, 0, 8, &target) != -1) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int Sort(void) {
   int array[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    int failed = 0;
    struct DS_Array *test = 0;
    test = DS_ArrayNew(sizeof(int), 8, IntCmp);
    DS_ArrayCopy(test, 0, 8, array);
    DS_ArraySort(test, 0, 4);
    if(*((int*) DS_ArrayAt(test, 0)) != 4) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 0) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArraySort(test, 4, 8);
    if(*((int*) DS_ArrayAt(test, 0)) != 4) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 0) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 3) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArraySort(test, 2, 6);
    if(*((int*) DS_ArrayAt(test, 0)) != 4) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 0) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 7) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 3) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArraySort(test, 0, 8);
    if(*((int*) DS_ArrayAt(test, 0)) != 0) failed++;
    if(*((int*) DS_ArrayAt(test, 1)) != 1) failed++;
    if(*((int*) DS_ArrayAt(test, 2)) != 2) failed++;
    if(*((int*) DS_ArrayAt(test, 3)) != 3) failed++;
    if(*((int*) DS_ArrayAt(test, 4)) != 4) failed++;
    if(*((int*) DS_ArrayAt(test, 5)) != 5) failed++;
    if(*((int*) DS_ArrayAt(test, 6)) != 6) failed++;
    if(*((int*) DS_ArrayAt(test, 7)) != 7) failed++;
    if(DS_ArrayLength(test) != 8) failed++;
    DS_ArrayDelete(test);
    return failed;
}

int main() {
    RunTests(11, (struct Test[11]) {
        (struct Test) {NewDeleteLength, "NewDeleteLength"},
        (struct Test) {ResizeAt, "ResizeAt"},
        (struct Test) {Get, "Get"},
        (struct Test) {Set, "Set"},
        (struct Test) {Copy, "Copy"},
        (struct Test) {Fill, "Fill"},
        (struct Test) {Max, "Max"},
        (struct Test) {Min, "Min"},
        (struct Test) {Count, "Count"},
        (struct Test) {Index, "Index"},
        (struct Test) {Sort, "Sort"},
    });
    return 0;
}
