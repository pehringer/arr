#include "arr.h"

//Malloc will always return a pointer that is aligned for any data type. Since
//The header is stored at the beginning of the allocation we want to keep this
//universal alignment.
const size_t SIZEOF_HDR = ceil((sizeof(size_t) * 2.0) / sizeof(max_align_t)) * sizeof(max_align_t);

void* arr_Init(const size_t ele, const size_t len) {
    size_t *hdr = malloc(SIZEOF_HDR + len * ele);
    if(hdr == 0) {
        return 0;
    }
    hdr[0] = ele;
    hdr[1] = len;
    char *dat = (char*) hdr + SIZEOF_HDR;
    memset(dat, 0, len * ele);
    return dat;
}

void arr_Free(void *arr) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    free(hdr);
}

size_t arr_Len(const void *arr) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    return hdr[1];
}

void* arr_App(void *arr, const void *src, const size_t len) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    hdr[1] += len;
    hdr = realloc(hdr, SIZEOF_HDR + hdr[1] * hdr[0]);
    if(hdr == 0) {
        return 0;
    }
    char *dat = (char*) hdr + SIZEOF_HDR;
    memcpy(dat + (hdr[1] - len) * hdr[0], src, len * hdr[0]);
    return dat;
}
