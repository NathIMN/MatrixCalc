#include "calc_header.h"

int minorMatrixF(int **ptr, int **ptrM, int size)
{
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			*(*(ptrM + i) + j) = minorF(ptr, size, i, j);
		}
	}
	
	return 0;
}

int cofacMatrixF(int **ptr, int **ptrC, int size)
{
	int i, j;
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			*(*(ptrC + i) + j) = cofacF(ptr, size, i, j);
		}
	}
	
	return 0;
}

int transMatrixF(int **ptr, int **ptrT, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < cols; i++){
		for(j = 0; j < rows; j++){
			*(*(ptrT + i) + j) = *(*(ptr + j) + i);
		}
	}
	
	return 0;
}

int inverseMatrixD(int **ptr, int size)  //check return for non existent  //displays still stupid
{
	int **ptrI, i, j, det;
	
	dclr2d(&ptrI, size, size);
	
	det = detF(ptr, size);
	
	if(det == 0){
		return 1;
	}
	
	if(cofacMatrixF(ptr, ptrI, size) != 0){
		exit(1);
		return 1;  //not required
	}
	
	copy2d(ptrI, ptr, size, size);
	
	transMatrixF(ptr, ptrI, size, size);
	
	out2dFrac(ptrI, det, size, size);
	
	free2d(ptrI, size);
	
	return 0;
}

int scalarD(int **ptr, int n, int d, int rows, int cols)
{
	int **ptrS, i, j;
	
	dclr2d(&ptrS, rows, cols);
	
	if(intScalarF(ptr, ptrS, n, rows, cols) != 0){
		exit(1);
		return 1;  //not required
	}
	
	out2dFrac(ptrS, d, rows, cols);
	
	free2d(ptrS, rows);
	
	return 0;
}

int intPowerD(int **ptr, int p, int size)
{
	int **ptrP, i, j, power;
	
	dclr2d(&ptrP, size, size);
	
	power = p < 0 ? -p : p;
	
	if(intNaturalPowerF(ptr, ptrP, power, size) != 0){
		exit(1);
		return 1;  //not required
	}
	
	if(p >= 0){
		out2d(ptrP, size, size);
	}
	else{
		if(inverseMatrixD(ptrP, size) != 0){
			printf("\tThe Input Matrix Can't be Raised to the Power of %d.\n", p);
		}
	}
	
	free2d(ptrP, size);
	
	return 0;
}
