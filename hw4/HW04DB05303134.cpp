//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-11-18
//  FILENAME   : HW04DB05303134.CPP 
//  DESCRIPTION: This is a program that simulates the rolling of 
//				 two dices.
//================================================================

#include <time.h>
#include <iostream>
using namespace std;

double answer1;
double answer2;
int rollDice();

int main()
{
	srand(time(NULL));
	
	for (int i = 0; i <  10000; i++){
		int win, len = 1, a = rollDice();
	
		if (a == 7 || a == 11){ // the case of wining
			win = 1;
		
		} else if (a == 2 || a == 3 || a == 12){ // the case of losing
			win = 0;
		
		} if (a == 4 || a == 5 || a == 6 || a == 8 || a == 9 || a == 10){ // the remaining case
			int b = a;
		
			while (true){ // the second and subsequent runs of games a != 4 && a != 5 && a == 6 && a != 7 && a != 8 && a != 9 && a != 10
				a = rollDice();
				len++;
			
				if (a == 7){ // lose becasure of receive 7 first
					win = 0;
					break;
				
				} else if (a == b){ // win because of receive the point first
					win = 1;
					break;
				
				}
			}
		}

		if (win == 1){
			answer1++; // the total wins in the 10000 games
		}
		answer2 += len; // the total length in the 10000 games
	}
	
	answer1 /= 10000; // the average chance of winning
	answer2 /= 10000; // in average lenght of a single game
	
	cout << "The probability of winning at game of Craps: " << answer1 << endl;
	cout << "The average length of a game of Craps: " << answer2 << endl;
	
	return 0;
}

int rollDice(){
	int a = rand() % 6, b = rand() % 6;
	
	return a + b + 2; // the sum of two dices
}

