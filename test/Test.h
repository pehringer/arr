#ifndef TEST_H
#define TEST_H

#include <stdio.h>

struct Test {
    int (*function)(void);
    char *name;
};

void RunTests(int number, struct Test *tests);

#endif
