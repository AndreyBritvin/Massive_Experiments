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
        puts("");
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
            puts("");
            ar_pr++;
        }
    }
    puts("");

    return 0;
}
