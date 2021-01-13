//================================================================
//  PROGRAMMER : yanyu chen 
//  DATE       : 2021-01_02
//  FILENAME   : HW07AB05303049.CPP 
//  DESCRIPTION: This is a program that reads this file and finds 
//				 the longest word that reverses to a different word.
//================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int answer1, answer2;

int main(){
	ifstream infile;
	infile.open("words.txt"); // read the file words.txt
	int total = 0; // count the total number of words
	string b, d = "";
	set<string>s;
	set<string>::iterator it;
	while (getline(infile, b,'\n')){
		total++;
		transform(b.begin(), b.end(), b.begin(), ::tolower); // turn the string into the lower case
		it = s.find(b); // find the location
		if (it == s.end()){
			string c = b;
			reverse(c.begin(), c.end()); // reverse the lower-letter string
			s.insert(c);
		}
		if (it != s.end() && b.length() > d.length()){ // find the one that has its reverse in words.txt and is the longest word in it
			d = b;
		}
	}
	infile.close();
	cout << "There are " << total << " words in the words.txt" << endl;
	cout << "The longest words: " << d << " and ";
	reverse(d.begin(), d.end());
	cout << d << endl;
	cout << "The number of characters of the longest words: " << d.length();
	
	answer1 = total;
	answer2 = d.length();
	return 0;
}
