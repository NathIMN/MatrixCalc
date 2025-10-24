#include "calc_header.h"

int addF(int **ptrA, int **ptrB, int **ptrC, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			*(*(ptrC + i) + j) = *(*(ptrA + i) + j) + *(*(ptrB + i) + j);
		}
	}
	
	return 0;
}

int subF(int **ptrA, int **ptrB, int **ptrC, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			*(*(ptrC + i) + j) = *(*(ptrA + i) + j) - *(*(ptrB + i) + j);
		}
	}
	
	return 0;
}
