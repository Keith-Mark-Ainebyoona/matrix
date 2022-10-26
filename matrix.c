#ifndef MATRIX
#include "matrix.h"
#endif

int r1, r2, c1, c2;

int** FormMatrix(int r1, int c1)
{
    int **Matrix = (int **)malloc(r1 * sizeof(int *));
    for(int i = 0; i < r1; i++)
	{
        Matrix[i] = (int *)calloc(c1, sizeof(int));	
	}
    return Matrix;
}

void fillMatrix(int **M, int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
}

void printMatrix(int **M, int r, int c)
{
    printf("Matrix:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ** AddM(int **M1, int **M2)
{
    if(r1 == r2 && c1 == c2)
    {
        int **result = FormMatrix(r1, c1);

        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                result[i][j] = M1[i][j] + M2[i][j];
            }
        }
        printf("\nAddition success:-)\nPrinting Result...\n");
        return result;
    }
    else
    {
        printf("\nCannot add these matrices :-(\n"
            "Printing matrix1...\n");
        return M1;
    }
    
}

int ** SubtractM(int **M1, int **M2)
{
    if(r1 == r2 && c1 == c2)
    {
        int **result = FormMatrix(r1, c1);

        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                result[i][j] = M1[i][j] - M2[i][j];
            }
        }
        printf("\nSubtraction success:-)\nPrinting Result...\n");
        return result;
    }
    else
    {
        printf("\nCannot subtract these matrices :-(\n"
            "Printing matrix1...\n");
        return M1;
    }
}

int ** MultiplyM(int **M1, int **M2)
{
    if(c1 == r2)
    {
        int **result = FormMatrix(r1, c2);
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c2; j++)
            {
                for(int y = 0; y < r2; y++)
                {
                    result[i][j] += M1[i][y] * M2[y][j];  
                }
            }
        }
        printf("\nMultiplication success:-)\nPrinting Result...\n");
        return result;

    }
    else
    {
        printf("\nCannot multiply these matrices :-(\n"
            "Printing matrix1...\n");
        return M1;
    }
}

