//================================================================
//  PROGRAMMER : Yan-Yu Chen 
//  DATE       : 2020-12-09
//  FILENAME   : HW05AB05303134.CPP 
//  DESCRIPTION: This is a Caesar shift cipher decoder program to 
//				 decode the following encrypted sentence given 
//				 K = 6:O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN
//================================================================

#include<iostream>
using namespace std;

char encry[31];
int i, k;
char answer1, answer2;

int main()
{
	char encry[] = "ORUBKIUSVAZKXVXUMXGSSOTMYUSAIN"; // input the encrypted sentence O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN
	k = 6; 
	for (i = 0; i < 30; i++)
	{
		if (encry[i] - k >= 65) // if after the movement encry[i] is still a capital character, then let encry[i] be the capital character
			encry[i] = encry[i] - k;
		else // if not, we first move to Z and do the rest movement
			encry[i] = 91 + (encry[i] - k - 65);
		cout << encry[i] << " ";		
	}
	answer1 = encry[0];
	answer2 = encry[29];
	cout << "\nthe first character of the decoded sentence is " << answer1 << endl;
	cout << "the last character of the decoded sentence is " << answer2 << endl;
	return 0;
}

