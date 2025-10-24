#include "calc_header.h"

int dclr2d(int ***ptr, int rows, int cols)
{
	int i, j;
	
	*ptr = malloc(rows * sizeof(int*));
	
	if(*ptr == NULL){
		printf("\tMemory Allocation Failed, 1st Layer.\n");
		exit(1);
		return 1;  //not required
	}
	
	for(i = 0; i < rows; i++){
		*(*ptr + i) = malloc(cols * sizeof(int));
		
		if(*(*ptr + i) == NULL){
			for(j = 0; j < i; j++){
				free(*(*ptr + j));
			}
			
			free(*ptr);
			
			printf("\tMemory Allocation Failed, 2nd Layer - Index: %d.\n", i);
			exit(1);
			return 2;  //not required
		}
	}
	
	return 0;	
}

int free2d(int **ptr, int rows)
{
	int i;
	
	for(i = 0; i < rows; i++){
		free(*(ptr + i));
	}
	
	free(ptr);
	
	return 0;
}
