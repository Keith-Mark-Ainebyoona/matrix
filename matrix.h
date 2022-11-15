#ifndef MATRIX_H
#define MATRIX_H
#define detERROR -10000000 //hopefully, no matrix has this as its determinant.

#include <stdio.h>
#include <stdlib.h>

extern int r1, r2, c1, c2;
int** FormMatrix(int, int);
void fillMatrix(int **, int, int);
void printMatrix(int **, int, int);
void AddM(int **M1, int **M2);
void SubtractM(int **M1, int **M2);
void MultiplyM(int **M1, int **M2);
double Determinant(int** M1, int , int);
double Det(int** matrix);
int** Cofactors(int** matrix, int r, int c);
int IsEqual(int**, int**);
void IdentityMatrix(int, int);
void Transpose(int**, int, int);
void MultiplyS(int**, int, int, int);
void freeMemory(int** m, int r);

#endif
