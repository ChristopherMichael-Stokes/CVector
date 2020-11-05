#ifndef __cvector_h
#define __cvector_h

typedef struct { 
    size_t max_capacity, size;
    int inner_array[0];
} vector;

enum sizes;

vector * init_vector(void);
vector * init_sized_vector(int size);
void free_vec(vector * v);
void vec_push_back(vector * v, int x);
void vec_pop_back(vector * v);
void vec_shrink_to_fit(vector * v);
void print_vec(vector * v);

// functions for elementwise vector arithmetic
vector * vec_add(vector * v1, vector * v2);
vector * vec_multiply(vector * v1, vector * v2);
vector * vec_subtract(vector * v1, vector * v2);
vector * vec_divide(vector * v1, vector * v2);


#endif
