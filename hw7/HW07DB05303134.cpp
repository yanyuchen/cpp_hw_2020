//================================================================
//  PROGRAMMER : yanyu chen 
//  DATE       : 2021-01_04
//  FILENAME   : HW07DB05303049.CPP 
//  DESCRIPTION: This is a program to solve Sodoku games via a text file
//================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime> // time_t
using namespace std;

int answer1; // store the number of center cell (5,5) of solved puzzle A
int answer2; // store the number of center cell (5,5) of solved puzzle B
int answer3; // store the number of center cell (5,5) of solved puzzle C
 
bool FindUnassignedLocation(int grid[9][9], int &row, int &col);
bool isSafe(int grid[9][9], int row, int col, int num);

bool SolveSudoku(int grid[9][9], int &answer){ // assign values to all unassigned locations
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (row == 4 && col == 4){
            	answer = num;
			}
            if (SolveSudoku(grid, answer))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

bool FindUnassignedLocation(int grid[9][9], int &row, int &col){ // if grid is empty
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}
 
bool UsedInRow(int grid[9][9], int row, int num){ // if the row matches the given number
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInCol(int grid[9][9], int col, int num){ // if the column matches the given number
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num){ // if the 3x3 box matches the given number
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
bool isSafe(int grid[9][9], int row, int col, int num){ // whether it will be legal to assign num to the given row and col
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3 , col - col % 3, num);
}

void printGrid(int grid[9][9]){ // display the solution
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){
        	cout << grid[row][col] << "  ";	
		}
        cout << endl;
    }
}

int main(){
    int grid[9][9] = {0}, i = 0, j = 0, idx = 0, answer;
	ifstream infile;
    infile.open("sudoku.txt");
    string a;
    ofstream outfile;
    outfile.open("Result.txt");
    while (getline(infile, a, '\n')){ // read sudoku.txt
    		string b;
    		stringstream ss(a);
    		j = 0;
    		while (ss >> b){
    			grid[i][j] = stoi(b);
    			j++;
			}
			i++;
			if (i == 9){
				time_t begin, end;
				time (&begin);
				if (SolveSudoku(grid, answer) == true){ // check if grid is solvable
					printGrid(grid); // display the solution
					time (&end);
					double difference = difftime (end,begin); // time difference
					cout << "Computation time: ";
					if (difference == 0){
						cout << "less than 1 sec" << endl;
					} else{
						cout << difference << " sec(s)" << endl;
					}
					cout << endl;
					
					if (idx == 0){
						answer1 = answer;
					} else if (idx == 1){
						answer2 = answer;
					} else if (idx == 2){
						answer3 = answer;
					}
					
					for (int row = 0; row < 9; row++){
        				for (int col = 0; col < 9; col++)
            				outfile << grid[row][col] << "  "; // save the solution in Result.txt
        				outfile << endl;
    				}
    				outfile << "\n";
			} else{
        		cout<<"No solution exists"<<endl;
			}
			i = -1;
			idx++;
			}
	}
	outfile.close();
	infile.close();
    return 0;
}
