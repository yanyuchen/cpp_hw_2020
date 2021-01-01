//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05BB05303134.CPP 
//  DESCRIPTION: This is a program to simulate the Game of Life 
//				 for a 20x20 world.
//================================================================

#include<iostream>
using namespace std;

int neighbor;
int k, i, j, a[20][20], n, b[20][20];
int answer1, answer2, answer3;

int main()
{
	cout << "please input an interger to decide the number of generation for the simulation" << endl;
	cin >> n;
	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	a[1][2] = 1;
	a[1][4] = 1;
	a[2][3] = 1;
	a[3][3] = 1;
	a[4][2] = 1;
	a[4][4] = 1;
	for (i = 0; i<20; i++)
	{
		for (j = 0; j<20; j++)
		{
			if (a[i][j] == 1) // we set 1 is alive and 0 is dead, we count the total number of live cells of the first generation
				answer1 = answer1 + 1;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------" << endl;
	for (k = 1; k<n; k++)
	{
		for (i = 0; i<20; i++)
		{
			for (j = 0; j<20; j++)
			{
				neighbor = 0;
				if (i - 1 >= 0) // determine the neighbors of a cell
				{
					if (j - 1 >= 0)
					{
						neighbor += a[i - 1][j - 1];
					}
					if (j + 1<20)
					{
						neighbor += a[i - 1][j + 1];
					}
					neighbor += a[i - 1][j];
				}
				if (i + 1<20) // determine the neighbors of a cell
				{
					if (j - 1 >= 0)
					{
						neighbor += a[i + 1][j - 1];
					}
					if (j + 1<20)
					{
						neighbor += a[i + 1][j + 1];
					}
					neighbor += a[i + 1][j];
				}
				if (j - 1 >= 0) // determine the neighbors of a cell
				{
					neighbor += a[i][j - 1];
				}
				if (j + 1<20) // determine the neighbors of a cell
				{
					neighbor += a[i][j + 1];
				}
				if (a[i][j] == 0)
				{
					if (neighbor == 3) // any dead cell with exactly three live neighbors comes to life
					{
						b[i][j] = 1;
					}
					else
					{
						b[i][j] = 0;
					}
				}
				else
				{
					if (neighbor<2 || neighbor>3) // any live cell with fewer than two live neighbors dies, as if by loneliness and any live cell with more than three live neighbors dies, as if by overcrowding
					{
						b[i][j] = 0;
					}
					else // any live cell with two or three live neighbors lives, unchanged, to the next generation.
					{
						b[i][j] = 1;
					}
				}
			}
		}
		for (i = 0; i<20; i++)
		{
			for (j = 0; j<20; j++)
			{
				a[i][j] = b[i][j];
				cout << a[i][j] << " ";
				if (a[i][j] == 1 && k == 1) // we count the total number of live cells of the second generation
					answer2 = answer2 + 1;
				if (a[i][j] == 1 && k == 2) // we count the total number of live cells of the third generation
					answer3 = answer3 + 1;
			}
			cout << endl;
		}
		cout << "-------------------------------------------------------" << endl;
	}
	cout << "the total number of live cells of the first generation is " << answer1 << endl;
	cout << "the total number of live cells of the second generation is " << answer2 << endl;
	cout << "the total number of live cells of the third generation is " << answer3 << endl;
	system("pause");
	return 0;
}
