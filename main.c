#ifndef MATRIX
#include "matrix.h"
#endif


int main(void)
{
	printf("Enter row and columns of matrix1\n"
		"then enter row and columns of matrix2\n"
		"then enter values of both matrices.\n");
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

	int **matrix1 = FormMatrix(r1, c1);
	int **matrix2 = FormMatrix(r2, c2);

	fillMatrix(matrix1, r1, c1);
	fillMatrix(matrix2, r2, c2);

	printMatrix(AddM(matrix1, matrix2), r1, c1);
	printMatrix(SubtractM(matrix1, matrix2), r1, c1);
	printMatrix(MultiplyM(matrix1, matrix2), r1, c2);



	

	return 0;

}