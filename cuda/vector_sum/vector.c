#include "vector.h"


/* Reads an n-dimensional vector from a file */
Vector* read_vector(FILE* fp) {
  Vector* v = (Vector*)malloc(sizeof(Vector));
  if (fscanf(fp, "%d", &v->size) != 1){
   free(v);
  return NULL;
  }
  v->components = (double*)malloc(v->size * sizeof(double));
  for (int i = 0; i < v->size; i++){
    // check that the each line is a valid component
    // (only contains one double
    if (fscanf(fp, "%lf", &v->components[i]) != 1){
      free(v->components);
      free(v);
      return NULL;
    }
  }
  return v;
}

/* Adds two n dimensional vectors. The vectors should already be in memory. Therefore, the vectors
 * should be created, or be read using the read_vector function */
Vector* add_vectors(Vector* v1, Vector* v2) {
  if (v1->size != v2->size) {
    printf("Vectors not the same size!");
    return NULL;
  }
  Vector* result = (Vector*)malloc(sizeof(Vector));
  result->size = v1->size;
  result->components = (double*)malloc(result->size * sizeof(double));
  for (int i = 0; i < result->size; i++) {
    result->components[i] = v1->components[i] + v2->components[i];
  }
  return result;
}

/* Creates a random n-dimensional vector. The vector is stored in memory but it not necessarily saved permanently.
 * To save the vector for posterity, use the write_vector method */
Vector* create_random_vector(int n){
  srand(time(NULL)); 
  Vector* v = (Vector*)malloc(sizeof(Vector));
  v->size = n;
  v->components = (double*)malloc(n * sizeof(double));
  for (int i = 0; i < n; i++){
    v->components[i] = (double)rand() / RAND_MAX * 10.0; // Generate a random number between 0 and 10
  }
  return v;
}

/* Frees vector from memory */
void free_vector(Vector* v) {
  free(v->components);
  free(v);
}

/* Writes a vector to a file for later use. */
void write_vector(FILE* fp, Vector* v) {
  fprintf(fp, "%d\n", v->size);
  for (int i = 0; i < v->size; i++) {
    fprintf(fp, "%f\n", v->components[i]);
  }
}
