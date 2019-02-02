/*
QUESTION: 
Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm. Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a). Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.
*/

function LetterChanges(str) {
    var abc = "abcdefghijklmnopqrstuvwxyz";
    var rot1 = {"z":"a"};
    var l,i;
    var vowels = {
        "a":"A",
        "e":"E",
        "i":"I",
        "o":"O",
        "u":"U"
    }

    for(i=0;i<abc.length-1;i++){ //avoid z
        l = abc[i+1];
        rot1[abc[i]] = (vowels.hasOwnProperty(l))?vowels[l]:l;
    }

    _str = str.split("");
    for(i=0;i<_str.length;i++){
        l = _str[i];
        _str[i] = (rot1.hasOwnProperty(l))?rot1[l]:l;
    }

    // code goes here
    return _str.join("");
}

// keep this function call here
LetterChanges(readline());
