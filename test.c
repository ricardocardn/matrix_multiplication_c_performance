#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "matrixOperations.h"

int n;

/**
 * @brief Function that benchmarks the matrix multiplication
 * 		function and returns the number of operations per ms
 * 		and elapsed time.
 * 
 * @param[in] iter Number of iterations
 * @param[in] a First matrix
 * @param[in] b Second matrix
 * @param[in] n Size of the matrices
 * @return Pointer to the matrix
 */
int benchmarkMultiplication(int iter, int** a, int** b, int n) {
    clock_t start_time = clock();
    for (int i = 0; i < iter; i++) {
        free(matrixMultiplication(a, b, n));
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double ops_per_ms = (iter / elapsed_time) / 1000.0;

	printf("Iterations: %d\n", iter);
    printf("Ops/ms: %.2f\n", ops_per_ms);
	printf("Elapsed time: %.2f\n", elapsed_time/iter);
}


/**
 * @brief Main function
 * 
 * Function that generates two square matrices of size n,
 * amd measures the time taken to multiply their blocks of
 * sizes of different powers of 2 between 1 and n.
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments
 * @return 0 if the program ends correctly, -1 otherwise
 */
int main(int argc, char *argv[]) {
	if (argc < 2) {return -1;}

	n = atoi(argv[1]);

	// Matrix Inicialization
	int** a = randSquareMatrix(n);
	int** b = randSquareMatrix(n);
	
	for (int i=1; i<=n; i=i*2) {
		printf("Orden de las matrices: %d\n", i);
		benchmarkMultiplication(100000, a, b, i);
		printf("\n");
    }

	free(a);
	free(b);

	return 0;
}