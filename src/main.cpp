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
    free(arr_sum); arr_sum = NULL;
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

    struct matrix mult_matr_1 =
    {
        (int *) mult_arr_1,
        sizeof(mult_arr_1)    / sizeof(mult_arr_1[0]),
        sizeof(mult_arr_1[0]) / sizeof(mult_arr_1[0][0])
    };

    struct matrix mult_matr_2 =
    {
        (int *) mult_arr_2,
        sizeof(mult_arr_2)    / sizeof(mult_arr_2[0]),
        sizeof(mult_arr_2[0]) / sizeof(mult_arr_2[0][0])
    };

    struct matrix mult_matr = mult_arrays(mult_matr_1, mult_matr_2);
    print_array(mult_matr);
    free(mult_matr.ptr); mult_matr.ptr = NULL;

    printf("\n");
    /*int to_obr_matrix[2][2] =
    {
        {-5, 7},
        {9, 8},
    };*/
    /*
    int to_obr_matrix[3][3] =
    {
        {1, 7, 3},
        {-4, 9, 4},
        {0, 3, 2}
    };*/

    int to_obr_matrix[4][4] =
    {
        {6, -5, 8, 4},
        {9, 7, 5, 2},
        {7, 5, 3, 7},
        {-4, 8, -8, -3}
    };

    struct matrix to_obr =
    {
        .ptr = (int *) to_obr_matrix,
        .size_x = sizeof(to_obr_matrix) / sizeof(to_obr_matrix[0]),
        .size_y = sizeof(to_obr_matrix[0]) / sizeof(to_obr_matrix[0][0])
    };

    printf("1/%d * matrix:\n", det_array(to_obr));

    struct matrix obr_arr = obr_matrix(to_obr);
    print_array(obr_arr);
    free(obr_arr.ptr); obr_arr.ptr = NULL;

    struct matrix input_matr = input_matrix();
    print_array(input_matr);
    free(input_matr.ptr); input_matr.ptr = NULL;

    return EXIT_SUCCESS;
}
