#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int spaceLeftInLine = 0;
int len = 0;
int spaceCounter = 0;

void lenMoreThanWidthOfLine(string w, int width) {

	if (spaceCounter != 0) {
		if (len > spaceLeftInLine) {
			cout << endl;
			spaceLeftInLine = width;
		}
	}

	int i = 0;

	while (i < len) {
		if (spaceLeftInLine == 0) {
			cout << endl;
			spaceLeftInLine = width;
		}
		if (i == len-1) {
			if (spaceLeftInLine != 0) {
				cout << w[i];
				//--spaceLeftInLine;
			} else {
				cout << w[i] << endl;
				spaceLeftInLine = width;
				return;
			}

		} else {
			cout << w[i];
		}
		--spaceLeftInLine;
		++i;
	}
}



	
int main(int argc, char *argv[]) {
	int width;

	if (argc == 1) {
		width = 25;
	} else {
		istringstream ss(argv[1]);
		ss >> width;
	}

	string word;
	spaceLeftInLine = width;
	while (cin >> word) {
		len = word.length();

		if (spaceCounter == 0) {

			if (len == spaceLeftInLine) {
				cout << word << endl;
				spaceLeftInLine = width;
			} else if (len > spaceLeftInLine) {
				lenMoreThanWidthOfLine(word, width);
			} else if (len < spaceLeftInLine) {
				cout << word;
				spaceLeftInLine = spaceLeftInLine - len;
			}
			++spaceCounter;

		} else {

			if (len+1 <= spaceLeftInLine) {
				if (spaceLeftInLine != width) {
					cout << " ";
					--spaceLeftInLine;
				}
			} else {
				lenMoreThanWidthOfLine(word, width);
				continue;
			}
		
			if (len == spaceLeftInLine) {
				cout << word << endl;
				spaceLeftInLine = width;
			} else if (len > spaceLeftInLine) {
				lenMoreThanWidthOfLine(word, width);
			} else if (len < spaceLeftInLine) {
				cout << word;
				spaceLeftInLine = spaceLeftInLine - len;
			}
	    }
	}
	cout << endl;
}
