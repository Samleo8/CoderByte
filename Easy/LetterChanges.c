/*
QUESTION:
Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm. Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.
*/

#include <stdio.h>
#include <string.h>

/*
Take note that for some reason, C does NOT have boolean types.
So we use unsigned char (with 0 and 1) instead.
Unsigned char only has one byte.
*/

/* Shift letters by 1 */
char shift_letter(char c){
    //Lower case letter
    if(c>='a' && c<='y') return c+1;
    if(c=='z') return 'a'; //'z'

    //Upper case letter
    if(c>='a' && c<='y') return c+1;
    if(c=='Z') return 'A';

    //Neither
    return c;
}

/* Check if vowel, and captialize if so */
char capitaliseVowel(char c){
    switch(c){
        case 'a': return 'A';
        case 'e': return 'E';
        case 'i': return 'I';
        case 'o': return 'O';
        case 'u': return 'U';

        default: return c;
    }
}

void LetterChanges(char * str) {
    int i;

    for(i=0;i<strlen(str);i++){
        printf("%c",capitaliseVowel(shift_letter(str[i])));
    }
}

int main(void) {
    LetterChanges(gets(stdin));
    return 0;
}
