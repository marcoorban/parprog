#include <stdio.h>
#include "vector.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <v1file> <v2file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* input_fp1  = fopen(argv[1], "r");
    if (input_fp1 == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    FILE* input_fp2  = fopen(argv[2], "r");
    if (input_fp2 == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        fclose(input_fp1);
        return 1;
    }

    FILE* output_fp = fopen(argv[3], "w");
    if (output_fp == NULL) {
        printf("Error opening file: %s\n", argv[3]);
        fclose(input_fp1);
        fclose(input_fp2);
        return 1;
    }

    Vector* v1 = read_vector(input_fp1);
    Vector* v2 = read_vector(input_fp2);
    if (v1 == NULL || v2 == NULL) {
        printf("Error reading vectors from file.\n");
        if (v1 != NULL) free_vector(v1);
        if (v2 != NULL) free_vector(v2);
        fclose(input_fp1);
        fclose(input_fp2);
        fclose(output_fp);
      }
}
