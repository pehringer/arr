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



int test_arr_Init(void) {
    return 0;
}

int main() {
    RunTests(1, (struct Test[1]) {
        (struct Test) {test_arr_Init, "test_arr_Init"},
    });
    return 0;
}
