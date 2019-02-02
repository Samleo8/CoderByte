/*
QUESTION:
Have the function QuestionsMarks(str) take the str string parameter, which will contain single digit numbers, letters, and question marks, and check if there are exactly 3 question marks between every pair of two numbers that add up to 10. If so, then your program should return the string true, otherwise it should return the string false. If there aren't any two numbers that add up to 10 in the string, then your program should return false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true because there are exactly 3 question marks between 6 and 4, and 3 question marks between 5 and 5 at the end of the string.
*/

function QuestionsMarks(_str) {
    //Replace all groups of non-numberic and non-question marks characters with "|".
    //This is to separate out numbers which were previously separated by other characters
    var str = _str.replace(new RegExp("([^0-9\\?]+)","gi"),"|");

    //Remove "|" characters which are next to question marks
    //This is so that later when we are finding for "???" we won't have problems
    str = str.replace(new RegExp("(\\?\\|)|(\\|\\?)","gi"),"?");

    //At this point, we have the numbers separated purely by '?'s and '|'s
    var regNumbers = new RegExp("([0-9]+)","gi");
    var i, result, results = [];

    //Get all the indexes of the numbers in this string
    while(result = regNumbers.exec(str)){
        results.push({
            "number": parseInt(result),
            "index": result.index
        });
    }

    var no10 = true;
    var r1,r2;
    for(i=0;i<results.length-1;i++){
        r1 = results[i];
        r2 = results[i+1];

        if(r1.number+r2.number != 10) continue;
        no10 = false;
        if(str.substring(r1.index+1,r2.index) != "???" ) return false;
    }

    if(no10) return false;
    
    return true;
}

//For testing purposes
/*
//n=-1;
testcases = ["arrb6???4xxbl5???eee5","9???1???9??1???9","5??aaaaaaaaaaaaaaaaaaa?5?5"];
readline = ()=>{
    return testcases[i];
}
for(i=0;i<testcases.length;i++)
//*/
QuestionsMarks(readline());
