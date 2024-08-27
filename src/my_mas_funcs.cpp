#include "my_mas_funcs.h"

int print_array(int *data, size_t x, size_t y)
{
    assert(data != NULL);

    for(size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            int elem = *(data + y * i + j);

            printf("data[%lu][%lu] = %d ", i, j, elem);
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
