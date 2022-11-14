#include "matrix.h"
#include <math.h>

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

int** CofactorMatrix(int** matrix, int r, int c)
{
    int** m = FormMatrix(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            m[i][j] = pow(-1, (i + j));
        }
    }
    return m;
}

double Det(int** M1)
{
    return (M1[0][0] * M1[1][1]) - (M1[0][1] * M1[1][0]);
}

double Determinant(int** M1, int r1, int c1)
{
    //0 isn't a worthy condition, coming up with something worthy
    double det = 0;
    if (r1 != c1)
    {
        printf("\nThe determinant of this matrix can not be determined :-(\n");
        return det;
    }
    if (r1 == 2)
    {
        return Det(M1);
    }
    else
    {

        int hmm = 0;
        int** cfm = CofactorMatrix(M1, r1, c1);
        //printMatrix(cfm,r1, c1); //was for debugging purposes :-)
        hmm++;
        for (int i = 0; i < r1; i++)
        {
            FILE* fp = fopen("temp.txt", "w");
            for (int x = 0; x < r1; x++)
            {
                if (x == 0)
                {
                    continue;
                }
                for (int y = 0; y < c1; y++)
                {
                    if (y == i)
                    {
                        continue;
                    }
                    fprintf(fp, "%d ", M1[x][y]);
                }
            }
            fclose(fp);
            FILE* fpr = fopen("temp.txt", "r");
            int** m = FormMatrix(r1 - hmm, c1 - hmm);
            for (int f = 0; f < r1 - hmm; f++)
            {
                for (int g = 0; g < c1 - hmm; g++)
                {
                    fscanf(fpr, "%d", &m[f][g]);
                }
            }
            fclose(fpr);

            det += M1[0][i] * cfm[0][i] * Determinant(m, r1 - hmm, c1 - hmm);
        }
        remove("temp.txt");
        return det;

    }
}
