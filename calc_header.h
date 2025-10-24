#ifndef CALC_HEADER_H
#define CALC_HEADER_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR_SCREEN() system("cls")
#else
    #define CLEAR_SCREEN() system("clear")
#endif

struct two{
	int x;
	int y;
};

int dclr2d(int ***ptr, int rows, int cols);
int free2d(int **ptr, int rows);

int detF(int **ptr, int size);
int minorF(int **ptr, int size, int x, int y);
int cofacF(int **ptr, int size, int x, int y);

void fractD(int x, int y, int dNmax, int dDmax);
int gcdF(int x, int y);
struct two fractF(int x, int y);
int digitsF(int x);

int in2d(int **ptr, int rows, int cols);
int copy2d(int **ptr1, int **ptr2, int rows, int cols);
int readNum(int *num);
int readFrac(int *n, int *d);
int readSize(int *n, int *d);
int out2d(int **ptr, int rows, int cols);
int out2dFrac(int **ptr, int denom, int rows, int cols);
int maxF(int **ptr, int rows, int cols);

int addF(int **ptrA, int **ptrB, int **ptrC, int rows, int cols);
int subF(int **ptrA, int **ptrB, int **ptrC, int rows, int cols);

int intScalarF(int **ptr, int **ptrS, int s, int rows, int cols);
int multiF(int **ptrA, int **ptrB, int **ptrC, int rowsA, int colsA, int colsB);
int intNaturalPowerF(int **ptr, int **ptrP, int p, int size);

int minorMatrixF(int **ptr, int **ptrM, int size);
int cofacMatrixF(int **ptr, int **ptrC, int size);
int transMatrixF(int **ptr, int **ptrT, int rows, int cols);
int inverseMatrixD(int **ptr, int size);
int scalarD(int **ptr, int n, int d, int rows, int cols);
int intPowerD(int **ptr, int p, int size);

#endif
