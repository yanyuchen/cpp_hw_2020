//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05DB05303134.CPP 
//  DESCRIPTION: This is a Caesar shift cipher decoder program to 
//				 decode the following encrypted sentence 
//				 GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB
//================================================================

#include<iostream>
using namespace std;

char encry[32];
int i, k, answer1;
char answer2, answer3;

int main()
{
	answer1 = 8; // after compiling the below program and considering the meaning of each sentence, we get k=8 is the value of K to decode the encrypted message
	for (k = 0; k < 26; k++) // test for all value of K to decode the encrypted message
	{
		char encry[] = "GWCIZMZMITTGIPIZLEWZSQVOABCLMVB"; // input the encrypted sentence GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB
		for (i = 0; i < 31; i++)
		{
			if (encry[i] - k >= 65) // if after the movement encry[i] is still a capital character, then let encry[i] be the capital character
				encry[i] = encry[i] - k;
			else // if not, we first move to Z and do the rest movement
				encry[i] = 91 + (encry[i] - k - 65);
			cout << encry[i] << " ";
			if (k == answer1) 
			{
				answer2 = encry[0];
				answer3 = encry[30];
			}
		}
		cout << "\n -------------------------------------------------------------" << endl;
	}

	cout << "\nthe first character of the decoded sentence is " << answer2 << endl;
	cout << "the last character of the decoded sentence is " << answer3 << endl;
	return 0;
}

