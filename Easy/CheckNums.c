/*
QUESTION:
Have the function CheckNums(num1,num2) take both parameters being passed and return the string true if num2 is greater than num1, otherwise return the string false. If the parameter values are equal to each other then return the string -1.
*/
#include <stdio.h>

void CheckNums(num1,num2) {
	printf("%s", (num1 == num2)?"-1":((num2>num1)?"true":"false") );
}

int main(void) {
    CheckNums(gets(stdin));
    return 0;
}
