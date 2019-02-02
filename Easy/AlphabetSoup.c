/*
QUESTION:
Have the function AlphabetSoup(str) take the str string parameter being passed and return the string with the letters in alphabetical order (ie. hello becomes ehllo). Assume numbers and punctuation symbols will not be included in the string.
*/
#include<cstdio>
#include<cstring>

void AlphabetSoup(char * str){
    int N = strlen(str);
    int i, j, count[26]; //for all 26 letters in the alphabet
    for(i=0;i<=26;i++) count[i] = 0; //set all counts to 0 first

    for(i=0;i<N;i++){
        int c = str[i]-'a'; //each character is actually an ASCII value
        if(c>=0 && c<26){
            count[c]++;
        }
    }

    for(i=0;i<26;i++)
        for(j=0;j<count[i];j++)
            printf("%c",(char)(i+'a'));
}

int main(void) {
	AlphabetSoup(gets(stdin));
	return 0;
}
