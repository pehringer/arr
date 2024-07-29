#include "arr.h"

struct Arr {
    size_t ele;
    size_t len;
};

//Malloc will always return a pointer that is aligned for any data type. Since
//The struct is stored at the beginning of the allocation we want to keep this
//universal alignment.
const size_t PADDED = ceil((float) sizeof(struct Arr) / (float) sizeof(max_align_t)) * sizeof(max_align_t);

void* arr_Init(const size_t ele, const size_t len) {
    struct Arr *a = malloc(PADDED + len * ele);
    if(a == 0) {
        return 0;
    }
    a->ele = ele;
    a->len = len;
    char *dat = (char*) a + PADDED;
    memset(dat, 0, len * ele);
    return dat;
}

void arr_Free(void *arr) {
    struct Arr *a = (struct Arr*) ((char*) arr - PADDED);
    free(a);
}

size_t arr_Len(const void *arr) {
    struct Arr *a = (struct Arr*) ((char*) arr - PADDED);
    return a->len;
}

void* arr_App(void *arr, const void *src, const size_t len) {
    struct Arr *a = (struct Arr*) ((char*) arr - PADDED);
    a->len += len;
    a = realloc(a, PADDED + a->len * a->ele);
    if(a == 0) {
        return 0;
    }
    char *dat = (char*) a + PADDED;
    memcpy(dat + (a->len - len) * a->ele, src, len * a->ele);
    return dat;
}
