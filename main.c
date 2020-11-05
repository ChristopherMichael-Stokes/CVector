#include <stdio.h>
#include <stdlib.h>
#include "cvector.h"

int main(void)
{
    printf("######################################\n"
           "Testing basic functionality\n"
           "######################################\n");

    vector * v = init_vector();
    for (int i = 0; i < 11; ++i) {
	// TODO fix push_back
        vec_push_back(v, i);
    }
    print_vec(v);
    printf("capacity: %lu\n",v->max_capacity);
    printf("size: %lu\n",v->size);
    vec_shrink_to_fit(v);
    printf("capacity: %lu\n",v->max_capacity);
    printf("size: %lu\n",v->size);
    free_vec(v);

    printf("######################################\n"
           "Testing arithmetic\n"
           "######################################\n");
    // test two equally sized vectors
    size_t vec_len = 10;
    vector * v1 = init_sized_vector(vec_len);
    vector * v2 = init_sized_vector(vec_len);
    for (int i = 0; i < vec_len; ++i) {
	    v1->inner_array[i] = i+1;
	    v2->inner_array[i] = (i+1)*2;
    }
    printf("v1:\t ");
    print_vec(v1);
    printf("v2:\t ");
    print_vec(v2);
    vector * v3 = vec_add(v1, v2);
    printf("v1 + v2: ");
    print_vec(v3); free_vec(v3);

    v3 = vec_multiply(v1, v2);
    printf("v1 * v2: ");
    print_vec(v3); free_vec(v3);

    v3 = vec_subtract(v1, v2);
    printf("v1 - v2: ");
    print_vec(v3); free_vec(v3);

    v3 = vec_divide(v2, v1);
    printf("v2 / v1: ");
    print_vec(v3); free_vec(v3);

    free_vec(v1); free_vec(v2);

    return 0;
}
