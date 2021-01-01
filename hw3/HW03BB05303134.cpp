//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-25
//  FILENAME   : HW03BB05303134.CPP 
//  DESCRIPTION: This is a program that shows the prime between
//				 2 and 1000
//=================================================================

#include <cmath>
#include <iostream>
using namespace std;

int answer1; // Store the largest prime before 1000

int main()
{
	cout << "The prime numbers between 2 and 1000: " << endl;
	
	for (int i = 2; i <= 1000; i++){ // run over 2 to 1000
		bool a = true;
		for (int j = 2; j <= int(sqrt(i)); j++){ // follow the hint
			if (i % j == 0){ // find the factor of each i
				a = false;
				break;
			}
		}
		if (a){ // determine if i is prime or not
			cout << i << ' ';
			answer1 = i;	
		}
	}
	return 0;
}
