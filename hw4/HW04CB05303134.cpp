//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020/11/18
//  FILENAME   : HW04CB05303134.CPP 
//  DESCRIPTION: This is a program to create a table of greatest 
//				 common divisor of paired integers from 1 to 20.
//================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int gcd(int a, int b);
int i, j;
int ans[20][20];
int answer1;
int answer2;
int answer3;

int main()
{
	cout << "       1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20" << endl;
	cout << "==================================================================" << endl;
	for (i = 0; i < 20; i++) 
	{
		cout <<setw(2)<< i+1 << " |  "; 
		for (j = 0; j < 20; j++)
		{
			ans[i][j] = gcd((i + 1), (j + 1)); // let the value of row i and column j be the gcd(i+1,j+1)

			cout << setw(2) << ans[i][j] << " ";
		}
		cout << " " << endl;
	}
	answer1 = ans[4][14]; // answer1 = gcd(5,15)
	answer2 = ans[1][12]; // answer2 = gcd(2,13)
	answer3 = ans[5][11]; // answer3 = gcd(6,12)
	return 0;
}


int gcd(int a, int b)
{
	int c;
	if (a > b) // use Euclidean algorithm to compute gcd
	{
		while (a != 0 && b != 0)
		{
			a = a%b; 
			if (a == 0) // if a mod b=0, then b is the gcd
			{
				c = b;
			}
			else
			{
				b = b%a; // if a!=0, then let b mod a and store the value of a to c. if a=c=0, then we stop the loop and get the gcd.
				c = a;
			}
		}
	}
	if (a <= b) // similar to the above case
	{
		while (a != 0 && b != 0)
		{
			b = b%a;
			if (b == 0)
			{
				c = a;
			}
			else
			{
				a = a%b;
				c = b;
			}
		}
	}
	//if (a == b) 
	//{
	//	c = a;
	//}
	return c;
}
