#include "matrix.h"

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

void freeMemory(int** m, int r)
{
    if (m)
    {
        for (int i = 0; i < r; ++i)
        {
            if (m[i])
            {
                free(m[i]);
            }
        }

        free(m);
    }
}

void printMatrix(int **M, int r, int c)
{
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


void AddM(int **M1, int **M2)
{
    if(r1 == r2 && c1 == c2)
    {
        printf("\nAddition success:-)\nPrinting Result...\n");

        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                printf("%d  ",M1[i][j] + M2[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nCannot add these matrices :-(\n");
    }
    
}

void SubtractM(int** M1, int** M2)
{
    if (r1 == r2 && c1 == c2)
    {
        printf("\nSubtraction success:-)\nPrinting Result...\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                printf("%d  ", M1[i][j] - M2[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nCannot subtract these matrices :-(\n");
    }
}

void MultiplyM(int **M1, int **M2)
{
    if(c1 == r2)
    {
        printf("\nMultiplication success:-)\nResult...\n");
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
        printMatrix(result, r1, c2);
        //freeing memory
        freeMemory(result, r1);
    }
    else
    {
        printf("\nCannot multiply these matrices :-(\n");
    }
}

int** Cofactors(int** matrix, int r, int c)
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
    double det = 0;
    if (r1 != c1)
    {
        printf("\nThe determinant of this matrix can not be determined :-(\n");
        return detERROR;
    }
    if (r1 == 2)
    {
        return Det(M1);
    }
    else
    {
        int hmm = 0;
        int** cfs = Cofactors(M1, r1, c1); //unfreed memory
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
            int** m = FormMatrix(r1 - hmm, c1 - hmm); //unfreed memory
            for (int f = 0; f < r1 - hmm; f++)
            {
                for (int g = 0; g < c1 - hmm; g++)
                {
                    fscanf(fpr, "%d", &m[f][g]);
                }
            }
            fclose(fpr);
            det += M1[0][i] * cfs[0][i] * Determinant(m, r1 - hmm, c1 - hmm);
            freeMemory(m,r1-hmm);
        }
        remove("temp.txt");
        freeMemory(cfs,r1);
        return det;

    }
}

int IsEqual(int** m1, int** m2)
{
    if (r1 == r2 && c1 == c2)
    {
        for (int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
            {
                if (m1[i][j] != m2[i][j])
                {
                    return 0;
                }
                
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

void IdentityMatrix(int r, int c)
{
    int** m = FormMatrix(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
            {
                m[i][j] = 1;
            }
            else
            {
                m[i][j] = 0;
            }
        }
    }
    printMatrix(m, r, c);
    freeMemory(m, r);
}

void Transpose(int** m, int r, int c)
{
    int** tm = FormMatrix(c, r);
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            tm[i][j] = m[j][i];
        }
    }
    printMatrix(tm, c, r);
    freeMemory(tm, c);
}

void MultiplyS(int** m, int r, int c, int scalar)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d  ",scalar * m[i][j]);
        }
        printf("\n");
    }
}
