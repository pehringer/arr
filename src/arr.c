#include "arr.h"

//Malloc will always return a pointer that is aligned for any data type. Since
//The header is stored at the beginning of the allocation we want to keep this
//universal alignment.
const size_t SIZEOF_HDR = ceil((sizeof(size_t) * 2.0) / sizeof(max_align_t)) * sizeof(max_align_t);

void* arr_Init(const size_t len, const size_t typ) {
    size_t *hdr = malloc(SIZEOF_HDR + len * typ);
    if(hdr == 0) {
        return 0;
    }
    hdr[0] = len;
    hdr[1] = typ;
    char *dat = (char*) hdr + SIZEOF_HDR;
    memset(dat, 0, len * typ);
    return dat;
}

void arr_Free(void *arr) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    free(hdr);
}

size_t arr_Len(const void *arr) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    return hdr[0];
}

void* arr_App(void *arr, const void *src, const size_t len) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    hdr[0] += len;
    hdr = realloc(hdr, SIZEOF_HDR + hdr[0] * hdr[1]);
    if(hdr == 0) {
        return 0;
    }
    char *dat = (char*) hdr + SIZEOF_HDR;
    memcpy(dat + (hdr[0] - len) * hdr[1], src, len * hdr[1]);
    return dat;
}

/*
size_t arr_Cpy(void *arr, const void *src, const size_t len) {
    size_t *hdr = (size_t*) ((char*) arr - SIZEOF_HDR);
    size_t cpy = len;
    if(hdr[0] < len) {
        cpy = hdr[0];
    }
    if(cpy > 0) {
        memcpy(arr, src, cpy * hdr[1]);
    }
    return cpy;
}
*/




