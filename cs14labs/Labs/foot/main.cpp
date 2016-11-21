#include "WordLadder.h"

#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
   string filename, wordBegin, wordEnd;
   cout << "Enter the name of the dictionary file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter the first word: ";
   cin >> wordBegin;
   cout << endl;
   while (wordBegin.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
      cin >> wordBegin;
      cout << endl;
   }
   cout << "Enter the last word: ";
   cin >> wordEnd;
   cout << endl;
   while (wordEnd.size() != 5) {
      cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
      cin >> wordEnd;
      cout << endl;
   }
   
	WordLadder wl(filename);
	
	wl.outputLadder(wordBegin, wordEnd,"output.txt");
	cout << endl;
	
	return 0;
}
