#ifndef ARR_H
#define ARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>

extern const size_t ARR_HEAD_SIZE;

void* arr_Init(size_t len, size_t size);

void arr_Free(void *arr);

size_t arr_Len(const void *arr);

size_t arr_Size(const void *arr);

void* arr_App(void *arr, const void *src, size_t len);

#endif
