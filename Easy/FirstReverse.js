/*
QUESTION:
Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. For example: if the input string is "Hello World and Coders" then your program should return the string "sredoC dna dlroW olleH". 
*/

function FirstReverse(str) {
	return str.split("").reverse().join("");
}

// keep this function call here
FirstReverse(readline());
