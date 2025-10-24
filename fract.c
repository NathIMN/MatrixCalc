#include "calc_header.h"

void fractD(int x, int y, int dNmax, int dDmax)
{
	struct two fract;
	int dN, dD, bfr, n;
	
	fract = fractF(x, y);  //could directly do: x = fractF(x, y).x;
	
	dN = digitsF(fract.x);
	dD = digitsF(fract.y);
	
	n = fract.x >= 0 ? 1 : 0;
	
	if(fract.x == 0 || fract.y == 1){
		bfr = dNmax + dDmax + 1 - dN;
		
		if(fract.x < 0){
			printf("%*s%d%*s", bfr / 2, "", fract.x, bfr - bfr / 2, "");
		}
		else{
			printf("%*s%s%d%*s", bfr / 2, "", " ", fract.x, bfr - bfr / 2, "");
		}
	}
	else{
		bfr = dNmax + dDmax -dN -dD;
		
		if(fract.x < 0){
			printf("%*s%d/%d%*s",bfr / 2, "", fract.x, fract.y, bfr - bfr / 2, "");
		}
		else{
			printf("%*s%s%d/%d%*s",bfr / 2, "", " ", fract.x, fract.y, bfr - bfr / 2, "");
		}
	}
	
	return;
}

int gcdF(int x, int y)  //only takes 0 and positive  
{
	int gcd;
	
	if(x < 0 || y < 0){
		printf("\tDo not pass negative numbers for gcd.\n");
		exit(1);
		return 1;  //not necessary
	}
	
	if(x == 0 && y == 0){
		printf("\tGCD between 0 and 0 is undefined.\n");
		exit(1);
		return 1;  //not necessary
	}
	else if(x == 0){
		gcd = y;
		return gcd;
	}
	else if(y == 0){
		gcd = x;
		return gcd;
	}
/*	
	while(1){
		if(x == y){
			gcd = x;
			break;
		}
		if(x > y){
			x = x - y;
		}
		else{
			y = y - x;
		}
	}  //not the most efficient algorithm
*/
	while(1){
		if(x == 0){
			gcd = y;
			break;
		}
		
		if(y == 0){
			gcd = x;
			break;
		}
		
		if(x > y){
			x = x % y;
		}
		else{
			y = y % x;
		}
	}
		
	return gcd;
}

struct two fractF(int x, int y)
{
	struct two red = {0, 0};
	int gcd, xx = x, yy = y;
	
	if(y == 0){
		printf("\tDivision by Zero is Undefined.\n");
		exit(1);
		return red;  //not necessary
	}
	
	if(xx < 0){
		xx = -xx;
	}
	
	if(yy < 0){
		yy = -yy;
	}
	
	gcd = gcdF(xx, yy);
	
	if(y < 0){
		x = -x;
		y = -y;
	}  //to keep the denominator positive
	
	red.x = x / gcd;
	red.y = y / gcd;
	
	return red;
}

int digitsF(int x)
{
	int digits = 0;
	
	if(x < 0){
		x = -x;
	}
	
	do{
		x /= 10;
		digits++;
	}
	while(x != 0);
	
	return digits;
}
