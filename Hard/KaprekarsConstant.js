/*
QUESTION:
Have the function KaprekarsConstant(num) take the num parameter being passed which will be a 4-digit number with at least two distinct digits. Your program should perform the following routine on the number: Arrange the digits in descending order and in ascending order (adding zeroes to fit it to a 4-digit number), and subtract the smaller number from the bigger number. Then repeat the previous step. Performing this routine will always cause you to reach a fixed number: 6174. Then performing the routine on 6174 will always give you 6174 (7641 - 1467 = 6174). Your program should return the number of times this routine must be performed until 6174 is reached. For example: if num is 3524 your program should return 3 because of the following steps: (1) 5432 - 2345 = 3087, (2) 8730 - 0378 = 8352, (3) 8532 - 2358 = 6174.

Hard challenges are worth 15 points and you are not timed for them.
*/

/* NOTE:
This is an interesting mathematical constant, wherein there are at most 8 iterations before we arrive at the constant 6174. Note also that repeating digits (eg. 1111, 2222 etc) will arrive at the constant 0000. For a full solution, we must account for this also.
*/

function KaprekarsConstant(num) {
	if(num == 6174) return 0; //reached the constant
	if(num == 0 || num == 1111 || num == 2222 || num == 3333 || num == 4444 || num == 5555 || num == 6666 || num == 7777 || num == 8888 || num == 9999) return 0; //special case

	var numArr = [];
	var i;

	numArr = num.toString().split("").sort(function(a,b){ return parseInt(b)-parseInt(a); }); //sort digits in descending order
	var l = numArr.length; for(i=0;i<4-l;i++) numArr.push(0); //add missing '0's to the back

	n1 = parseInt(numArr.join(""));
	n2 = parseInt(numArr.reverse().join(""));

    //return 1;
	return 1+KaprekarsConstant(Math.abs(n2-n1));
}

// keep this function call here
KaprekarsConstant(readline());
