#include "my_mas_funcs.h"

int print_array(int *data, size_t x, size_t y)
{
    assert(data != NULL);

    for(size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            int elem = *(data + y * i + j);

            // printf("data[%lu][%lu] = %d ", i, j, elem);
            printf("%3d ", elem);
        }

        printf("\n");
    }

    return 0;
}

int print_tr_array(int *data, size_t total)
{
    assert(data != NULL);

    size_t ar_pr = 1; // arithmetical progression

    for (size_t i = 0; i < total; i++)
    {
        printf("%3d", *(data + i));

        if (i + 1 == ar_pr * (ar_pr + 1) / 2)
        {
            printf("\n");
            ar_pr++;
        }
    }

    printf("\n");

    return 0;
}


int *sum_arrays(size_t size_x, size_t size_y, int *data_1, int *data_2)
{
    int *ret_arr = (int *) calloc(size_x * size_y, sizeof(int));

    for (size_t i = 0; i < size_x; i++)
    {
        for (size_t j = 0; j < size_y; j++)
        {
            size_t addr_offset = i * size_y + j;
            *(ret_arr + addr_offset) = *(data_1 + addr_offset) + *(data_2 + addr_offset);
        }
    }

    return ret_arr;
}

int *mult_arrays(int *data_1, size_t SIZE_X_1, size_t SIZE_Y_1,
                 int *data_2, size_t SIZE_X_2, size_t SIZE_Y_2)
{
    assert(data_1 != NULL);
    assert(data_2 != NULL);
    assert(SIZE_X_2 == SIZE_Y_1);


    int *ret_arr = (int *) calloc(SIZE_X_1 * SIZE_Y_2, sizeof(int));

    for (size_t i = 0; i < SIZE_X_1; i++)
    {
        for (size_t j = 0; j < SIZE_Y_2; j++)
        {
            for (size_t k = 0; k < SIZE_Y_1; k++)
            {
                ret_arr[i * SIZE_Y_2 + j] += data_1[i * SIZE_Y_1 + k] * data_2[k * SIZE_Y_2 + j];
            }
        }
    }

    return ret_arr;
}


int det_array(int *matr, size_t SIZE, size_t SIZE_Y)
{
    assert(SIZE == SIZE_Y);
    assert(matr != NULL);

    int ret_det = 0;

    if (SIZE == 1)
    {
        return matr[0];
    }

    if (SIZE == 2)
    {
        ret_det = matr[3] * matr[0] - matr[1] * matr[2];

        return ret_det;
    }

    for (size_t i = 0; i<SIZE; i++)
    {
        if ((1 + i) % 2 == 0)
            ret_det -= matr[i] * minor_array(matr, SIZE, SIZE, 0, i);
        else
            ret_det += matr[i] * minor_array(matr, SIZE, SIZE, 0, i);
    }

    return ret_det;
}

int minor_array(int *matr, size_t SIZE, size_t SIZE_Y, size_t min_i, size_t min_j)
{
    assert(matr != NULL);
    assert(SIZE == SIZE_Y);

    int *minor_matrix = (int *) calloc((SIZE - 1) * (SIZE - 1), sizeof(int));

    bool is_i_added = false, is_j_added = false;

    for (size_t i = 0, i2 = 0; i < SIZE - 1; i++, i2++)
    {
        for (size_t j = 0, j2 = 0; j < SIZE - 1; j++, j2++)
        {
            if (i2 == min_i && !is_i_added)
            {
                is_i_added = true;
                i2++;
            }

            if (j2 == min_j && !is_j_added)
            {
                is_j_added = true;
                j2++;
            }

            minor_matrix[i * (SIZE - 1) + j] = matr[i2 * SIZE + j2];
        }

        is_j_added = false;
    }
    // printf("For array:\n");
    // print_array(matr, SIZE, SIZE);
    // printf("Printing minor matrix for i = %lu, j = %lu\n", min_i, min_j);
    // print_array(minor_matrix, SIZE - 1, SIZE - 1);
    // printf("\n\n");

    int ret_val = det_array(minor_matrix, SIZE - 1, SIZE - 1);

    free(minor_matrix);

    return ret_val;
}

int alg_dop(size_t dop_i, size_t dop_j, int minor)
{
    if ((dop_i + dop_j) % 2 == 0)
    {
        return +minor;
    }

    return -minor;
}

int *obr_matrix(int *matr, size_t SIZE, size_t SIZE_Y)
{
    assert(SIZE == SIZE_Y);
    assert(matr != NULL);

    int *ret_matr = (int *) calloc(SIZE * SIZE, sizeof(int));

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            int minor_ij = minor_array(matr, SIZE, SIZE, i, j);

            ret_matr[j * SIZE + i] = alg_dop(i, j, minor_ij); // transponirovanie
        }
    }

    return ret_matr;
}
