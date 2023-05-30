#include "Test.h"

void RunTests(int number, struct Test *tests) {
    int failures = 0;
    for(int index = 0; index < number; index++) {
        if(tests[index].function()) {
            printf("Test failed: %s\n", tests[index].name);
            failures++;
        }
    }
    if(failures == 0) {
        printf("All tests passed.\n");
    }
}
