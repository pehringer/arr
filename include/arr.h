#ifndef ARR_H
#define ARR_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void* arr_Create(size_t length, size_t size);

void arr_Destroy(void *array);

size_t arr_Length(const void *array);

void* arr_Append(void *array, const void *source, size_t length);

#endif
