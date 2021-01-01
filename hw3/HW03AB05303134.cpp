//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-25
//  FILENAME   : HW03AB05303134.CPP 
//  DESCRIPTION: This is a program to calculate a infiniite polynomial
//				 series with accuracy 1e-3
//=================================================================

#include <iostream>
#include <cmath>
using namespace std;

double answer1; // Store the number of nth term that satisfies the tolerance

int main()
{
	double b_1 = 1, b_2 = 1, A = 0; // A is the finite sum of F(x)
	int n = 1;
	
	// The exact solution is F(x) = x/(1-x-x^2). So, F(1/2)= 2.
	while (2 - A >= 1e-3){
		if (n % 2 == 1){ // the odd term
			A += pow(0.5, n) * b_1;
			b_1 = b_1 + b_2;
			n += 1;
			cout << "The " << n-1 << "th approximation is " << A << " with error " << 2 - A << "." << endl;
		} else if (n % 2 == 0){ // the even term
			A += pow(0.5, n) * b_2;
			b_2 = b_1 + b_2;
			n += 1;
			cout << "The " << n-1 << "th approximation is " << A << " with error " << 2 - A << "." << endl;
		}
	}
	
	// Because we add additional 1 in the last iteration, we substract it to get the smallest n.
	answer1  = n-1;
	return 0;
}
