//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020/11/18
//  FILENAME   : HW04BB05303134.CPP 
//  DESCRIPTION: This is a program to calculate the matrix 
//				 multiplication
//================================================================

#include <iostream>
#include <iomanip>
using namespace std;

double answer1;
void multiplyMatrices(double [20][20], double [20][20], double [20][20], int, int, int, int);
void display(double mult[20][20], int, int);

int main()
{
	// The given matrices A & B
	double A[3][4] = {
		{2.1, 3.1, 6.7, 7.1},
		{5.0, 3.0, 4.2, 2.2},
		{3.3, 4.4, 5.5, 0.5}
	};
	double B[4][5]= {
		{1.0, 1.1, 7.7, 2.1, 4.4},
		{2.2, 2.3, 2.3, 8.6, 3.3},
		{7.5, 8.1, 2.4, 9.2, 0.7},
		{9.1, 2.3, 9.9, 0.5, 0.9}
	};
	double c[20][20] = {0}, a[20][20] = {0}, b[20][20] = {0};
	
	// assign the values of A & B into 20 x 20 2-D arrays, a and b
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			a[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j ++){
			b[i][j] = B[i][j];
		}
	}
	
    // calculate c= a * b
    multiplyMatrices(a, b, c, 3, 4, 4, 5);

    // display the matrix c
    display(c, 3, 5);
    
    // store the sum of all elements in the matirx c
    answer1 = 0;
    for (int i = 0; i < 20; i++){
    	for (int j = 0; j < 20; j++){
    		answer1 += c[i][j];
		}
	}
	
	cout << "The sum of all elements in the matrix C is " << answer1 << "." << endl;
	return 0;
}


void multiplyMatrices(double A[20][20], double B[20][20], double C[20][20], int row_A, int column_A, int row_B, int column_B)
{
	// Initialize elements of matrix C to 0
	for(int i = 0; i < row_A; ++i)
	{
		for(int j = 0; j < column_B; ++j)
		{
			C[i][j] = 0;
		}
	}

	// Multiply matrices A and B and store in the array C
	for(int i = 0; i < row_A; ++i)
	{
		for(int j = 0; j < column_B; ++j)
		{
			for(int k=0; k<column_A; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void display(double C[20][20], int row_A, int column_B)
{
	cout << "Their multiplication:" << endl;
	for(int i = 0; i < row_A; ++i)
	{
		for(int j = 0; j < column_B; ++j)
		{
			cout << setw(6) << C[i][j] << " ";
			if(j == column_B - 1){ // turn to the next row
				cout << endl << endl;
			}
		}
	}
}
