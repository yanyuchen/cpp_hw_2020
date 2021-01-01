//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-11-01
//  FILENAME   : HW03DB05303134.CPP 
//  DESCRIPTION: This is a program to play Rock-Paper-Scissors game 
//				 against computer
//=================================================================

#include <iostream>
#include <time.h>

using namespace std;

int answer1; // store the total number of rounds

int main()
{
	int a = 0, b = 0; // score
	answer1 = 0;	
    
    while (a != 3 && b != 3){
    	char x; // for player
    	int y; // for computer
    	
    	cout << "Input R, S, or P to start: ";
    	cin >> x;
    	srand(time(NULL));
    	y = rand() % 3;
    	answer1 += 1;
    	
    	// player's move
    	cout << "Round " << answer1 << ": You choose a ";
    	if (x == 'R'){
    		cout << "Rock, ";
		} else if (x == 'S'){
			cout << "Scissor, ";
		} else if (x == 'P'){
			cout << "Paper, ";
		}
		
		// computer's move
		cout << "and the computer chooses a ";
		if (y == 0){
    		cout << "Rock. ";
		} else if (y == 1){
			cout << "Scissor. ";
		} else if (y == 2){
			cout << "Paper. ";
		}
		
    	// choose the winner or a draw
    	if ((x == 'R' && y == 0) || (x == 'S' && y == 1) || (x == 'P' && y == 2)){
    		cout << "It is a draw." << endl;
		} else if ((x == 'R' && y == 1) || (x == 'S' && y == 2) || (x == 'P' && y == 0)){
			cout << "You win." << endl;
			a += 1;
		} else if ((x == 'R' && y == 2) || (x == 'S' && y == 0) || (x == 'P' && y == 1)){
			cout << "You lose." << endl;
			b += 1;
		}
		cout << "Your score: " << a << ". The computer's score: " << b << endl;	
	}
	
	// show the result
	cout << "Afer " << answer1 <<  " rounds, the winer is ";
	if (a == 3){
		cout << "you. ";
	} else if (b ==3){
		cout << "the computer.";
	}
	return 0;
}
