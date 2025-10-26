#include "arr.h"

/*

Arr memory layout:

                    pointer returned by arr_Create / arr_Append
                   /
_____________________________________________
| arr_t | padding | element | ... | element |
|       |         | 0       |     | n       |
|_______|_________|_________|_____|_________|

*/

typedef struct arr_t {
    size_t length;
    size_t size;
} arr_t;

//Malloc will always return a pointer that is aligned for any data type. Since
//The struct is stored at the beginning of the allocation we want to keep this
//universal alignment.
const size_t PADDED = (sizeof(arr_t) / sizeof(max_align_t) + 1) * sizeof(max_align_t);

void* arr_Create(size_t length, size_t size) {
    arr_t *a = malloc(PADDED + length * size);
    if(a == 0) {
        return 0;
    }
    a->length = length;
    a->size = size;
    unsigned char *d = (unsigned char*) a + PADDED;
    memset(d, 0, length * size);
    return d;
}

void arr_Destroy(void *array) {
    arr_t *a = (arr_t*) ((unsigned char*) array - PADDED);
    free(a);
}

size_t arr_Length(const void *array) {
    arr_t *a = (arr_t*) ((unsigned char*) array - PADDED);
    return a->length;
}

void* arr_Append(void *array, const void *source, size_t length) {
    arr_t *a = (arr_t*) ((unsigned char*) array - PADDED);
    a = realloc(a, PADDED + (a->length + length) * a->size);
    if(a == 0) {
        return 0;
    }
    unsigned char *d = (unsigned char*) a + PADDED;
    memcpy(d + a->length * a->size, source, length * a->size);
    a->length += length;
    return d;
}
