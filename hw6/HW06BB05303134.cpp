//================================================================
//  PROGRAMMER : yanyu chen
//  DATE       : 2020-12-22
//  FILENAME   : HW06BB0303134.CPP 
//  DESCRIPTION: This is a program to reads a document in English and calculate
//				 the reading level of the document.
//================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

double answer1 = 0; // store the average rank of Document.txt file
int answer2 = 0; // store the number of words in Document.txt which cannot be found in the dictionary file Dictionary_1000.txt

int findRank(string *dictionary, string word); // Search the word in the *dictionary and return the rank of the word. Return the rank 1001 if the word is not in the *dictionary
void saveResult(int *rank, string outFileName); // The int *rank stores the rank of all words in the document file. The function saves the result to an output file outFileName

int main(){
	vector<string> dict;
	string a;
	ifstream infile1, infile2;         // inFile is an istream object
	infile1.open("Dictionary_1000.txt");
	while (getline(infile1, a, '\n')){ // keep processing sentences
		string b;
		int i = 0;
		stringstream ss(a);
		while (ss >> b){ // keep processing words
			if (i == 1){
				dict.push_back(b);		
			}
			i++;
			i %= 2;
		}
	}
	infile1.close();
	string *dictionary = new string [dict.size()];
	for (int i = 0; i < int(dict.size()); i++){
		dictionary[i] = dict[i];
	} 
	vector<int> rk;
	infile2.open("Document.txt");
	while (getline(infile2, a, '\n')){ // keep processing sentences
		string b;
		stringstream ss(a);
		while (ss >> b){ // keep processing words
			int len = b.size();
			if (b[len -1] == 46 || b[len - 1] == 44 || b[len - 1] == 59){ // remove the camma, dot, and semicolon if there exists
				b.replace(len-1, 1, "");
			}
			char tmp = tolower(b[0]);
			b[0] = tmp; // change to the lower case
			rk.push_back(findRank(dictionary, b));
		}
		rk.push_back(0); // insult 0 for the format of a new line	
	}
	infile2.close();
	int *rank = new int [rk.size()];
	for (int i = 0; i < int(rk.size()); i++){
		rank[i] = rk[i];
	} 
	saveResult(rank, "Result.txt");
	for (int i = 0; i < 397; i++){ // display the result on screen
		if (rank[i] == 0){
			cout << "\n";	
		} else{
			cout << rank[i] << " ";
		}
	}
	cout << "\nThe average rank is " << answer1;
	return 0;
}

int findRank(string *dictionary, string word){
	int answer;
	bool NotFind = true;
	for (int i = 0; i < 1000; i++){
		if (word == dictionary[i]){ // check each individual word
			answer = i+1;
			NotFind = false;
			break;
		}
	}
	if (NotFind){ // for those not found
		answer2++;
		answer = 1001;
	}
	return answer;
}

void saveResult(int *rank, string outFileName){
	double sum = 0, total = 0;
	ofstream outFile;
	outFile.open(outFileName);
	for (int i = 0; i < 397; i++){ // store the rank in the required format
		if (rank[i] == 0){
			outFile << "\n";	
		} else{
			outFile << rank[i] << " ";
			sum += rank[i];
			total++;
		}
	}
	answer1 = sum/total;
	outFile << "\nThe average rank is " << answer1;
	outFile.close();
}


