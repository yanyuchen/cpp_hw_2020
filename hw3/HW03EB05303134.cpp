//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-25
//  FILENAME   : HW03EB05303134.CPP 
//  DESCRIPTION: This is a program that displays all the twin prime 
//				 between 2 and 1000
//=================================================================

#include <cmath>
#include <iostream>
using namespace std;

int answer1, answer2; // Store the largest pair of twin prime less than 1000

int main()
{
	cout << "The twin prime between 3 and 1000: " << endl;
	
	answer1 = 3;
	answer2 = 5;
	for (int i = 3; i <= 1000; i++){ // run over 3 to 1000
		bool a = true;
		for (int j = 2; j <= int(sqrt(i)); j++){ // follow the hint
			if (i % j == 0){ // find the factor of each i
				a = false;
				break;
			}
		}
		if (a && i != answer1 + 2){
			answer1 = i; // the potential twin prime
		} else if (a && i == answer1 + 2){
			answer2 = i; // the second twin prime
			cout << "(" << answer1 << ", " << answer2 << ") ";
			answer1 = i;
		}
	}
	
	// correct the largest pair of twin prime
	if (answer1 == answer2){
		answer1 -= 2;
	} else if (answer1 > answer2){
		answer1 = answer2 - 2;
	}
	return 0;
}
