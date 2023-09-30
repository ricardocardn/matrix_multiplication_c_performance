#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "matrixOperations.h"

/**
 * @brief Definition of a square matrix
 * 
 * Function that defines a square matrix of size n
 * with nxn random integer numbers between 0 and 99.
 * 
 * @return Square matrix of size n
 */
int** randSquareMatrix(int n) {
	int** matrix = (int**)malloc(n * sizeof(int*));

	for (int i=0; i<n; i++) {
		matrix[i] = (int*)malloc(n * sizeof(int));
		for (int j=0; j<n; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

	return matrix;
}


/**
 * @brief  Multiplicación de matrices
 * 
 * Function that multiplies two square matrices of size n,
 * where n is an integer number.
 * 
 * @param[in] a Square matrix of size n
 * @param[in] b Square matrix of size n
 * @param[in] size Size of the matrices
 * @return Time taken to multiply the matrices
 */
int** matrixMultiplication(int** a, int** b, int size) {
	int** c = (int**)malloc(size * sizeof(int*));

	for (int i=0; i<size; i++) {
		c[i] = (int*)malloc(size * sizeof(int));
		for (int j=0; j<size; j++) {
			c[i][j] = 0;

			for (int k=0; k<size; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j];			
			}
		}
	}

	return c;
}