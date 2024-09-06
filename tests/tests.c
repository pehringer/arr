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
        int error = tests[index].function();
        if(error) {
            printf("FAILED: %d\n", error);
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
    int *a = arr_Create(0, 0);
    if(arr_Length(a) != 0) return 1;
    arr_Destroy(a);
    a = arr_Create(0, sizeof(int));
    if(arr_Length(a) != 0) return 2;
    arr_Destroy(a);
    return 0;
}

int non_zero_len_init(void) {
    int *a = arr_Create(9, 0);
    if(arr_Length(a) != 9) return 1;
    arr_Destroy(a);
    a = arr_Create(3, sizeof(int));
    if(arr_Length(a) != 3) return 2;
    if(a[0] != 0) return 3;
    if(a[1] != 0) return 4;
    if(a[2] != 0) return 5;
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    if(arr_Length(a) != 3) return 6;
    if(a[0] != 2) return 7;
    if(a[1] != 3) return 8;
    if(a[2] != 5) return 9;
    arr_Destroy(a);
    return 0;
}

int zero_len_app_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Create(0, 0);
    a = arr_Append(a, 0, 0);
    if(arr_Length(a) != 0) return 1;
    arr_Destroy(a);
    a = arr_Create(0, sizeof(int));
    a = arr_Append(a, v, 0);
    if(arr_Length(a) != 0) return 2;
    arr_Destroy(a);
    if(v[0] != 9) return 3;
    if(v[1] != 8) return 4;
    if(v[2] != 7) return 5;
    if(v[3] != 6) return 6;
    if(v[4] != 5) return 7;
    if(v[5] != 4) return 8;
    if(v[6] != 3) return 9;
    if(v[7] != 2) return 10;
    if(v[8] != 1) return 11;
    return 0;
}

int non_zero_len_app_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Create(9, 0);
    a = arr_Append(a, 0, 0);
    if(arr_Length(a) != 9) return 1;
    arr_Destroy(a);
    a = arr_Create(3, sizeof(int));
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a = arr_Append(a, v, 0);
    if(arr_Length(a) != 3) return 2;
    if(a[0] != 2) return 3;
    if(a[1] != 3) return 4;
    if(a[2] != 5) return 5;
    arr_Destroy(a);
    if(v[0] != 9) return 6;
    if(v[1] != 8) return 7;
    if(v[2] != 7) return 8;
    if(v[3] != 6) return 9;
    if(v[4] != 5) return 10;
    if(v[5] != 4) return 11;
    if(v[6] != 3) return 12;
    if(v[7] != 2) return 13;
    if(v[8] != 1) return 14;
    return 0;
}

int zero_len_app_non_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Create(0, 0);
    a = arr_Append(a, 0, 9);
    if(arr_Length(a) != 9) return 1;
    arr_Destroy(a);
    a = arr_Create(0, sizeof(int));
    a = arr_Append(a, v + 5, 4);
    if(arr_Length(a) != 4) return 2;
    if(a[0] != 4) return 3;
    if(a[1] != 3) return 4;
    if(a[2] != 2) return 5;
    if(a[3] != 1) return 6;
    arr_Destroy(a);
    if(v[0] != 9) return 7;
    if(v[1] != 8) return 8;
    if(v[2] != 7) return 9;
    if(v[3] != 6) return 10;
    if(v[4] != 5) return 11;
    if(v[5] != 4) return 12;
    if(v[6] != 3) return 13;
    if(v[7] != 2) return 14;
    if(v[8] != 1) return 15;
    return 0;
}

int non_zero_len_app_non_zero(void) {
    int v[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *a = arr_Create(9, 0);
    a = arr_Append(a, 0, 7);
    if(arr_Length(a) != 16) return 1;
    arr_Destroy(a);
    a = arr_Create(3, sizeof(int));
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a = arr_Append(a, v + 5, 4);
    if(arr_Length(a) != 7) return 2;
    if(a[0] != 2) return 3;
    if(a[1] != 3) return 4;
    if(a[2] != 5) return 5;
    if(a[3] != 4) return 6;
    if(a[4] != 3) return 7;
    if(a[5] != 2) return 8;
    if(a[6] != 1) return 9;
    arr_Destroy(a);
    if(v[0] != 9) return 10;
    if(v[1] != 8) return 11;
    if(v[2] != 7) return 12;
    if(v[3] != 6) return 13;
    if(v[4] != 5) return 14;
    if(v[5] != 4) return 15;
    if(v[6] != 3) return 16;
    if(v[7] != 2) return 17;
    if(v[8] != 1) return 18;
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

