#include "my_mas_funcs.h"

int print_array(int *data, size_t x, size_t y)
{
    assert(data != NULL);

    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            int elem = *(data + y * i + j);

            #ifdef FULL_PRINT_MATRIX
            printf("data[%lu][%lu] = %d ", i, j, elem);
            #else
            printf("%3d ", elem);
            #endif
        }

        printf("\n");
    }

    return 0;
}


int print_array(struct matrix input_matr)
{
    assert(input_matr.ptr != NULL);

    for (size_t i = 0; i <  input_matr.size_x; i++)
    {
        for (size_t j = 0; j < input_matr.size_y; j++)
        {
            int elem = *(input_matr.ptr + input_matr.size_y * i + j);

            #ifdef FULL_PRINT_MATRIX
            printf("data[%lu][%lu] = %d ", i, j, elem);
            #else
            printf("%4d ", elem);
            #endif
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


int *sum_arrays(size_t size_x, size_t size_y, int *data_1, int *data_2) // TODO: change name to matrix
{                                                                       // TODO: group into a structure
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

struct matrix mult_arrays(struct matrix matr_1,
                          struct matrix matr_2)
{
    assert(matr_1.ptr != NULL);
    assert(matr_2.ptr != NULL);
    assert(matr_2.size_x == matr_1.size_y);

    struct matrix ret_matr = {.size_x = matr_1.size_x,
                              .size_y = matr_2.size_y};

    if (matr_2.size_x != matr_1.size_y)
    {
        return ret_matr;
    }

    ret_matr.ptr = (int *) calloc(matr_1.size_x * matr_2.size_y, sizeof(int));

    if(ret_matr.ptr == NULL)
    {
        return ret_matr;
    }

    for (size_t i = 0; i < matr_1.size_x; i++)
    {
        for (size_t j = 0; j < matr_2.size_y; j++)
        {
            for (size_t k = 0; k < matr_1.size_y; k++)
            {
                ret_matr.ptr[i * matr_2.size_y + j]
                += matr_1.ptr[i * matr_1.size_y + k] * matr_2.ptr[k * matr_2.size_y + j];
            }
        }
    }

    return ret_matr;
}


int det_array(struct matrix input_matrix)
{
    assert(input_matrix.size_x == input_matrix.size_y);
    assert(input_matrix.ptr != NULL);

    int ret_det = 0;
    int *matr = input_matrix.ptr;
    size_t SIZE = input_matrix.size_x;

    if (SIZE == 1)
    {
        return input_matrix.ptr[0];
    }

    if (SIZE == 2)
    {
        ret_det = matr[3] * matr[0] - matr[1] * matr[2];

        return ret_det;
    }

    for (size_t i = 0; i<SIZE; i++)
    {
        if ((1 + i) % 2 == 0)
            ret_det -= matr[i] * minor_array(input_matrix, 0, i);
        else
            ret_det += matr[i] * minor_array(input_matrix, 0, i);
    }

    return ret_det;
}

int minor_array(struct matrix input_matrix, size_t min_i, size_t min_j)
{
    assert(input_matrix.ptr != NULL);
    assert(input_matrix.size_x == input_matrix.size_y);

    struct matrix minor_matrix = {};
    minor_matrix.size_x = input_matrix.size_x - 1;
    minor_matrix.size_y = input_matrix.size_y - 1;

    minor_matrix.ptr = (int *) calloc((input_matrix.size_x - 1) * (input_matrix.size_y - 1), sizeof(int));

    if (minor_matrix.ptr == NULL)
    {
        printf("Cant find memory to minor matrix :(");
        return 0;
    }

    bool is_i_added = false, is_j_added = false;

    for (size_t i = 0, i2 = 0; i < input_matrix.size_x - 1; i++, i2++)
    {
        for (size_t j = 0, j2 = 0; j < input_matrix.size_y - 1; j++, j2++)
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

            minor_matrix.ptr[i * (input_matrix.size_x - 1) + j] = input_matrix.ptr[i2 * input_matrix.size_x + j2];
        }

        is_j_added = false;
    }
    // printf("For array:\n");
    // print_array(matr, SIZE, SIZE);
    // printf("Printing minor matrix for i = %lu, j = %lu\n", min_i, min_j);
    // print_array(minor_matrix, SIZE - 1, SIZE - 1);
    // printf("\n\n");

    int ret_val = det_array(minor_matrix);

    free(minor_matrix.ptr);

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

struct matrix obr_matrix(struct matrix input_matrix)
{
    assert(input_matrix.size_x == input_matrix.size_y);
    assert(input_matrix.ptr != NULL);

    struct matrix ret_matr = {.size_x = input_matrix.size_x,
                              .size_y = input_matrix.size_y};

    if (input_matrix.size_x != input_matrix.size_y)
    {
        return ret_matr;
    }

    ret_matr.ptr = (int *) calloc(input_matrix.size_x * input_matrix.size_x, sizeof(int));

    if (ret_matr.ptr == NULL)
    {
        printf("Cant find memory for obr matrix");
        return ret_matr;
    }

    for (size_t i = 0; i < input_matrix.size_x; i++)
    {
        for (size_t j = 0; j < input_matrix.size_x; j++)
        {
            int minor_ij = minor_array(input_matrix, i, j);

            ret_matr.ptr[j * input_matrix.size_x + i] = alg_dop(i, j, minor_ij); // transponirovanie
        }
    }

    return ret_matr;
}


struct matrix input_matrix()
{
    struct matrix ret_matrix = {};
    ret_matrix.size_x = get_rows("рядов");
    ret_matrix.size_y = get_rows("столбцов");

    ret_matrix.ptr = (int *) calloc(ret_matrix.size_x * ret_matrix.size_y, sizeof(int));

    if (ret_matrix.ptr == NULL)
    {
        return ret_matrix;
    }

    for (size_t i = 0; i < ret_matrix.size_x; i++)
    {
        printf("Введите %lu чисел в строку №%lu:\n", ret_matrix.size_y, i);

        for (size_t j = 0; j < ret_matrix.size_y; j++)
        {
            scanf("%d", ret_matrix.ptr + i * ret_matrix.size_y + j);
        }
    }

    return ret_matrix;
}

struct ptr_array input_array()
{
    size_t matr_size_row = get_rows("рядов");

    struct ptr_array ptr_arr = {.size = matr_size_row};

    for (size_t i = 0; i < matr_size_row; i++)
    {
        size_t matr_size_col = get_rows("Столбцов");

        ptr_arr.ptr = (int *) calloc(matr_size_col, sizeof(int));

        printf("Введите %lu чисел в строку №%lu:\n", matr_size_col, i);
        for (size_t j = 0; j < matr_size_col; j++)
        {
            scanf("%d", &ptr_arr.ptr[j]);
        }
    }

    return ptr_arr;
}

size_t get_rows(const char par_name[])
{
    printf("Введите количество %s в матрице: ", par_name);
    size_t matr_size = 0;
    scanf("%lu", &matr_size);

    return matr_size;
}

