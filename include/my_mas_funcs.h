#ifndef MY_STR_FUNCS_H__
#define MY_STR_FUNCS_H__

//puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>


int print_array(int *data, size_t x, size_t y);

int print_tr_array(int *data, size_t total);

int *sum_arrays(size_t size_x, size_t size_y, int *data_1, int *data_2);

#endif // MY_STR_FUNCS_H__
