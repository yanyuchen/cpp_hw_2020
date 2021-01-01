//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-14
//  FILENAME   : HW02CB05303134.CPP 
//  DESCRIPTION: This is a program to calculate the score of bowling 
//				 game
//=================================================================

#include "iostream"
using namespace std;

int answer1;
int answer2;

int main()
{
	int x, y, z; // store the number of pin knocked down in each throw
	cin >> x >> y >> z;
	
	if (x < 0 || y < 0 || z < 0){ // nonnegative constraint
		answer2 = 0;
		cout << "Erroneous iput!" << endl;
	} else{
		// classify in each case
		if (x == 10 && y < 10 && y + z < 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout << "The scope is " << answer1 << " (a spare)." << endl;
		} else if (x == 10 && y < 10 && y + z == 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout << "The scope is " << answer1 << " (a strike)." << endl;
		} else if (x == 10 && y == 10 && z < 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout <<  "The scope is " << answer1 << " (a spare)." << endl;
		} else if (x == 10 && y == 10 && z == 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout <<  "The scope is " << answer1 << " (a strike)." << endl;
		} else if (x < 10 && x + y < 10){
			answer1 = x + y;
			answer2 = 1;
			cout <<  "The scope is " << answer1 << " (a blow)." << endl;
		} else if (x < 10 && x + y == 10 && z < 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout <<  "The scope is " << answer1 << " (a spare)." << endl;
		} else if (x < 10 && x + y == 10 && z == 10){
			answer1 = x + y + z;
			answer2 = 1;
			cout <<  "The scope is " << answer1 << " (a strike)." << endl;
		} else{
			answer2 = 0;
			cout << "Erroneous input!" << endl;
		}	
	}
	return 0;
}
