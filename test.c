#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "matrixOperations.h"

int n;
struct timeval start, stop;

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
	printf("Orden de las matrices: %d\n", n);

	// Matrix Inicialization
	int** a = randSquareMatrix(n);
	int** b = randSquareMatrix(n);
	
	for (int i=1; i<=n; i=i*2) {

        printf("Tamano de bloque: %d\n", i);
		gettimeofday(&start, NULL);			// Time measurement opening

        int** c = matrixMultiplication(a, b, i);

		gettimeofday(&stop, NULL);			// Time measurement closing
		free(c);

		double time = stop.tv_sec - start.tv_sec;
		time = time + 1e-6*(stop.tv_usec - start.tv_usec);

        printf("Tiempo de ejecucion: %f (seconds)\n\n", time);		
    }

	fprintf(f, "]\n");
	fclose(f);

	free(a);
	free(b);

	return 0;
}