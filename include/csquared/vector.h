#pragma once

#define VECTOR_INIT_CAPACITY 6
#define UNDEFINE -1
#define SUCCESS 0

typedef struct
{
	void **items;
	int capacity;
	int total;
} vector_list_t;

typedef struct vector vector_t;
struct vector
{
	vector_list_t vector_list;
	int (*vector_total)(vector_t *);
	int (*vector_resize)(vector_t *, int);
	int (*vector_add)(vector_t *, void *);
	int (*vector_set)(vector_t *, int, void *);
	void *(*vector_get)(vector_t *, int);
	int (*vector_delete)(vector_t *, int);
	int (*vector_free)(vector_t *);
};

void vector_create(vector_t *vector);
int vector_total(vector_t *vector);
int vector_resize(vector_t *vector, int capacity);
int vector_pushback(vector_t *vector, void *item);
int vector_set(vector_t *vector, int index, void *item);
void *vector_get(vector_t *vector, int index);
int vector_delete(vector_t *vector, int index);
int vector_free(vector_t *vector);