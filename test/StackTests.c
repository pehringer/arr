#include "Test.h"
#include "cds_Stack.h"

int ConstructDestructCapacityZero() {
    int failed = 0;
    struct cds_Stack stack;
    if(cds_StackConstruct(&stack, sizeof(int), 0) == 0 ||
        stack.length != 0 ||
        stack.capacity != 0 ||
        stack.size != sizeof(int)) {
        failed++;
    }
    cds_StackDestruct(&stack);
    if(stack.first != 0 ||
        stack.top != 0 ||
        stack.capacity != 0 ||
        stack.length != 0 ||
        stack.size != 0) {
        failed++;
    }
    return failed;
}

int main() {
    RunTests(1, (struct Test[1]) {
        (struct Test) {ConstructDestructCapacityZero, "ConstructDestructCapacityZero"},
        //(struct Test) {ConstructDestructLengthNonZero, "ConstructDestructLengthNonZero"},
        //(struct Test) {FromArrayToArrayAll, "FromArrayToArrayAll"},
        //(struct Test) {FromArrayToArrayFirstHalf, "FromArrayToArrayFirstHalf"},
        //(struct Test) {FromArrayToArraySecondHalf, "FromArrayToArraySecondHalf"},
        //(struct Test) {FromArrayToArrayMiddle, "FromArrayToArrayMiddle"},
        //(struct Test) {FromArrayToArrayNone, "FromArrayToArrayNone"},
    });
    return 0;
}
