#ifndef ARR_H
#define ARR_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

void* arr_Init(const size_t ele, const size_t len);

void arr_Free(void *arr);

size_t arr_Len(const void *arr);

void* arr_App(void *arr, const void *src, const size_t len);

#endif
