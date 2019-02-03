/*
QUESTION: Have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false. The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter.
*/
#include <stdio.h>
#include <string.h>

/*
Take note that for some reason, C does NOT have boolean types.
So we use unsigned char (with 0 and 1) instead.
Unsigned char only has one byte.
*/
unsigned char isLetter(char c){
    //Lower case letter
    int n = c-'a';
    if(n>=0 && n<=26) return 1;

    //Upper case letter
    n = c-'A';
    if(n>=0 && n<=26) return 1;

    return 0;
}

void SimpleSymbols(char * str){
    int i, n = strlen(str);
    char c;

    for(i=0;i<n;i++){
        c = str[i];

        if(isLetter(c)) if(i==0 || i==n || str[i-1]!='+' || str[i+1]!='+'){
            printf("false");
            return;
        }
    }

    printf("true");
}

int main(void) {
    SimpleSymbols(gets(stdin));
    return 0;
}
