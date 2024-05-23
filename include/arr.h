#ifndef ARR_H
#define ARR_H

#include <stdlib.h>
#include <string.h>

//Allocation And Configuration

void* arr_New(size_t size, int length, int (*compare)(const void*, const void*));

void arr_Delete(void *array);

int arr_Length(void *array);

void* arr_Resize(void *array, int length);

//Setters

void arr_Copy(void *array, int start, int stop, const void *source);

void arr_Fill(void *array, int start, int stop, const void *source);

//Search

int arr_Max(void *array, int start, int stop);

int arr_Min(void *array, int start, int stop);

int arr_Count(void *array, int start, int stop, const void *target);

int arr_Index(void *array, int start, int stop, const void *target);

//Sort

void arr_Sort(void *array, int start, int stop);

#endif
