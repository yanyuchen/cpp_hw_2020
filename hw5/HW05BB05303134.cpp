//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05BB05303134.CPP 
//  DESCRIPTION: This is a program to simulate the Game of Life 
//				 for a 20x20 world.
//================================================================

#include<iostream>
using namespace std;

int answer1, answer2, answer3;

int main(){
	int n, a[20][20], b[20][20];
	cout << "Input an interger to decide the number of generation for the simulation: ";
	cin >> n;
	
	for (int i = 0; i < 20; i++){ // initialization
		for (int j = 0; j<20; j++){
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	a[1][2] = a[1][4] = a[2][3] = a[3][3] = a[4][2] = a[4][4] = 1;
	
	for (int i = 0; i < 20; i++){
		for (int j = 0; j<20; j++){
			if (a[i][j] == 1){ // set 1 if alive and 0 if dead; count the total number of live cells of the first generation
				answer1 = answer1 + 1;	
			}
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------" << endl;
	for (int k = 1; k < n; k++){
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				int neighbor = 0; // determine the neighbors of a cell
				if (i - 1 >= 0){ 
					if (j - 1>= 0){
						neighbor += a[i - 1][j - 1];
					}
					if (j + 1 < 20){
						neighbor += a[i - 1][j + 1];
					}
					neighbor += a[i - 1][j];
				}
				if (i + 1 < 20){
					if (j - 1 >= 0){
						neighbor += a[i + 1][j - 1];
					}
					if (j + 1 < 20){
						neighbor += a[i + 1][j + 1];
					}
					neighbor += a[i + 1][j];
				}
				if (j - 1 >= 0){
					neighbor += a[i][j - 1];
				}
				if (j + 1 < 20){
					neighbor += a[i][j + 1];
				}
				if (a[i][j] == 0){ // for the next generation
					if (neighbor == 3){ // any dead cell with exactly three live neighbors comes to life
						b[i][j] = 1;
					} else{
						b[i][j] = 0;
					}
				} else{
					if (neighbor < 2 || neighbor > 3){ // any live cell with fewer than two live neighbors dies, as if by loneliness and any live cell with more than three live neighbors dies, as if by overcrowding
						b[i][j] = 0;
					} else{ // any live cell with two or three live neighbors lives, unchanged, to the next generation
						b[i][j] = 1;
					}
				}
			}
		}
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 20; j++){
				a[i][j] = b[i][j];
				cout << a[i][j] << "  ";
				
				if (a[i][j] == 1 && k == 1){// count the total number of live cells of the second generation
					answer2 = answer2 + 1;
				}
				if (a[i][j] == 1 && k == 2){
					answer3 = answer3 + 1;  // we count the total number of live cells of the third generation
				}
			}
			cout << endl;
		}
		cout << "-------------------------------------------------------" << endl;
	}
	cout << "The total number of live cells of the first generation is " << answer1 << endl;
	cout << "The total number of live cells of the second generation is " << answer2 << endl;
	cout << "The total number of live cells of the third generation is " << answer3 << endl;
	return 0;
}
