/*
QUESTION:
Have the function VowelSquare(strArr) take the strArr parameter being passed which will be a 2D matrix of some arbitrary size filled with letters from the alphabet, and determine if a 2x2 square composed entirely of vowels exists in the matrix. For example: strArr is ["abcd", "eikr", "oufj"] then this matrix looks like the following:

a b c d
e i k r
o u f j

Within this matrix there is a 2x2 square of vowels starting in the second row and first column, namely, ei, ou. If a 2x2 square of vowels is found your program should return the top-left position (row-column) of the square, so for this example your program should return 1-0. If no 2x2 square of vowels exists, then return the string not found. If there are multiple squares of vowels, return the one that is at the most top-left position in the whole matrix. The input matrix will at least be of size 2x2.
===============================================================================
Input:["aqrst", "ukaei", "ffooo"]

Output:"1-2"


Input:["gg", "ff"]

Output:"not found"
*/
#include <stdio.h>
#include <string.h>

unsigned char isVowel(c){
	switch(c){
		case 'a': case 'A':
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O':
		case 'u': case 'U':
			return 1;
		default:
			return 0;
	}
}

void VowelSquare(char * strArr[], int len) {
	int len2 = strlen(strArr[0]);
	char arr[len][len2];
	int i,j;

	for(i=0;i<arr.length-1;i++){
		for(j=0;j<arr[i].length-1;j++){
			if( isVowel(arr[i][j]) && isVowel(arr[i+1][j]) && isVowel(arr[i][j+1])  && isVowel(arr[i+1][j+1]) ){
				printf("%d-%d",i,j);
				return;
			}
		}
	}

	printf("not found");
	return;
}

int main(void) {
	/* Note: In C you first have to initialize an array and set
	 it equal to the stdin to test your code with arrays. */

	char * A[] = gets(stdin);
	int len = sizeof(A)/sizeof(A[0]); //take note that due to pointer issues, you need to find the size BEFORE passing it through a function
	VowelSquare(A,len);
	return 0;
}
