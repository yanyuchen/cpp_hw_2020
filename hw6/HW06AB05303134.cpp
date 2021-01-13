//================================================================
//  PROGRAMMER : yanyu chen
//  DATE       : 2020-12-22
//  FILENAME   : HW06AB05303134.CPP 
//  DESCRIPTION: This is a program to simulate dealing cards to 4 players.
//================================================================

#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

int answer1, answer2, answer3, answer4; // store the total high-card points of the first, second, third, and fourth player in the final run of dealing respectively

class poker
{
private:
	char f[52];
	int card[52], player1[13], player2[13], player3[13], player0[13], cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt0 = 0;
public:
	poker(){
		srand(time(NULL)); // shuffle the deck
		int i, j = 1;
		for (i = 0; i<52; i += 4){
			if (i == 0){
				card[i] = j;
				card[i + 1] = j;
				card[i + 2] = j;
				card[i + 3] = j;
			} else{
				card[i] = 15 - j;
				card[i + 1] = 15 - j;
				card[i + 2] = 15 - j;
				card[i + 3] = 15 - j;
			}
			f[i] = 's';
			f[i + 1] = 'h';
			f[i + 2] = 'd';
			f[i + 3] = 'c';
			j++;
		}
		for (i = 0; i<52; i++){
			int r = 1;
			r = rand() % 4;
			switch (r){
				case 1:{
					if (cnt1 == 13){
						i--;
					} else{
						player1[cnt1] = i;
						cnt1++;
					}
					break;
				} case 2:{
					if (cnt2 == 13){
						i--;
					} else{
						player2[cnt2] = i;
						cnt2++;
					}
					break;
				} case 3:{
					if (cnt3 == 13){
						i--;
					} else{
						player3[cnt3] = i;
						cnt3++;
					}
					break;
				} case 0:{
					if (cnt0 == 13){
						i--;
					} else {
						player0[cnt0] = i;
						cnt0++;
					}
					break;
				}
			}
		}
	}
	
	void show(int num){ // show the player's cards
		ofstream outFile;
		for (int i = 0; i < 13; i++){
			switch (num){
			case 1:
			{	cout << f[player1[i]] << ":";
			switch (card[player1[i]])
			{
			case 1:
				answer2 = answer2 + 4;
				cout << "A";
				outFile << "A";
				break;
			case 11:
				answer2 = answer2 + 1;
				cout << "J";
				outFile << "J";
				break;
			case 12:
				answer2 = answer2 + 2;
				cout << "Q";
				outFile << "Q";
				break;
			case 13:
				answer2 = answer2 + 3;
				cout << "K";
				outFile << "K";
				break;
			default:
				cout << card[player1[i]];
				outFile << card[player1[i]];
				break;
			}
			break;
			}
			case 2:
			{	cout << f[player2[i]] << ":";
			switch (card[player2[i]])
			{
			case 1:
				answer3 = answer3 + 4;
				cout << "A";
				outFile << "A";
				break;
			case 11:
				answer3 = answer3 + 1;
				cout << "J";
				outFile << "J";
				break;
			case 12:
				answer3 = answer3 + 2;
				cout << "Q";
				outFile << "Q";
				break;
			case 13:
				answer3 = answer3 + 3;
				cout << "K";
				outFile << "K";
				break;
			default:
				cout << card[player2[i]];
				outFile << card[player2[i]];
				break;
			}
			break;
			}
			case 3:
			{	cout << f[player3[i]] << ":";
			switch (card[player3[i]])
			{
			case 1:
				answer4 = answer4 + 4;
				cout << "A";
				outFile << "A";
				break;
			case 11:
				answer4 = answer4 + 1;
				cout << "J";
				outFile << "J";
				break;
			case 12:
				answer4 = answer4 + 2;
				cout << "Q";
				outFile << "Q";
				break;
			case 13:
				answer4 = answer4 + 3;
				cout << "K";
				outFile << "K";
				break;
			default:
				cout << card[player3[i]];
				outFile << card[player3[i]];
				break;
			}
			break;
			}
			case 0:
			{	cout << f[player0[i]] << ":";
			switch (card[player0[i]])
			{
			case 1:
				answer1 = answer1 + 4;
				cout << "A";
				outFile << "A";
				break;
			case 11:
				answer1 = answer1 + 1;
				cout << "J";
				outFile << "J";
				break;
			case 12:
				answer1 = answer1 + 2;
				cout << "Q";
				outFile << "Q";
				break;
			case 13:
				answer1 = answer1 + 3;
				cout << "K";
				outFile << "K";
				break;
			default:
				cout << card[player0[i]];
				outFile << card[player0[i]];
				break;
			}
			break;
			}
			}
			cout << " ";
			outFile << " ";
		}
		cout << endl;
		outFile << endl;
	}
};

int main(){
	ofstream outFile;
	outFile.open("CardGame.txt"); // read the file CardGame.txt
	answer1 = answer2 = answer3 = answer4 = 0;
	poker a;
	a.show(0);
	a.show(1);
	a.show(2);
	a.show(3);
	cout << "\nThe high-card points of the first player in the final run of dealing are " << answer1 << endl;
	cout << "The high-card points of the second player in the final run of dealing are " << answer2 << endl;
	cout << "The high-card points of the third player in the final run of dealing are " << answer3 << endl;
	cout << "The high-card points of the fourth player in the final run of dealing are " << answer4 << endl;
	outFile << "\nThe high-card points of the first player in the final run of dealing are " << answer1 << endl;
	outFile << "The high-card points of the second player in the final run of dealing are " << answer2 << endl;
	outFile << "The high-card points of the third player in the final run of dealing are " << answer3 << endl;
	outFile << "The high-card points of the fourth player in the final run of dealing are " << answer4 << endl;
	outFile.close();
	return 0;
}



