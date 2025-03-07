#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n;
    FILE *file;
    
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <vector_size> <output_file>\n", argv[0]);
        return 1;
    }
    
    // Parse vector size
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Error: Vector size must be a positive integer.\n");
        return 1;
    }
    
    // Open output file
    file = fopen(argv[2], "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", argv[2]);
        return 1;
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Write vector sizes to file
    fprintf(file, "%d\n", n);
    
    // Generate and write first vector
    for (int i = 0; i < n; i++) {
        // Generate random float between 0 and 100
        float random_value = (float)rand() / RAND_MAX * 100.0;
        fprintf(file, "%.2f ", random_value);
    }
    fprintf(file, "\n");
    
    // Generate and write second vector
    for (int i = 0; i < n; i++) {
        // Generate random float between 0 and 100
        float random_value = (float)rand() / RAND_MAX * 100.0;
        fprintf(file, "%.2f ", random_value);
    }
    fprintf(file, "\n");
    
    // Close file
    fclose(file);
    
    printf("Successfully wrote two random vectors of length %d to %s\n", n, argv[2]);
    
    return 0;
}
