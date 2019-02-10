/* QUESTION:
Have the function CorrectPath(str) read the str parameter being passed, which will represent the movements made in a 5x5 grid of cells starting from the top left position. The characters in the input string will be entirely composed of: r, l, u, d, ?. Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down. Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the grid all the way to the bottom right without touching previously travelled on cells in the grid.

For example: if str is "r?d?drdd" then your program should output the final correct string that will allow a path to be formed from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd. There will only ever be one correct path and there will always be at least one question mark within the input string.
================================================================================
Input:"???rrurdr?"
Output:"dddrrurdrd"

Input:"drdr??rrddd?"
Output:"drdruurrdddd"
*/
var N = 5; //size of grid

var dir = { //"[u|r|d|l]":[dx,dy]
	"u":[0,-1],
	"d":[0,1],
	"r":[1,0],
	"l":[-1,0]
}

function CorrectPath(str){
	var i,j;
	var dirs = str.split("");

	var grid = [];
	/* Generate a NxN grid, where each element in the grid represents the direction to take.
	Default is '?'
	*/
	for(i=0;i<N;i++){
		grid.push([]);
		for(j=0;j<N;j++){
			grid[i].push("?");
		}
	}

	/*
	==Smarter way?==
	If we sum up the individual directions' dx and dy, we can get an idea of what's lacking from the difference in the sums and the total size of the grid (N=5).
	For eg. "???rrurdr?":
		[1,0]+[1,0]+[0,-1]+[1,0]+[0,1]+[1,0] = [4,0]
		[4,-4] - [4,0] = [0,-4]
		This means that if there are 4 '?'s, there needs to be 4'd's and 0'l/r's.
		If there are 5 '?'s, there might be 4'd's, 1'r', 1'l', so the final total is also [0,-4]
	*/
	var nQ = 0; //number of question marks to be found
	var diffSum = [N-1,-(N-1)]; //we need to traverse 4 spaces right and 4 spaces down
	for(i=0;i<dirs.length;i++){
		var c  = dirs[i];
		if(c == '?') nQ++;
		else{
			diffSum[0] -= dir[c][0];
			diffSum[1] -= dir[c][1];
		}
	}

	var combos = generateCombos(nQ, diffSum);

	return dirs;
}

function generateCombos(nQ, diffSum){
	
}

readline = ()=>{
	return "r?d?drdd";
}

CorrectPath(readline());
