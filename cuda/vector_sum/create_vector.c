#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[]){

  if (argc != 3) {
        printf("Usage: %s <output_file> <dimensions>\n", argv[0]);
        return 1;
  }
  
  FILE* output_fp = fopen(argv[1], "w");
  if (output_fp == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }

  int dim = atoi(argv[2]);

  Vector *v = create_random_vector(dim);
  write_vector(output_fp, v);
  return 0;
}
