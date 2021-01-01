//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-10
//  FILENAME   : HW02AB05303134.CPP 
//  DESCRIPTION: This is a program to determine where is the 
//				 locaiton of a point on the x-y plane
//=================================================================

#include "iostream"
using namespace std;

int answer1; // Store the required number

int main()
{
	double x, y; // the coordinate of a point
	
	cin >> x >> y;
	cout << "The point (" << x << ", " << y << ") is ";
	
	// classify the result in each case
	if (x == 0 && y == 0){
		cout << "on the origin.";
		answer1 = 7;
	} else if (y == 0){
		cout << "on the x-axis.";
		answer1 = 5;
	} else if (x == 0){
		cout << "on the y-axis.";
		answer1 = 6;
	} else if (x > 0 && y > 0){
		cout << "in quadrant I.";
		answer1 = 1;
	} else if (x > 0 && y < 0){
		cout << "in quadrant IV.";
		answer1 = 4;
	} else if (x < 0 && y > 0){
		cout << "in quadrant II.";
		answer1 = 2;
	} else if (x < 0 && y < 0){
		cout << "in quadrant III.";
		answer1 = 3;
	}
	cout << endl;
    return 0;
}
