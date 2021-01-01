//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-14
//  FILENAME   : HW02BB05303134.CPP 
//  DESCRIPTION: This is a program that encryptes a valid integer 
//				 using the required procedure
//=================================================================

#include "iostream"
using namespace std;

int answer1;
int answer2;
int answer3;
int answer4;
int answer5;

int main()
{
	int x, y; // x is the input integer; y is the encrypted integer
	cin >> x;
	
	if (x < 1000 || x > 9999){
		cout << "The input is out of the range of 1000-9999." << endl;
		answer5 = 0;
	} else{
		int a, b, c, d; // store each digit of the input integer
		
		a = x / 1000;
		b = (x - a * 1000) / 100;
		c = (x - a * 1000 - b * 100) / 10;
		d = x - a * 1000 - b * 100 - c * 10;
		
		// follow the required procedure
		answer2 = (a + 7) % 10;
		answer1 = (b + 7) % 10;
		answer4 = (c + 7) % 10;
		answer3 = (d + 7) % 10;
		y = answer1 * 1000 + answer2 * 100 + answer3 * 10 + answer4;
		
		cout << y << " is the encrypted integer of " << x << endl;
		answer5 = 1;
	}
    return 0;
}
