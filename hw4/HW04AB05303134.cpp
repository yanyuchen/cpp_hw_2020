//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020/11/18
//  FILENAME   : HW04AB05303134.CPP 
//  DESCRIPTION: This is a program to find all perfect numbers 
//				 between 1 and 10000 by calling the function 
//				 PerfectNumber(long int Num).
//================================================================

#include <iostream>
using namespace std;

int answer1;
int i, j;
long int k,m;
int PerfectNumber(long int Num); // function prototype

int main()
{
	for (k = 1; k < 10000 ; k++) // start from 1 to 10000, use the function PerfectNumber to test determines whether the supplied number k is a perfect number.
 	{
		if (PerfectNumber(k) == 1) // if PerfectNumber(k) is 1, then the number is perfect number
		{
			answer1 = k; // since the last k is the largest perfect number among 1 to 10000, the answer1 is the largest perfect number less than 10000
			cout << k << " is a perfect number." << endl;
		}
	}
	cout << answer1 << " is the largest perfect number less than 10000." << endl;
	return 0;
}


int PerfectNumber(long int Num) 
{
	j = 0;
	for (i = 1 ; i < Num ; i++) // find all factors of Num which are less than Num
	{
		if (Num % i == 0) // if Num is divided by i, then store i and then sum all this kind of i
		{
			j = j + i;
		}
	}
	if (j == Num) // if j equals to Num, then it is a perfect number and thus return 1
	{
		return 1;
	}
	else
	{
		return 0; // if j doesn't equal to Num, then it is not a perfect number and thus return 0
	}
}

