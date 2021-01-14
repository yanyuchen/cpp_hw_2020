//================================================================
//  PROGRAMMER : Yan-Yu Chen 
//  DATE       : 2020-12-09
//  FILENAME   : HW05AB05303134.CPP 
//  DESCRIPTION: This is a Caesar shift cipher decoder program to 
//				 decode the following encrypted sentence given 
//				 K = 6: O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN
//================================================================

#include<iostream>
#include<string>
#define k 6
using namespace std;

char answer1, answer2;

int main(){
	string encry = "O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN"; // input the encrypted sentence
	for (int i = 0; i < int(encry.length()); i++){
		if (encry[i] != ' '){
			if (encry[i] - k >= 65){ // if after the movement encry[i] is still a capital character, then let encry[i] be the capital character
				encry[i]-= k;
			} else{ // if not, we first move to Z and do the rest movement
				encry[i] = 91 + (encry[i] - k - 65);
			}	
		}
		cout << encry[i];		
	}
	answer1 = encry[0];
	answer2 = encry[encry.length()-1];
	cout << "\n\nThe first character of the decoded sentence is " << answer1 << endl;
	cout << "The last character of the decoded sentence is " << answer2;
	return 0;
}

