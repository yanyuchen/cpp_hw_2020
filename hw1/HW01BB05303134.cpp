//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-09-26
//  FILENAME   : HW01BB05303134.CPP 
//  DESCRIPTION: This is a program to compute the sum and average 
//				 of three numbers
//=================================================================

#include <iostream>
using namespace std;

double answer1, answer2; // Store the sum and average of the three
						 //	numbers respectively
int main(){
	double a, b, c;
	
	cout << "Input three numbers: ";
	cin >> a >> b >> c;
	
	answer1 = a + b + c; // sum
	answer2 = answer1 / 3; // average
	
	// print the each answer in the screen
	cout << "Their sum is " << answer1 << endl;
	cout << "Their average is " << answer2 << endl;
	
	return 0;
}
