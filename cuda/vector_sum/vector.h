#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
	int size;
	double *components;
} Vector;

Vector* read_vector(FILE* fp);
Vector* add_vectors(Vector* v1, Vector* v2);
Vector* create_random_vector(int n);
void free_vector(Vector *v);
void write_vector(FILE* fp, Vector* v);

#endif 

