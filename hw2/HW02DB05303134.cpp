//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-14
//  FILENAME   : HW02DB05303134.CPP 
//  DESCRIPTION: This is a program to calculate the total value of
//				 the hand in the game of blackjack
//=================================================================

#include "iostream"
using namespace std;

int answer1;
int answer2;

int main()
{
	int x, y, z; // store the face value in each card
	cin >> x >> y >> z;
	
	answer2 = x + y + z;
	
	// count the value for face cards
	if (x > 10){
		x = 10;	
	} 
	if (y > 10){
		y = 10;
	}
	if (z > 10){
		z = 10;	
	}
	
	// classify the case for an ace
	answer1 = x + y + z;
	if (x == 1 && y != 1 && z != 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x != 1 && y == 1 && z != 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x != 1 && y != 1 && z == 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x == 1 && y == 1 && z != 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x != 1 && y == 1 && z == 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x == 1 && y != 1 && z == 1 && answer1 <= 11){
		answer1 += 10;
	} else if (x == 1 && y == 1 && z == 1){
		answer1 += 10;
	}
	
	// display the total value
	cout << "The total value of the hand is " << answer1;
	if (answer1 > 21){
		cout << " (bust)." << endl;
	} else{
		cout << "." << endl;
	}
	return 0;
}
