//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-09-26
//  FILENAME   : HW01CB05303134.CPP 
//  DESCRIPTION: This is a program to compute the returned frequency
//				 corresponding to 55 mph
//=================================================================

#include "iostream"
using namespace std;

double answer1; // Store the returned frequency

int main()
{
	double speed, fe, fr; //declare speed, emitted waves' frequency, and reflected frequency
	
 	fe = 2e10;
 	speed = 55;
 	fr =  fe * (6.685e8 + speed) / ( 6.685e8 - speed); // plug each variables in the formula
 	answer1 = fr;
 	
 	cout << "The returned frequency corresponding to 55 mph is " << fr;
    return 0;
}
