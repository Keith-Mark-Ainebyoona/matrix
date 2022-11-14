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

	printMatrix(matrix1, r1, c1);
	printMatrix(matrix2, r2, c2);

	printMatrix(AddM(matrix1, matrix2), r1, c1);
	printMatrix(SubtractM(matrix1, matrix2), r1, c1);
	printMatrix(MultiplyM(matrix1, matrix2), r1, c2);

	printf("\nDeterminant of matrix 1 is : %.2lf\n", Determinant(matrix1, r1, c1));
	printf("\nDeterminant of matrix 2 is : %.2lf\n", Determinant(matrix2, r2, c2));


	

	return 0;

}