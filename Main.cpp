#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include "DoubList.h"
#include "AvlTree.h"

using namespace std;


AvlTree readFile(string doc) {
	AvlTree tree;
	ifstream infile;
	infile.open(doc);

	string word;
	int count = 0;
	if (infile.is_open()) {
		while (std::getline(infile, word)) {
			//infile >> word;
			count++;
			//replace punction before adding to tree
			std::replace(word.begin(), word.end(), '[', ' ');
			std::replace(word.begin(), word.end(), ']', ' ');
			std::replace(word.begin(), word.end(), ',', ' ');
			std::replace(word.begin(), word.end(), '.', ' ');
			std::replace(word.begin(), word.end(), '?', ' ');
			std::replace(word.begin(), word.end(), '!', ' ');
			std::replace(word.begin(), word.end(), '(', ' ');
			std::replace(word.begin(), word.end(), ')', ' ');
			std::replace(word.begin(), word.end(), '<', ' ');
			std::replace(word.begin(), word.end(), '>', ' ');
			std::replace(word.begin(), word.end(), '"', ' ');
			std::replace(word.begin(), word.end(), ';', ' ');

			//replace numbers
			std::replace(word.begin(), word.end(), '0', ' ');
			std::replace(word.begin(), word.end(), '1', ' ');
			std::replace(word.begin(), word.end(), '2', ' ');
			std::replace(word.begin(), word.end(), '3', ' ');
			std::replace(word.begin(), word.end(), '4', ' ');
			std::replace(word.begin(), word.end(), '5', ' ');
			std::replace(word.begin(), word.end(), '6', ' ');
			std::replace(word.begin(), word.end(), '7', ' ');
			std::replace(word.begin(), word.end(), '8', ' ');
			std::replace(word.begin(), word.end(), '9', ' ');

			//string line = "a line of text to iterate through";
			string test;

			istringstream iss(word, istringstream::in);

			while (iss >> test)
			{
				//cout << "The word is " << test << " Line nuumber " << count << endl;
				tree.insert(test, count);
			}
		}
	}
	return tree;
	infile.close();
}

int main() {
	AvlTree p;
	p = readFile("document.txt");
	p.printwords();

	return 0;
};


