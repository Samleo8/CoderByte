/*
QUESTION:
Have the function PentagonalNumber(num) read num which will be a positive integer and determine how many dots exist in a pentagonal shape around a center dot on the Nth iteration. For example, in the image below you can see that on the first iteration there is only a single dot, on the second iteration there are 6 dots, on the third there are 16 dots, and on the fourth there are 31 dots.
*/
#include <stdio.h>

int PentagonalNumber(int n) {
	//Basically: f(n) = 1+5*(1+2+...+n-1) = 1+5*(n+1-1)(n-1)/2 (based on Gauss summation)
	return 1+5*(n*(n-1)/2);
}

int main(void){
	printf("%d", PentagonalNumber(gets(stdin)));
}
