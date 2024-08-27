#ifndef MY_STR_FUNCS_H__
#define MY_STR_FUNCS_H__

//puts, strchr, strlen, strcpy, strncpy, strcat, strncat, fgets, strdup, getline

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>


int print_array(int *data, size_t x, size_t y);

int print_tr_array(int *data, size_t total);

int *sum_arrays(size_t size_x, size_t size_y, int *data_1, int *data_2);

int *mult_arrays(int *data_1, size_t SIZE_X_1, size_t SIZE_Y_1,
                 int *data_2, size_t SIZE_X_2, size_t SIZE_Y_2);

int det_array(int *matr, size_t SIZE, size_t SIZE_Y);
int minor_array(int *matr, size_t SIZE, size_t SIZE_Y, size_t min_i, size_t min_j);

int alg_dop(size_t dop_i, size_t dop_j, int minor);
int *obr_matrix(int *matr, size_t SIZE, size_t SIZE_Y);

#endif // MY_STR_FUNCS_H__
