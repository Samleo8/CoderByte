/*
QUESTION: Have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false. The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol. So the string to the left would be false. The string will not be empty and will have at least one letter. 
*/

function SimpleSymbols(str) {
    var abc = new RegExp("[A-Z]","gi");

    var indexes = [];
    var result;

    while(result = abc.exec(str)){
      indexes.push(result.index);
    }

    for(i=0;i<indexes.length;i++){
        if(indexes[i]===0 || indexes[i]==str.length-1) return false;

        var ind = indexes[i];
        if(str[ind-1]!="+" || str[ind+1]!="+") return false;
    }

    return true;
}

// keep this function call here
SimpleSymbols(readline());
