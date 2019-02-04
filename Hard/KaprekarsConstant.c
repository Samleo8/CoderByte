/*
QUESTION:
Have the function KaprekarsConstant(num) take the num parameter being passed which will be a 4-digit number with at least two distinct digits. Your program should perform the following routine on the number: Arrange the digits in descending order and in ascending order (adding zeroes to fit it to a 4-digit number), and subtract the smaller number from the bigger number. Then repeat the previous step. Performing this routine will always cause you to reach a fixed number: 6174. Then performing the routine on 6174 will always give you 6174 (7641 - 1467 = 6174). Your program should return the number of times this routine must be performed until 6174 is reached. For example: if num is 3524 your program should return 3 because of the following steps: (1) 5432 - 2345 = 3087, (2) 8730 - 0378 = 8352, (3) 8532 - 2358 = 6174.

Hard challenges are worth 15 points and you are not timed for them.
*/

/* NOTE:
This is an interesting mathematical constant, wherein there are at most 8 iterations before we arrive at the constant 6174. Note also that repeating digits (eg. 1111, 2222 etc) will arrive at the constant 0000. For a full solution, we must account for this also.
*/
#include <stdio.h>
#include <stdlib.h>

#define INT_LEN(n) (n<10)?1:(n<100)?2:(n<1000)?3:4
#define POW_TEN(n) (n==3)?1000:(n==2)?100:(n==1)?10:1
//#define ABS(n) (n>0)?n:-n

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int KaprekarsConstant(int num) {
	if(num == 6174) return 0; //reached the constant
	if(num == 0 || num == 1111 || num == 2222 || num == 3333 || num == 4444 || num == 5555 || num == 6666 || num == 7777 || num == 8888 || num == 9999) return 0; //special case

	int numArr[4] = {0};
	int i;

	int l = INT_LEN(num);

	for(i=0;i<l;i++){
		numArr[i] = num%10;
		num = num/10;
	}

	qsort(numArr, 4, sizeof(int), cmpfunc);

	//for(i=0;i<4;i++) printf("%d ",numArr[i]); puts("");

	int n1= 0; int n2 = 0; int ten;

	for(i=0;i<4;i++){
	    ten = POW_TEN(i);
	    n1 += numArr[i]*ten;
	    n2 += numArr[3-i]*ten;
	}

	return 1+KaprekarsConstant(n1-n2);
}

int main(void){
	printf("%d",KaprekarsConstant(gets(stdin)));
}
