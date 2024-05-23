#include "test.h"
#include "arr.h"


int IntCmp(const void *l, const void *r) {
    return *((int*) l) - *((int*) r);
}

int NewDeleteLength(void) {
    int failed = 0;
    int *test = arr_New(sizeof(int), 0, IntCmp);
    if(test == 0) failed++;
    if(arr_Length(test) != 0) failed++;
    arr_Delete(test);
    test = arr_New(sizeof(int), 4, IntCmp);
    if(test == 0) failed++;
    if(arr_Length(test) != 4) failed++;
    arr_Delete(test);
    return failed;
}

int Resize(void) {
    int failed = 0;
    int *test = arr_New(sizeof(int), 0, IntCmp);
    test = arr_Resize(test, 4);
    if(test == 0) failed++;
    test[0] = 3;
    test[1] = 2;
    test[2] = 1;
    test[3] = 0;
    test = arr_Resize(test, 8);
    if(test == 0) failed++;
    test[4] = 7;
    test[5] = 6;
    test[6] = 5;
    test[7] = 4;
    if(test[0] != 3) failed++;
    if(test[1] != 2) failed++;
    if(test[2] != 1) failed++;
    if(test[3] != 0) failed++;
    if(test[4] != 7) failed++;
    if(test[5] != 6) failed++;
    if(test[6] != 5) failed++;
    if(test[7] != 4) failed++;
    if(arr_Length(test) != 8) failed++;
    test = arr_Resize(test, 4);
    if(test == 0) failed++;
    if(test[0] != 3) failed++;
    if(test[1] != 2) failed++;
    if(test[2] != 1) failed++;
    if(test[3] != 0) failed++;
    if(arr_Length(test) != 4) failed++;
    arr_Delete(test);
    return failed;
}

int Copy(void) {
    int array[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 4, 8, array);
    arr_Copy(test, 0, 4, array + 4);
    if(test[0] != 3) failed++;
    if(test[1] != 2) failed++;
    if(test[2] != 1) failed++;
    if(test[3] != 0) failed++;
    if(test[4] != 7) failed++;
    if(test[5] != 6) failed++;
    if(test[6] != 5) failed++;
    if(test[7] != 4) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Copy(test, 2, 6, array);
    if(test[0] != 3) failed++;
    if(test[1] != 2) failed++;
    if(test[2] != 7) failed++;
    if(test[3] != 6) failed++;
    if(test[4] != 5) failed++;
    if(test[5] != 4) failed++;
    if(test[6] != 5) failed++;
    if(test[7] != 4) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}


int Fill(void) {
    int value = 0;
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    value = 5;
    arr_Fill(test, 4, 8, &value);
    value = 6;
    arr_Fill(test, 0, 4, &value);
    if(test[0] != 6) failed++;
    if(test[1] != 6) failed++;
    if(test[2] != 6) failed++;
    if(test[3] != 6) failed++;
    if(test[4] != 5) failed++;
    if(test[5] != 5) failed++;
    if(test[6] != 5) failed++;
    if(test[7] != 5) failed++;
    if(arr_Length(test) != 8) failed++;
    value = 7;
    arr_Fill(test, 2, 6, &value);
    if(test[0] != 6) failed++;
    if(test[1] != 6) failed++;
    if(test[2] != 7) failed++;
    if(test[3] != 7) failed++;
    if(test[4] != 7) failed++;
    if(test[5] != 7) failed++;
    if(test[6] != 5) failed++;
    if(test[7] != 5) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int Max(void) {
    int array[8] = {2, 4, 3, 1, 0, 5, 7, 6};
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 0, 8, array);
    if(arr_Max(test, 0, 0) != -1) failed++;
    if(arr_Max(test, 0, 1) != 0) failed++;
    if(arr_Max(test, 0, 2) != 1) failed++;
    if(arr_Max(test, 0, 3) != 1) failed++;
    if(arr_Max(test, 0, 4) != 1) failed++;
    if(arr_Max(test, 1, 5) != 1) failed++;
    if(arr_Max(test, 2, 6) != 5) failed++;
    if(arr_Max(test, 3, 7) != 6) failed++;
    if(arr_Max(test, 4, 8) != 6) failed++;
    if(arr_Max(test, 5, 8) != 6) failed++;
    if(arr_Max(test, 6, 8) != 6) failed++;
    if(arr_Max(test, 7, 8) != 7) failed++;
    if(arr_Max(test, 8, 8) != -1) failed++;
    if(arr_Max(test, 0, 8) != 6) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int Min(void) {
    int array[8] = {2, 4, 3, 1, 0, 5, 7, 6};
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 0, 8, array);
    if(arr_Min(test, 0, 0) != -1) failed++;
    if(arr_Min(test, 0, 1) != 0) failed++;
    if(arr_Min(test, 0, 2) != 0) failed++;
    if(arr_Min(test, 0, 3) != 0) failed++;
    if(arr_Min(test, 0, 4) != 3) failed++;
    if(arr_Min(test, 1, 5) != 4) failed++;
    if(arr_Min(test, 2, 6) != 4) failed++;
    if(arr_Min(test, 3, 7) != 4) failed++;
    if(arr_Min(test, 4, 8) != 4) failed++;
    if(arr_Min(test, 5, 8) != 5) failed++;
    if(arr_Min(test, 6, 8) != 7) failed++;
    if(arr_Min(test, 7, 8) != 7) failed++;
    if(arr_Min(test, 8, 8) != -1) failed++;
    if(arr_Min(test, 0, 8) != 4) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int Count(void) {
    int array[8] = {1, 2, 0, 0, 2, 1, 0, 1};
    int target = -1;
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 0, 8, array);
    target = 0;
    if(arr_Count(test, 0, 4, &target) != 2) failed++;
    if(arr_Count(test, 4, 8, &target) != 1) failed++;
    if(arr_Count(test, 2, 6, &target) != 2) failed++;
    if(arr_Count(test, 0, 8, &target) != 3) failed++;
    target = 1;
    if(arr_Count(test, 0, 4, &target) != 1) failed++;
    if(arr_Count(test, 4, 8, &target) != 2) failed++;
    if(arr_Count(test, 2, 6, &target) != 1) failed++;
    if(arr_Count(test, 0, 8, &target) != 3) failed++;
    target = 2;
    if(arr_Count(test, 0, 4, &target) != 1) failed++;
    if(arr_Count(test, 4, 8, &target) != 1) failed++;
    if(arr_Count(test, 2, 6, &target) != 1) failed++;
    if(arr_Count(test, 0, 8, &target) != 2) failed++;
    target = 3;
    if(arr_Count(test, 0, 4, &target) != 0) failed++;
    if(arr_Count(test, 4, 8, &target) != 0) failed++;
    if(arr_Count(test, 2, 6, &target) != 0) failed++;
    if(arr_Count(test, 0, 8, &target) != 0) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int Index(void) {
    int array[8] = {1, 2, 0, 0, 2, 1, 0, 1};
    int target = -1;
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 0, 8, array);
    target = 0;
    if(arr_Index(test, 0, 4, &target) != 2) failed++;
    if(arr_Index(test, 4, 8, &target) != 6) failed++;
    if(arr_Index(test, 2, 6, &target) != 2) failed++;
    if(arr_Index(test, 0, 8, &target) != 2) failed++;
    target = 1;
    if(arr_Index(test, 0, 4, &target) != 0) failed++;
    if(arr_Index(test, 4, 8, &target) != 5) failed++;
    if(arr_Index(test, 2, 6, &target) != 5) failed++;
    if(arr_Index(test, 0, 8, &target) != 0) failed++;
    target = 2;
    if(arr_Index(test, 0, 4, &target) != 1) failed++;
    if(arr_Index(test, 4, 8, &target) != 4) failed++;
    if(arr_Index(test, 2, 6, &target) != 4) failed++;
    if(arr_Index(test, 0, 8, &target) != 1) failed++;
    target = 3;
    if(arr_Index(test, 0, 4, &target) != -1) failed++;
    if(arr_Index(test, 4, 8, &target) != -1) failed++;
    if(arr_Index(test, 2, 6, &target) != -1) failed++;
    if(arr_Index(test, 0, 8, &target) != -1) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int Sort(void) {
   int array[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    int failed = 0;
    int *test = arr_New(sizeof(int), 8, IntCmp);
    arr_Copy(test, 0, 8, array);
    arr_Sort(test, 0, 4);
    if(test[0] != 4) failed++;
    if(test[1] != 5) failed++;
    if(test[2] != 6) failed++;
    if(test[3] != 7) failed++;
    if(test[4] != 3) failed++;
    if(test[5] != 2) failed++;
    if(test[6] != 1) failed++;
    if(test[7] != 0) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Sort(test, 4, 8);
    if(test[0] != 4) failed++;
    if(test[1] != 5) failed++;
    if(test[2] != 6) failed++;
    if(test[3] != 7) failed++;
    if(test[4] != 0) failed++;
    if(test[5] != 1) failed++;
    if(test[6] != 2) failed++;
    if(test[7] != 3) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Sort(test, 2, 6);
    if(test[0] != 4) failed++;
    if(test[1] != 5) failed++;
    if(test[2] != 0) failed++;
    if(test[3] != 1) failed++;
    if(test[4] != 6) failed++;
    if(test[5] != 7) failed++;
    if(test[6] != 2) failed++;
    if(test[7] != 3) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Sort(test, 0, 8);
    if(test[0] != 0) failed++;
    if(test[1] != 1) failed++;
    if(test[2] != 2) failed++;
    if(test[3] != 3) failed++;
    if(test[4] != 4) failed++;
    if(test[5] != 5) failed++;
    if(test[6] != 6) failed++;
    if(test[7] != 7) failed++;
    if(arr_Length(test) != 8) failed++;
    arr_Delete(test);
    return failed;
}

int main() {
    RunTests(9, (struct Test[9]) {
        (struct Test) {NewDeleteLength, "NewDeleteLength"},
        (struct Test) {Resize, "Resize"},
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
