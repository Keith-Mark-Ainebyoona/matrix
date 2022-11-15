#include "matrix.h"

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

	printf("\nMatrix1:\n");
	printMatrix(matrix1, r1, c1);
	printf("\nMatrix2:\n");
	printMatrix(matrix2, r2, c2);

	AddM(matrix1, matrix2);
	SubtractM(matrix1, matrix2);
	MultiplyM(matrix1, matrix2);

	int det1 = Determinant(matrix1, r1, c1);
	if (det1 != detERROR)
	{
		printf("\nDeterminant of matrix 1 is : %.2lf\n", det1);
	}
	int det2 = Determinant(matrix2, r2, c2);
	if (det2 != detERROR)
	{
		printf("\nDeterminant of matrix 2 is : %.2lf\n", det2);
	}

	if (IsEqual(matrix1, matrix2))
	{
		printf("\nThe matrices are equal.\n");
	}
	else
	{
		printf("\nThe matrices are NOT equal.\n");
	}

	printf("\nTranspose of matrix1:\n");
	Transpose(matrix1, r1, c1);

	printf("\nTranspose of matrix2:\n");
	Transpose(matrix2, r2, c2);
	
	printf("\n\n");
	IdentityMatrix(r1, c1);

	printf("\n\nmultiplying matrix1 by a 5 (scalar)\n");
	MultiplyS(matrix1, r1, c1, 5);

	freeMemory(matrix1, r1);
	freeMemory(matrix2, r2);
	
	return 0;

}