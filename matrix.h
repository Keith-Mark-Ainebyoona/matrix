#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>

extern int r1, r2, c1, c2;
int** FormMatrix(int, int);
void fillMatrix(int **, int, int);
void printMatrix(int **, int, int);
int ** AddM(int **M1, int **M2);
int ** SubtractM(int **M1, int **M2);
int ** MultiplyM(int **M1, int **M2);
double Determinant(int** M1, int , int);
double Det(int** matrix);
int** CofactorMatrix(int** matrix, int r, int c);

#endif
