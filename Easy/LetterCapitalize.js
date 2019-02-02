/*
QUESITON:
Have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word. Words will be separated by only one space. 
*/

function LetterCapitalize(str) {
    var s = str.split(" ");
    for(var i=0;i<s.length;i++){
        var w = s[i].split("");
        w[0] = w[0].toUpperCase();
        s[i] = w.join("");
    }

    return s.join(" ");
}

// keep this function call here
LetterCapitalize(readline());
