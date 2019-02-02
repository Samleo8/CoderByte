/*
QUESTION:
Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it. For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24. For the test cases, the range will be between 1 and 18 and the input will always be an integer. 
*/

var fact = {}

function FirstFactorial(n) {
    if(n<=2) return n;
    if(fact.hasOwnProperty(n)) return fact[n]

    return fact[n] = n*FirstFactorial(n-1);
}

// keep this function call here
FirstFactorial(readline());
