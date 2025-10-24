#include "calc_header.h"

int detF(int **ptr, int size)  //minimum size of 1  //validate check here, nvm exit 
{							   //pass a pointer from main to cofac and use return for status instead??
	int det = 0, j;
	
	if(size < 1){
		printf("\tdetF requires a positive size\n");
		exit(1);
		return 1;  //not necessary
	}
	
	if(size == 1){
		det = *(*(ptr + 0) + 0);
	}
	else if(size == 2){
		det = (*(*(ptr + 0) + 0) * *(*(ptr + 1) + 1)) - (*(*(ptr + 0) + 1) * *(*(ptr + 1) + 0));
	}
	else{
		for(j = 0; j < size; j++){
			det += *(*(ptr + 0) + j) * cofacF(ptr, size, 0, j);
		}
	}
	
	return det;
}

int minorF(int **ptr, int size, int x, int y)
{
	int minor, check, **arr, i, j, k = 0, l;
	
	if(size < 2){
		printf("\tminorF requires a size not lower than 2\n");
		exit(1);
		return 1;  //not necessary
	}
	
	if((check = dclr2d(&arr, size - 1, size - 1)) != 0){
		printf("\tMemory Allocation Failure inside minorF function, check = %d\n", check);
		exit(1);
		return check;  //not necessary
	}
		
	for(i = 0; i < size; i++){
		if(i != x){
			l = 0;
			for(j = 0; j < size; j++){
				if(j != y){
					*(*(arr + k) + l) = *(*(ptr + i) + j);
					l++;
				}
			}
			k++;
		}
	}  //fkin dryrun
	
	minor = detF(arr, size - 1);
	
	free2d(arr, x);
	
	return minor;
}

int cofacF(int **ptr, int size, int x, int y)  //minimum size of 2
{
	int cofac, check, **arr, i, j, k = 0, l;
	
	if(size < 2){
		printf("\tcofacF requires a size not lower than 2\n");
		exit(1);
		return 1;  //not necessary
	}
	
	if((check = dclr2d(&arr, size - 1, size - 1)) != 0){
		printf("\tMemory Allocation Failure inside cofacF function, check = %d\n", check);
		exit(1);
		return check;  //not necessary
	}
		
	for(i = 0; i < size; i++){
		if(i != x){
			l = 0;
			for(j = 0; j < size; j++){
				if(j != y){
					*(*(arr + k) + l) = *(*(ptr + i) + j);
					l++;
				}
			}
			k++;
		}
	}  //fkin dryrun
	
	cofac = detF(arr, size - 1);
	
	if((x + y) % 2 != 0){
		cofac = -cofac;
	}
	
	free2d(arr, x);
	
	return cofac;
}
