#include <stdio.h>
#include <stdlib.h>

#include "my_mas_funcs.h"
#include <string.h>

int main()
{
    int pr_arr[][3] =
    {
        {11, 12, 13},
        {21, 22, 23},
        {31, 32, 33},
        {41, 42, 43}
    };
    int pr_arr_2[][3] =
    {
        {43, 42, 41},
        {33, 32, 31},
        {23, 22, 21},
        {13, 12, 11}
    };

    int tr_arr[] =
    {
         1,
        -1,  0,
         0,  1, 1,
         1, -1, 0, 1
    };
    const int SIZE_X = sizeof(pr_arr) / sizeof(pr_arr[0]);
    const int SIZE_Y = sizeof(pr_arr[0]) / sizeof(pr_arr[0][0]);


    print_array((int *) pr_arr, SIZE_X, SIZE_Y);

    printf("\n");

    print_tr_array((int *) tr_arr, sizeof(tr_arr) / sizeof(int));

    int * arr_sum = sum_arrays(SIZE_X, SIZE_Y, (int *) pr_arr, (int *) pr_arr_2);

    print_array(arr_sum, SIZE_X, SIZE_Y);

    printf("\n");

    int mult_arr_1[4][2] =
    {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
    };

    int mult_arr_2[2][3] =
    {
        { 7,  8,  9},
        {10, 11, 12}
    };

    size_t SIZE_X_1 = sizeof(mult_arr_1) / sizeof(mult_arr_1[0]);
    size_t SIZE_Y_1 = sizeof(mult_arr_1[0]) / sizeof(mult_arr_1[0][0]);


    size_t SIZE_X_2 = sizeof(mult_arr_2) / sizeof(mult_arr_2[0]);
    size_t SIZE_Y_2 = sizeof(mult_arr_2[0]) / sizeof(mult_arr_2[0][0]);

    int * arr_mult = mult_arrays((int *) mult_arr_1, SIZE_X_1, SIZE_Y_1,
                                 (int *) mult_arr_2, SIZE_X_2, SIZE_Y_2);


    print_array(arr_mult, SIZE_X_1, SIZE_Y_2);

    free(arr_sum);
    free(arr_mult);

    return EXIT_SUCCESS;
}
