#include <stdio.h>
#include "arr.h"

struct Test {
    int (*function)(void);
    char *name;
};

void RunTests(int number, struct Test *tests) {
    int failed = 0;
    int passed = 0;
    printf("--------------------------------------\n");
    for(int index = 0; index < number; index++) {
        printf("%s: ", tests[index].name);
        fflush(stdout);
        if(tests[index].function()) {
            printf("FAILED\n");
            failed++;
        } else {
            printf("PASSED\n");
            passed++;
        }
    }
    printf("--------------------------------------\n");
    printf("Tests Failed: %d Tests Passed: %d\n", failed, passed);
    printf("--------------------------------------\n");
}

int zero_len_init(void) {
    int *a = arr_Init(0, 0);
    if(arr_Len(a) != 0) return 1;
    arr_Free(a);
    a = arr_Init(0, sizeof(int));
    if(arr_Len(a) != 0) return 1;
    arr_Free(a);
    return 0;
}

int non_zero_len_init(void) {
    int *a = arr_Init(9, 0);
    if(arr_Len(a) != 9) return 1;
    arr_Free(a);
    a = arr_Init(3, sizeof(int));
    if(arr_Len(a) != 3) return 1;
    if(a[0] != 0) return 1;
    if(a[1] != 0) return 1;
    if(a[2] != 0) return 1;
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    if(arr_Len(a) != 3) return 1;
    if(a[0] != 2) return 1;
    if(a[1] != 3) return 1;
    if(a[2] != 5) return 1;
    arr_Free(a);
    return 0;
}

int zero_len_app_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Init(0, 0);
    a = arr_App(a, 0, 0);
    if(arr_Len(a) != 0) return 1;
    arr_Free(a);
    a = arr_Init(0, sizeof(int));
    a = arr_App(a, v, 0);
    if(arr_Len(a) != 0) return 1;
    arr_Free(a);
    return 0;
}

int non_zero_len_app_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Init(9, 0);
    a = arr_App(a, 0, 0);
    if(arr_Len(a) != 9) return 1;
    arr_Free(a);
    a = arr_Init(3, sizeof(int));
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a = arr_App(a, v, 0);
    if(arr_Len(a) != 3) return 1;
    if(a[0] != 2) return 1;
    if(a[1] != 3) return 1;
    if(a[2] != 5) return 1;
    arr_Free(a);
    return 0;
}

int zero_len_app_non_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Init(0, 0);
    a = arr_App(a, 0, 9);
    if(arr_Len(a) != 9) return 1;
    arr_Free(a);
    a = arr_Init(0, sizeof(int));
    a = arr_App(a, v + 5, 4);
    if(arr_Len(a) != 4) return 1;
    if(a[0] != 4) return 1;
    if(a[1] != 3) return 1;
    if(a[2] != 2) return 1;
    if(a[3] != 1) return 1;
    arr_Free(a);
    return 0;
}

int non_zero_len_app_non_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Init(9, 0);
    a = arr_App(a, 0, 7);
    if(arr_Len(a) != 16) return 1;
    arr_Free(a);
    a = arr_Init(3, sizeof(int));
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a = arr_App(a, v + 5, 4);
    if(arr_Len(a) != 7) return 1;
    if(a[0] != 2) return 1;
    if(a[1] != 3) return 1;
    if(a[2] != 5) return 1;
    if(a[3] != 4) return 1;
    if(a[4] != 3) return 1;
    if(a[5] != 2) return 1;
    if(a[6] != 1) return 1;
    arr_Free(a);
    return 0;
}

int main() {
    RunTests(6, (struct Test[6]) {
        (struct Test) {zero_len_init, "zero_len_init"},
        (struct Test) {non_zero_len_init, "non_zero_len_init"},
        (struct Test) {zero_len_app_zero, "zero_len_app_zero"},
        (struct Test) {non_zero_len_app_zero, "non_zero_len_app_zero"},
        (struct Test) {zero_len_app_non_zero, "zero_len_app_non_zero"},
        (struct Test) {non_zero_len_app_non_zero, "non_zero_len_app_non_zero"},
    });
    return 0;
}
