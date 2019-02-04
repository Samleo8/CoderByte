/*
QUESTION:
Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters, and question marks, and check if there are exactly 3 question marks between every pair of two numbers that add up to 10. If so, then your program should return the string true, otherwise it should return the string false. If there aren't any two numbers that add up to 10 in the string, then your program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3 question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.
*/
#include <stdio.h>
#include <string.h>

/*
Take note that for some reason, C does NOT have boolean types.
So we use unsigned char (with 0 and 1) instead.
unsigned char only has one byte.
*/
unsigned char isNumber(char c){
    return (c-'0'>=0 && c-'0'<10)?1:0;
}

void QuestionMarks(char* str){
    int prevNum = -1, i;
    int nQuestionMarks = 0;
    unsigned char has10 = 0;

    for(i=0;i<strlen(str);i++){
        char c = str[i]; //note that we can use c (single char) because no 2 numbers will add to 10 that are 2 digits
        //EXCEPT 10+0: Therefore, this solution is actually incomplete, and lacks a check for 10 + 0
        if(isNumber(c)){
            if(prevNum != -1){//previous number has a value
                if(prevNum + (int)(c-'0') == 10){
                    has10 = 1;
                    if(nQuestionMarks != 3){ //2 numbers add to 10 but have no ??? between them
                        printf("false");
                        return;
                    }
                }
            }
            nQuestionMarks = 0; //reset question marks counter
            prevNum = c-'0'; //convert from char to int
        }
        else if(c=='?'){
            nQuestionMarks++;
        }
    }

    if(has10) printf("true");
    else printf("false");
}

int main(void){
    QuestionMarks(gets(stdin));

    return 0
}
