#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
using namespace std;

const int puzzle_size = 9;
const int empty_vale = 0;

void printPuzzle(int puzzle[puzzle_size][puzzle_size]) {
	string text, padding, separator = "";
	for(int i= 0; i<puzzle_size; i++) {
		text = "|";
		separator = " -";
		padding = "|";
		for(int j = 0; j<puzzle_size; j++) {
			string value = puzzle[i][j] == empty_vale ? " " : to_string(puzzle[i][j]);
			text += " " + value + "  |";
			separator += "------";
			padding += "     |";

			if(j % 3 == 2 && j != puzzle_size -1) {
				padding += "|";
				text += "|";
			}
		}
		if(i % 3 == 0 && i != 0) {
			replace(separator.begin(), separator.end(), '-', '=');
		}
		cout << separator << endl;
		cout << padding << endl;
		cout << text << endl;
		cout << padding << endl;
	}
}

void generatePuzzle(int puzzle[puzzle_size][puzzle_size]) {
	for(int i = 0; i<puzzle_size; i++) {
		for(int j = 0; j<puzzle_size; j++) {
			puzzle[i][j] = empty_vale;
		}
	}
}

int main() {
	int puzzle[puzzle_size][puzzle_size];
	generatePuzzle(puzzle);
	return 0;
}