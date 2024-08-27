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

    int tr_arr[] =
    {
         1,
        -1,  0,
         0,  1, 1,
         1, -1, 0, 1
    };

    return EXIT_SUCCESS;
}
