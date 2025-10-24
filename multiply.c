#include "calc_header.h"

int intScalarF(int **ptr, int **ptrS, int s, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			*(*(ptrS + i) + j) = *(*(ptr + i) + j) * s;
		}
	}
	
	return 0;
}

int multiF(int **ptrA, int **ptrB, int **ptrC, int rowsA, int colsA, int colsB)
{
	int rowsB = colsA, i, j, k;
	
	for(i = 0; i < rowsA; i++){
		for(j = 0; j < colsB; j++){
			*(*(ptrC + i) + j) = 0;
			
			for(k = 0; k < colsA; k++){
				*(*(ptrC + i) + j) += *(*(ptrA + i) + k) * *(*(ptrB + k) + j);
			}
		}
	}
	
	return 0;
}

int intNaturalPowerF(int **ptr, int **ptrP, int p, int size)
{
	int i, j, k, **ptr2;
	
	if(p < 0){
		printf("\tintNaturalPowerF requires non negative power.\n");
		exit(1);
		return 1;  //not required
	}
	
	if(p == 0){
		for(i = 0; i < size; i++){
			for(j = 0; j < size; j++){
				if(i == j){
					*(*(ptrP + i) + j) = 1;
				}
				else{
					*(*(ptrP + i) + j) = 0;
				}
			}
		}
		
		return 0;
	}
	
	dclr2d(&ptr2, size, size);
	
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			*(*(ptr2 + i) + j) = *(*(ptr + i) + j);
			*(*(ptrP + i) + j) = *(*(ptr + i) + j);
		}
	}
	
	for(i = 0; i < p - 1; i++){
		multiF(ptr, ptr2, ptrP, size, size, size);
		
		for(j = 0; j < size; j++){
			for(k = 0; k < size; k++){
				*(*(ptr + j) + k) = *(*(ptrP + j) + k);
			}
		}
	}
	
	free2d(ptr2, size);
	
	return 0;
}
