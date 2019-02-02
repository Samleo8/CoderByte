/*
QUESTION:
Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it. For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24. For the test cases, the range will be between 1 and 18 and the input will always be an integer.
*/

#include <stdio.h>

int FirstFactorial(int n) {
    if(n<=2) return n;
    return n*FirstFactorial(n-1);
}

int main(void) {
	int f = FirstFactorial(gets(stdin));
	printf("%d",f);
	return 0;
}
