#ifndef __cvector_h
#define __cvector_h

typedef struct { 
    unsigned max_capacity, size;
    int inner_array[0];
} vector;

enum sizes;

vector * init_vector(void);
vector * init_sized_vector(int size);
void free_vec(vector * v);
void vec_push_back(vector * v, int x);
void vec_pop_back(vector * v);
void vec_shrink_to_fit(vector * v);

#endif