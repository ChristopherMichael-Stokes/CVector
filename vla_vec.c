#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cvector.h"

//extensible integer array type, using variable length
//array, and reallocating entire struct when needed
//hence variableLengthArray_vector

enum sizes { INITIAL_SIZE=5 };

vector * _init_vector(int size)
{
    vector * v = malloc(sizeof(int)*size + sizeof(vector));
    v->max_capacity = size;
    v->size = 0;
    return v;
}

vector * init_vector(void) 
{
    vector * v;
    assert((v=_init_vector(INITIAL_SIZE)) != NULL);
    return v;
}

vector * init_sized_vector(int size)
{
    vector * v;
    assert((v=_init_vector(size)) != NULL);
    return v;
}

void free_vec(vector * v)
{
    free(v);
}

void vec_push_back(vector * v, int x) 
{
    if (v->size == v->max_capacity) {

        /* basic implementation
        //make a duplicate array, with double the size of v
        vector * copy = init_sized_vector(v->size*2); 
        for (int i = 0; i < v->size; ++i)
            copy->inner_array[i] = v->inner_array[i];
        copy->size = v->size;
        *v = *copy;
        free_vec(copy);
        */

        //better implementation using realloc
        assert((v = realloc(v, sizeof(int)*(v->max_capacity*=2) +
                sizeof(vector))) != NULL);

    }
    v->inner_array[v->size++] = x;
}

void vec_pop_back(vector * v)
{
    if (v->size > 0)
        v->size--;
}

//costly as it makes a new vector, only use where memory is 
//limited
void vec_shrink_to_fit(vector * v)
{
    if (!(v->size == v->max_capacity)) {
        assert((v = realloc(v, sizeof(int)*(v->max_capacity=v->size) +
                sizeof(vector))) != NULL);
    }
}