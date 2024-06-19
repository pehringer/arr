#include "arr.h"

//Malloc will always return a pointer that is aligned for any data type. Since
//The header is stored at the beginning of the allocation we want to keep this
//universal alignment.
const size_t ARR_HEAD_SIZE = ceil((sizeof(size_t) * 2.0) / sizeof(max_align_t)) * sizeof(max_align_t);

void* arr_Init(size_t len, size_t size) {
    size_t *head = (size_t*) malloc(ARR_HEAD_SIZE + len * size);
    if(head == 0) {
        return 0;
    }
    head[0] = len;
    head[1] = size;
    char *data = (char*) head + ARR_HEAD_SIZE;
    memset(data, 0, len * size);
    return data;
}

void arr_Free(void *arr) {
    size_t *head = (size_t*) ((char*) arr - ARR_HEAD_SIZE);
    free(head);
}

size_t arr_Len(const void *arr) {
    size_t *head = (size_t*) ((char*) arr - ARR_HEAD_SIZE);
    return head[0];
}

size_t arr_Size(const void *arr) {
    size_t *head = (size_t*) ((char*) arr - ARR_HEAD_SIZE);
    return head[1];
}

void* arr_App(void *arr, const void *src, size_t len) {
    size_t *head = (size_t*) ((char*) arr - ARR_HEAD_SIZE);
    head[0] += len;
    head = (size_t*) realloc(head, ARR_HEAD_SIZE + head[0] * head[1]);
    if(head == 0) {
        return 0;
    }
    char *data = (char*) head + ARR_HEAD_SIZE;
    memcpy(data + (head[0] - len) * head[1], src, len * head[1]);
    return data;
}




