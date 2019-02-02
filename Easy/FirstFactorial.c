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
