#include "calc_header.h"

int in2d(int **ptr, int rows, int cols)
{
	int i, j, ch;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("\tEnter Element [%d,%d] : ", i + 1, j + 1);
			
			if(scanf("%d", *(ptr + i) + j) != 1){
				printf("\tInvalid Input, Enter Again.\n");
				j--;
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			
			if((ch = getchar()) != '\n' && ch != EOF){
				if(ch != ' '){
					printf("\tInvalid Input, Enter Again.\n");
					j--;
				}
				while((ch = getchar()) != '\n' && ch != EOF);
			}
		}
	}
	
	return 0;
}

int copy2d(int **ptr1, int **ptr2, int rows, int cols)
{
	int i, j;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			*(*(ptr2 + i) + j) = *(*(ptr1 + i) + j);
		}
	}
	
	return 0;
}

int readNum(int *num)
{
	int ch;
	
	while(1){
		if(scanf("%d", num) != 1){
			printf("\tInvalid Input, Enter Again: ");
			while((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		
		if((ch = getchar()) != '\n' && ch != EOF){
			if(ch != ' '){
				printf("\tInvalid Input, Enter Again: ");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			while((ch = getchar()) != '\n' && ch != EOF);
		}
		
		break;
	}
	
	return 0;
}

int readFrac(int *n, int *d)
{
	int ch, count;
	
	while(1){
		count = 0;
		
		if(scanf("%d", n) != 1){
			printf("\tInvalid Input, Enter Again: ");
			while((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		
		count++;
		
		if((ch = getchar()) != '\n' && ch != EOF){
			if(ch != ' ' && ch != '\t' && ch != '/'){
				printf("\tInvalid Input, Enter Again: ");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
		}
		else{
			break;
		}
		
		while(ch == ' ' || ch == '\t'){
			ch = getchar();
		}
		
		if(ch != '/'){
			break;
		}
		else{
			if(scanf("%d", d) != 1){
				printf("\tInvalid Input, Enter Again: ");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;	
			}
			
			count++;
			
			if((ch = getchar()) != '\n' && ch != EOF){
				if(ch != ' ' && ch != '\t'){
					printf("\tInvalid Input, Enter Again: ");
					while((ch = getchar()) != '\n' && ch != EOF);
					continue;
				}
				while((ch = getchar()) != '\n' && ch != EOF);
			}
			
			break;
		}
	}
	
	if(count == 1){
		*d = 1;
	}
	
	return count;
}

int readSize(int *r, int *c)
{
	int ch;
	
	while(1){
		if(scanf("%d", r) != 1){
			printf("\tInvalid Input, Enter Again: ");
			while((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		
		while((ch = getchar()) == ' ' || ch == '\t');
		
		if(ch == '\n' || ch == EOF){
			printf("\tInvalid Input, Enter Again: ");
			continue;
		}
		
		if(ch != 'x' && ch != 'X' && ch != '*'){
			printf("\tInvalid Input, Enter Again: ");
			while((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		else{
			if(scanf("%d", c) != 1){
				printf("\tInvalid Input, Enter Again: ");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			
			if((ch = getchar()) != '\n' && ch != EOF){
				if(ch != ' ' && ch != '\t'){
					printf("\tInvalid Input, Enter Again: ");
					while((ch = getchar()) != '\n' && ch != EOF);
					continue;
				}
				while((ch = getchar()) != '\n' && ch != EOF);
			}
		}
		
		if(*r < 1 || *c < 1){
			printf("\tA Matrix must have Positive Dimensions, Enter Again: ");
			continue;
		}
		
		break;
	}
	
	return 0;
}

int out2d(int **ptr, int rows, int cols)
{
	int i, j, max, d;
	
	max = maxF(ptr, rows, cols);
	
	d = digitsF(max) + 1;  //+1 for the sign or space
	
	for(i = 0; i < rows; i++){
		printf("\t\t");
		
		for(j = 0; j < cols; j++){
			printf("%*d ", d, *(*(ptr + i) + j));
		}
		
		printf("\n");
	}
	
	return 0;
}

int out2dFrac(int **ptr, int denom, int rows, int cols)
{
	struct two fract;
	int i, j, dN, dD, dNmax = 0, dDmax = 0;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			fract = fractF(*(*(ptr + i) + j), denom);
			
			dN = digitsF(fract.x);
			dD = digitsF(fract.y);
			
			if(dNmax + dDmax < dN + dD){
				dNmax = dN;
				dDmax = dD;
			}
		}
	}
	
	for(i = 0; i < rows; i++){
		printf("\t\t");
		
		for(j = 0; j < cols; j++){
			fractD(*(*(ptr + i) + j), denom, dNmax, dDmax);
			printf(" ");
		}
		
		printf("\n");
	}
	
	return 0;
}

int maxF(int **ptr, int rows, int cols)
{
	int num, max = *(*(ptr + 0) + 0), i, j;
	
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			if(*(*(ptr + i) + j) < 0){
				num = -*(*(ptr + i) + j);
			}
			else{
				num = *(*(ptr + i) + j);
			}
			
			if(max < num){
				max = num;
			}
		}
	}
	
	return max;
}
