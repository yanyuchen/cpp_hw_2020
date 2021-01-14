//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05DB05303134.CPP 
//  DESCRIPTION: This is a Caesar shift cipher decoder program to 
//				 decode the following encrypted sentence 
//				 GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB
//================================================================

#include<iostream>
#include<string>
using namespace std;

int answer1;
char answer2, answer3;

int main(){
	answer1 = 8; // after compiling the below program and considering the meaning of each sentence, we get k=8 is the value of K to decode the encrypted message
	string encry = "GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB"; // input the encrypted sentence
	for (int k = 0; k < 26; k++){ // test for all value of K to decode the encrypted message
		string de = "";
		for (int i = 0; i < int(encry.length()); i++){
			if (encry[i] == ' '){
				de += ' ';
			} else{
				if (encry[i] - k >= 65){ // if after the movement encry[i] is still a capital character, then let encry[i] be the capital character
					de += encry[i] - k;	
				} else { // if not, move to Z and do the rest movement
					de += 91 + (encry[i] - k - 65);
				}
			}
		}
		cout << de;
		cout << "\n-------------------------------------" << endl;;
		if (k == answer1){
			answer2 = de[0];
			answer3 = de[de.length()-1];
		}
	}
	cout << "\nThe first character of the decoded sentence is " << answer2 << endl;
	cout << "The last character of the decoded sentence is " << answer3;
	return 0;
}

