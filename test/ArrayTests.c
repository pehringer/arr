#include "Test.h"
#include "DS_Array.h"

int IntCmp(const void *l, const void *r) {
    return *(int*)l - *(int*)r;
}

int NewDeleteZero() {
    int failed = 0;
    struct DS_Array *arr = DS_ArrayNew(sizeof(int), 0, IntCmp);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 0) failed++;
    if(arr->size != sizeof(int)) failed++;
    DS_ArrayDelete(arr);
    return failed;
}

int NewDeleteMany() {
    int failed = 0;
    struct DS_Array *arr = DS_ArrayNew(sizeof(int), 4, IntCmp);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 4) failed++;
    if(arr->size != sizeof(int)) failed++;
    *((int*) arr->base + 0) = 0;
    *((int*) arr->base + 1) = 1;
    *((int*) arr->base + 2) = 2;
    *((int*) arr->base + 3) = 3;
    DS_ArrayDelete(arr);
    return failed;
}

int ResizeBigger() {
    int failed = 0;
    struct DS_Array *arr = DS_ArrayNew(sizeof(int), 0, IntCmp);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 0) failed++;
    if(arr->size != sizeof(int)) failed++;
    arr = DS_ArrayResize(arr, 4);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 4) failed++;
    if(arr->size != sizeof(int)) failed++;
    *((int*) arr->base + 0) = 0;
    *((int*) arr->base + 1) = 1;
    *((int*) arr->base + 2) = 2;
    *((int*) arr->base + 3) = 3;
    arr = DS_ArrayResize(arr, 8);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 8) failed++;
    if(arr->size != sizeof(int)) failed++;
    *((int*) arr->base + 4) = 4;
    *((int*) arr->base + 5) = 5;
    *((int*) arr->base + 6) = 6;
    *((int*) arr->base + 7) = 7;
    if(*((int*) arr->base + 0) != 0) failed++;
    if(*((int*) arr->base + 1) != 1) failed++;
    if(*((int*) arr->base + 2) != 2) failed++;
    if(*((int*) arr->base + 3) != 3) failed++;
    if(*((int*) arr->base + 4) != 4) failed++;
    if(*((int*) arr->base + 5) != 5) failed++;
    if(*((int*) arr->base + 6) != 6) failed++;
    if(*((int*) arr->base + 7) != 7) failed++;
    DS_ArrayDelete(arr);
    return failed;
}

int ResizeSmaller() {
    int failed = 0;
    struct DS_Array *arr = DS_ArrayNew(sizeof(int), 8, IntCmp);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 8) failed++;
    if(arr->size != sizeof(int)) failed++;
    *((int*) arr->base + 0) = 0;
    *((int*) arr->base + 1) = 1;
    *((int*) arr->base + 2) = 2;
    *((int*) arr->base + 3) = 3;
    *((int*) arr->base + 4) = 4;
    *((int*) arr->base + 5) = 5;
    *((int*) arr->base + 6) = 6;
    *((int*) arr->base + 7) = 7;
    arr = DS_ArrayResize(arr, 4);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 4) failed++;
    if(arr->size != sizeof(int)) failed++;
    if(*((int*) arr->base + 0) != 0) failed++;
    if(*((int*) arr->base + 1) != 1) failed++;
    if(*((int*) arr->base + 2) != 2) failed++;
    if(*((int*) arr->base + 3) != 3) failed++;
    if(*((int*) arr->base + 4) != 4) failed++;
    arr = DS_ArrayResize(arr, 0);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 0) failed++;
    if(arr->size != sizeof(int)) failed++;
    DS_ArrayDelete(arr);
    return failed;
}

int AtAll() {
    int failed = 0;
    struct DS_Array *arr = DS_ArrayNew(sizeof(int), 4, IntCmp);
    if(arr == 0) failed++;
    if(arr->compare == 0) failed++;
    if(arr->length != 4) failed++;
    if(arr->size != sizeof(int)) failed++;
    *((int*) DS_ArrayAt(arr, 0)) = 0;
    *((int*) DS_ArrayAt(arr, 1)) = 1;
    *((int*) DS_ArrayAt(arr, 2)) = 2;
    *((int*) DS_ArrayAt(arr, 3)) = 3;
    if(*((int*) DS_ArrayAt(arr, 0)) != 0) failed++;
    if(*((int*) DS_ArrayAt(arr, 1)) != 1) failed++;
    if(*((int*) DS_ArrayAt(arr, 2)) != 2) failed++;
    if(*((int*) DS_ArrayAt(arr, 3)) != 3) failed++;
    DS_ArrayDelete(arr);
    return failed;
}

int main() {
    RunTests(5, (struct Test[5]) {
        (struct Test) {NewDeleteZero, "NewDeleteZero"},
        (struct Test) {NewDeleteMany, "NewDeleteMany"},
        (struct Test) {ResizeBigger, "ResizeBigger"},
        (struct Test) {ResizeSmaller, "ResizeSmaller"},
        (struct Test) {AtAll, "AtAll"},
    });
    return 0;
}
