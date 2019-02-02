/*
QUESITON:
Have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word. Words will be separated by only one space.
*/

#include <stdio.h>
#include <string.h>

char toUpper(char c){
    int n = c-'a';
    char * upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(n>=0 && n<=26){ //lower case alpha letter
        //printf("%c",upper[n]);
        return upper[n];
    }
    return c;
}

void LetterCapitalize(char * str){
    short prevWasSpace = 1;
    int i;
    char c;

    for(i=0;i<strlen(str);i++){
        c = (prevWasSpace)?toUpper(str[i]):str[i];
        printf("%c",c);
        prevWasSpace = (c==' ')?1:0;
    }

    //printf("%s", str);
}

int main(void) {
    LetterCapitalize(gets(stdin));
    return 0;
}
