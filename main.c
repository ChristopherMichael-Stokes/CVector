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
    printf("capacity: %d\n",v->max_capacity);
    printf("size: %d\n",v->size);
    vec_shrink_to_fit(v);
    printf("capacity: %d\n",v->max_capacity);
    printf("size: %d\n",v->size);
    return 0;
}