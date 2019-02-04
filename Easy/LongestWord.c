/* QUESTION:
Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty.
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

    //Number
    n = c-'0';
    if(n>=0 && n<=9) return 1;

    return 0;
}

void LongestWord(char * sen){
    int startIndex = 0, maxStartIndex = 0;
    int currLength = 0, maxLength = 0;
    int i, len = strlen(sen);

    for(i=0;i<len;i++){
        if(isLetter(sen[i])){ //we are at a letter
            if(currLength==0) startIndex = i;
            currLength++;
        }

        if(!isLetter(sen[i]) || i==len-1){ //either not a letter, or reached the end of the string
            if(currLength > maxLength){
                maxLength = currLength;
                maxStartIndex = startIndex;
            }
            currLength = 0;
        }
    }

    for(i=maxStartIndex;i<maxStartIndex+maxLength;i++){
        printf("%c", sen[i]);
    }
}

int main(void) {
    LongestWord(gets(stdin));
    return 0;
}
