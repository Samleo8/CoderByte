/*
QUESTION:
Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. For example: if the input string is "Hello World and Coders" then your program should return the string "sredoC dna dlroW olleH".
*/

#include <stdio.h>
#include <string.h>

void FirstReverse(char * str) {
    int N = strlen(str);
    for(int i=0;i<N;i++){
        printf("%c", str[N-i-1]);
    }
}

int main(void) {
    FirstReverse(gets(stdin));
    return 0;
}
