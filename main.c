#include <stdio.h>
#include <stdlib.h>
#include "cvector.h"

int main(void)
{
    vector * v = init_vector();
    for (int i = 0; i < 11; ++i)
        vec_push_back(v, i);
    for (int i = 0; i < v->size; ++i)
        printf("%d\t", v->inner_array[i]);
    putchar('\n');
    printf("%d\n",v->max_capacity);
    printf("%d\n",v->size);
    return 0;
}