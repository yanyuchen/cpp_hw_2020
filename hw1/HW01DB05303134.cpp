//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-09-26
//  FILENAME   : HW01DB05303134.CPP 
//  DESCRIPTION: This a program to compute the maximum load in lbs
//				 that can be placed at the end of an 8-foot 2" กั 4"
//				 wooden beam with the stress on the fixed end is
//				 3000 lb/in2
//=================================================================

#include <iostream>
using namespace std;

double answer1; // Store the max load

int main(){	
	// plug the values into the formula
	answer1 = 3000 * 10.67 / (8 * 12 * 2);
	
	cout << "The max load in lbs is " << answer1 << ".";
	return 0;
}
