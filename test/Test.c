#include "Test.h"

void RunTests(struct Test *tests, int length) {
    int failures = 0;
    for(int index = 0; index < length; index++) {
        if(tests[index].function()) {
            printf("Test failed: %s\n", tests[index].name);
            failures++;
        }
    }
    if(failures == 0) {
        printf("All tests passed.\n");
    }
}
