#include "calc_header.h"

int matrixAddition();
int matrixSubtraction();
int matrixScalarMultiplication();
int matrixMultiplication();
int matrixTranspose();
int matrixDeterminant();
int matrixMinor();
int matrixCofactor();
int matrixAdjoint();
int matrixInverse();
int matrixPower();

int main(int argc, char *argv[]) 
{
	int num, ch;
	char YorN;
	
	while(1){
		printf("\n\n\t     Matrix Calculator v1.2\n\n");
		
		printf("\t (1) Matrix Addition Calculator\n");
		printf("\t (2) Matrix Subtraction Calculator\n");
		printf("\t (3) Matrix Scalar Multiplication Calculator\n");
		printf("\t (4) Matrix Multiplication Calculator\n");
		printf("\t (5) Transpose Matrix Calculator\n");
		printf("\t (6) Matrix Determinant Calculator\n");
		printf("\t (7) Minor Matrix Calculator\n");
		printf("\t (8) Cofactor Matrix Calculator\n");
		printf("\t (9) Adjoint Matrix Calculator\n");
		printf("\t(10) Inverse Matrix Calculator\n");
		printf("\t(11) Matrix Power Calculator\n");
		
		printf("\n");
		
		while(1){
			printf("\tEnter the number of the calculator you want to use: ");
			
			if(scanf("%d", &num) != 1){
				printf("\tInvalid Input, Enter Again.\n");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			
			if((ch = getchar()) != '\n' && ch != EOF){
				if(ch != ' ' && ch != '\t'){
					printf("\tInvalid Input, Enter Again.\n");
					while((ch = getchar()) != '\n' && ch != EOF);
					continue;
				}
				while((ch = getchar()) != '\n' && ch != EOF);
			}
			
			if(num < 1 || num > 11){
				printf("\tInvalid Input, Enter Again.\n");
				continue;
			}
			
			break;
		}
		
		CLEAR_SCREEN();
		
		switch(num){
			case 1: matrixAddition();
			break;
			case 2: matrixSubtraction();
			break;
			case 3: matrixScalarMultiplication();
			break;
			case 4: matrixMultiplication();
			break;
			case 5: matrixTranspose();
			break;
			case 6: matrixDeterminant();
			break;
			case 7: matrixMinor();
			break;
			case 8: matrixCofactor();
			break;
			case 9: matrixAdjoint();
			break;
			case 10: matrixInverse();
			break;
			case 11: matrixPower();
			break;
		}
		
		while(1){
			printf("\n\tDo you want to perform another calculation? (Y/N) : ");
			
			if(scanf(" %c", &YorN) != 1){
				printf("\tInvalid Input, Enter Again.\n");
				while((ch = getchar()) != '\n' && ch != EOF);
				continue;
			}
			
			if((ch = getchar()) != '\n' && ch != EOF){
				if(ch != ' ' && ch != '\t'){
					printf("\tInvalid Input, Enter Again.\n");
					while((ch = getchar()) != '\n' && ch != EOF);
					continue;
				}
				while((ch = getchar()) != '\n' && ch != EOF);
			}
			
			if(YorN != 'Y' && YorN != 'y' && YorN != 'N' && YorN != 'n'){
				printf("\tInvalid Input, Enter Again.\n");
				continue;
			}
			
			break;
		}
		
		if(YorN == 'N' || YorN == 'n'){
			break;
		}
		
		CLEAR_SCREEN();
	}
	
	return 0;
}

int matrixAddition()
{
	int **ptrA, **ptrB, **ptrC, rows, cols;
	
	printf("\n\n\tMatrix Addition\n\n");
	
	printf("\tEnter the Matrix Size (M x N) : ");
	readSize(&rows, &cols);
	
	dclr2d(&ptrA, rows, cols);
	dclr2d(&ptrB, rows, cols);
	dclr2d(&ptrC, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix A:\n");
	in2d(ptrA, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix B:\n");
	in2d(ptrB, rows, cols);
	
	addF(ptrA, ptrB, ptrC, rows, cols);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix Addition\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptrA, rows, cols);
	
	printf("\n\t\tMatrix B:\n\n");
	
	out2d(ptrB, rows, cols);
	
	printf("\n\t\tMatrix (A + B) :\n\n");
	
	out2d(ptrC, rows, cols);
	
	free2d(ptrA, rows);
	free2d(ptrB, rows);
	free2d(ptrC, rows);
	
	return 0;
}

int matrixSubtraction()
{
	int **ptrA, **ptrB, **ptrC, rows, cols;
	
	printf("\n\n\tMatrix Subtraction\n\n");
	
	printf("\tEnter the Matrix Size (M x N) : ");
	readSize(&rows, &cols);
	
	dclr2d(&ptrA, rows, cols);
	dclr2d(&ptrB, rows, cols);
	dclr2d(&ptrC, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix A:\n");
	in2d(ptrA, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix B:\n");
	in2d(ptrB, rows, cols);
	
	subF(ptrA, ptrB, ptrC, rows, cols);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix Subtraction\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptrA, rows, cols);
	
	printf("\n\t\tMatrix B:\n\n");
	
	out2d(ptrB, rows, cols);
	
	printf("\n\t\tMatrix (A - B) :\n\n");
	
	out2d(ptrC, rows, cols);
	
	free2d(ptrA, rows);
	free2d(ptrB, rows);
	free2d(ptrC, rows);
	
	return 0;
}

int matrixScalarMultiplication()
{
	int **ptr, numer, denom, rows, cols;
	
	printf("\n\n\tMatrix Scalar Multiplication\n\n");
	
	printf("\tEnter the Matrix Size (M x N) : ");
	readSize(&rows, &cols);
	
	printf("\n\tEnter the Scalar as an Integer or a Fraction: ");
	readFrac(&numer, &denom);
	
	dclr2d(&ptr, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix Scalar Multiplication\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tMatrix (%d/%d)A:\n\n", numer, denom);
	
	scalarD(ptr, numer, denom, rows, cols);
	
	free2d(ptr, rows);
	
	return 0;
}

int matrixMultiplication()
{
	int **ptrA, **ptrB, **ptrC, rowsA, colsA, rowsB, colsB;
	
	printf("\n\n\tMatrix Multiplication\n\n");
	
	while(1){
		printf("\tEnter the Size of Matrix A (M x N) : ");
		readSize(&rowsA, &colsA);
		
		printf("\tEnter the Size of Matrix B (M x N) : ");
		readSize(&rowsB, &colsB);
		
		if(colsA == rowsB){
			break;
		}
		else{
			printf("\tMatrices are Incompatible for Multiplication, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptrA, rowsA, colsA);
	dclr2d(&ptrB, rowsB, colsB);
	dclr2d(&ptrC, rowsA, colsB);
	
	printf("\n\tEnter the Elements of Matrix A:\n");
	in2d(ptrA, rowsA, colsA);
	
	printf("\n\tEnter the Elements of Matrix B:\n");
	in2d(ptrB, rowsB, colsB);
	
	multiF(ptrA, ptrB, ptrC, rowsA, colsA, colsB);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix Multiplication\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptrA, rowsA, colsA);
	
	printf("\n\t\tMatrix B:\n\n");
	
	out2d(ptrB, rowsB, colsB);
	
	printf("\n\t\tMatrix (A x B) :\n\n");
	
	out2d(ptrC, rowsA, colsB);
	
	free2d(ptrA, rowsA);
	free2d(ptrB, rowsB);
	free2d(ptrC, rowsA);
	
	return 0;
}

int matrixTranspose()
{
	int **ptr, **ptrT, rows, cols;
	
	printf("\n\n\tTranspose Matrix\n\n");
	
	printf("\tEnter the Matrix Size (M x N) : ");
	readSize(&rows, &cols);
	
	dclr2d(&ptr, rows, cols);
	dclr2d(&ptrT, cols, rows);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	transMatrixF(ptr, ptrT, rows, cols);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tTranspose Matrix\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tMatrix (A^T) :\n\n");
	
	out2d(ptrT, cols, rows);
	
	free2d(ptr, rows);
	free2d(ptrT, cols);
	
	return 0;
}

int matrixDeterminant()
{
	int **ptr, det, rows, cols;
	
	printf("\n\n\tDeterminant of a Matrix\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			break;
		}
		else{
			printf("\tOnly Square Matrices have a Determinant, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptr, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	det = detF(ptr, rows);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tDeterminant of a Matrix\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tdet(A) = %d\n", det);
	
	free2d(ptr, rows);
	
	return 0;
}

int matrixMinor()
{
	int **ptr, **ptrM, rows, cols;
	
	printf("\n\n\tMatrix of Minors\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			if(rows < 2){
				printf("\tMatrix Size must be 2x2 or above to have Minors, Enter Dimensions Again.\n\n");
				continue;
			}
			
			break;
		}
		else{
			printf("\tOnly Square Matrices have Minors, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptr, rows, cols);
	dclr2d(&ptrM, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	minorMatrixF(ptr, ptrM, rows);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix of Minors\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tMatrix minor(A) :\n\n");
	
	out2d(ptrM, rows, cols);
	
	free2d(ptr, rows);
	free2d(ptrM, rows);
	
	return 0;
}

int matrixCofactor()
{
	int **ptr, **ptrC, rows, cols;
	
	printf("\n\n\tMatrix of Cofactors\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			if(rows < 2){
				printf("\tMatrix Size must be 2x2 or above to have Cofactors, Enter Dimensions Again.\n\n");
				continue;
			}
			
			break;
		}
		else{
			printf("\tOnly Square Matrices have Cofactors, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptr, rows, cols);
	dclr2d(&ptrC, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	cofacMatrixF(ptr, ptrC, rows);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tMatrix of Cofactors\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tMatrix cofac(A) :\n\n");
	
	out2d(ptrC, rows, cols);
	
	free2d(ptr, rows);
	free2d(ptrC, rows);
	
	return 0;
}

int matrixAdjoint()
{
	int **ptr, **ptrJ, rows, cols;
	
	printf("\n\n\tAdjoint Matrix\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			if(rows < 2){
				printf("\tMatrix Size must be 2x2 or above to have an Adjoint Matrix, Enter Dimensions Again.\n\n");
				continue;
			}
			
			break;
		}
		else{
			printf("\tOnly Square Matrices have an Adjoint Matrix, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptr, rows, cols);
	dclr2d(&ptrJ, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	cofacMatrixF(ptr, ptrJ, rows);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tAdjoint Matrix\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	copy2d(ptrJ, ptr, rows, cols);
	
	transMatrixF(ptr, ptrJ, rows, cols);
	
	printf("\n\t\tMatrix adj(A) :\n\n");
	
	out2d(ptrJ, rows, cols);
	
	free2d(ptr, rows);
	free2d(ptrJ, rows);
	
	return 0;
}

int matrixInverse()
{
	int **ptr, det, rows, cols;
	
	printf("\n\n\tInverse Matrix\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			if(rows < 2){
				printf("\tMatrix Size must be 2x2 or above to have an Inverse Matrix, Enter Dimensions Again.\n\n");
				continue;
			}
			
			break;
		}
		else{
			printf("\tOnly Square Matrices have an Inverse Matrix, Enter Dimensions Again.\n\n");
		}
	}
	
	dclr2d(&ptr, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	det = detF(ptr, rows);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tInverse Matrix\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	if(det == 0){
		printf("\n\t\tInverse Matrix does not exist.\n");
	}
	else{
		printf("\n\t\tMatrix (A^-1) :\n\n");
		
		inverseMatrixD(ptr, rows);
	}
	
	free2d(ptr, rows);
	
	return 0;
}

int matrixPower()
{
	int **ptr, power, rows, cols;
	
	printf("\n\n\tPower of Matrix\n\n");
	
	while(1){
		printf("\tEnter the Matrix Size (M x N) : ");
		readSize(&rows, &cols);
		
		if(rows == cols){
			break;
		}
		else{
			printf("\tOnly Square Matrices have an Inverse Matrix, Enter Dimensions Again.\n\n");
		}
	}
	
	printf("\n\tEnter the Power to raise the Matrix to (Integer Powers Only) : ");
	readNum(&power);
	
	dclr2d(&ptr, rows, cols);
	
	printf("\n\tEnter the Elements of Matrix:\n");
	in2d(ptr, rows, cols);
	
	CLEAR_SCREEN();
	
	printf("\n\n\tPower of Matrix\n\n");
	
	printf("\t\tMatrix A:\n\n");
	
	out2d(ptr, rows, cols);
	
	printf("\n\t\tMatrix (A^%d):\n\n", power);
	
	intPowerD(ptr, power, rows);
	
	free2d(ptr, rows);
	
	return 0;
}
