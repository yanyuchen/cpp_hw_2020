//================================================================
//  PROGRAMMER : yanyu chen
//  DATE       : 2020-12-22
//  FILENAME   : HW06CB0303134.CPP 
//  DESCRIPTION: This is a program to call the PangramCheck function to check the sentences in the file PangramList.txt.
//================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int answer1; // store the total number of sentences which is NOT a pangram in the file
int answer2; // store the total number of sentences which is a pangram in the file

int PangramCheck(string);

int main(){
	int i = 0, j = 0;
	string b;
	ifstream infile; // inFile is an istream object
	infile.open("PangramList.txt");
	while (getline(infile, b, '\n')){ // keep processing sentences
		i = i + PangramCheck(b);
		if (i != 0){
			j = j + 1;
		}
	}
	infile.close();
	answer1 = j - i;
	answer2 = i;
	cout << "The total number of sentences which is NOT a pangram in the file is " << answer1 << endl;
	cout << "The total number of sentences which is a pangram in the file is " << answer2;
	return 0;
}

int PangramCheck(string a){
	int m = 0, n = 0, p = 0, q = 0;
	while(a[m]!= 0){ // if two letters represent same letter erase one
		n = m + 1;
		while (a[n] != 0){
			if (a[n] == a[m] || a[n] == a[m]+32 || a[m] == a[n] + 32){
				a[n] = 20;
			}
			n = n + 1;
		}
		m = m + 1;
	}
	while (a[p] != 0){ // count the letter of the sentence after erasing
		if ((a[p] >= 97 && a[p]<=122)|| (a[p] >= 65 && a[p] <= 90)){
			q = q + 1;
		}
		p = p + 1;
	}
	if (q == 26){ // return 1 if it contains all letter
		return 1;
	} else { // else return 0
		return 0;
	}
}

