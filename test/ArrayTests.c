#include "Test.h"
#include "cds_Array.h"

int cds_ArrayConstruct_LengthZero() {
    struct cds_Array array;
    if(cds_ArrayConstruct(&array, sizeof(int), 0) == 0 ||
       array.length != 0 ||
       array.sizeOf != sizeof(int)) {
        return 1;
    }
    return 0;
}

int main() {
    struct Test tests[1] = {
         (struct Test) {cds_ArrayConstruct_LengthZero, "cds_ArrayConstruct_LengthZero"}
    };
    RunTests(tests, 1);
    return 0;
}
