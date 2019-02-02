/* QUESTION: 
Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty.
*/

function LongestWord(sen) {
    var words = sen.replace(/[^a-zA-Z0-9 ]/gi,"").split(" ");

    var maxi = {
        "word":null,
        "length":0
    }
    for(var i=0;i<words.length;i++){
        if(words[i].length>maxi.length){
            maxi.word = words[i];
            maxi.length = words[i].length;
        }
    }
    // code goes here
    return maxi.word;
}

// keep this function call here
LongestWord(readline());
