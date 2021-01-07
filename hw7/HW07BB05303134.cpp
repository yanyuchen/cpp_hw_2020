//================================================================
//  PROGRAMMER : yanyu chen
//  DATE       : 2021-01-06
//  FILENAME   : HW07BB05303134.CPP 
// DESCRIPTION : This is a program for movie rating survey analysis.
//================================================================
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int answer1; // store the total number of movies listed in the RatingList.txt file
int answer2 = 0; // store the total number of ratings in the RatingList.txt file
string answer3; // store the movie title with the highest average rating

class MovieReview
{
private:
	string movieTitle;
	double totalScore, numRating, aveScore;
public:
	// constructor
	MovieReview(){
		movieTitle = "";
		totalScore = 0;
		numRating = 0;
		aveScore = 0;
	};
	
	// accessor functions
	string getMovieTitle(){ 
		return movieTitle;
	};
	double getTotalScore(){
		return totalScore;
	};
	double getNumRating(){
		return numRating;
	};
	double getAveScore(){
		return aveScore;
	};
	
	// mutator functions
	void setMovieTitle(string title){
		movieTitle = title;
	};
	void setTotalScore(double score){
		totalScore = score;
	};
	void setNumRating(double num){
		numRating = num;
	};
	void setAveScore(double avgscore){
		aveScore = avgscore;
	};
	
	// add score to the object's total score
	void addScore(double score){
		totalScore += score;
		numRating++;
	};
	// calcuate the average score of the object
	void calculateAveScore(){
		aveScore =  totalScore / numRating;
	};
	// display the result
	void show(){
		cout << movieTitle << endl;
		cout <<  "Total Score: " << totalScore << ", Average Score: " << aveScore << ", Number of Rating: " << numRating << endl;
		cout << endl;
	}
};

MovieReview readData(string title, double score){ // turn the data from the file RatingList.txt into the class MovieReview  
	MovieReview movie;
	movie.setMovieTitle(title);
	movie.setTotalScore(score);
	return movie;
}

int main(){
	MovieReview Movie[20];
	string data;
	int idx = 0;
	ifstream infile;
    infile.open("RatingList.txt"); // read the file RatingList.txt
    while(getline(infile, data, '\n')){
    	answer2++;
    	string title = data.substr(0, data.find('|')-1);
    	double score = stod(data.substr(data.find('|')+2, data.size()));
    	MovieReview movie = readData(title, score); // turn each line of the RatingList.txt into the class MovieReview 
    	bool check = true;
    	if (idx > 0){
    		for (int i = 0; i < idx; i++){
    		if (Movie[i].getMovieTitle() == title){ // check if the movie has been rated previously
    			Movie[i].addScore(score);
    			check = false;
    			break;
			}
		}	
		}
		if (check){
			Movie[idx] = movie;
    		idx++;
		}
		answer1 = idx;
	}
	infile.close();
	
	ofstream outfile;
	outfile.open("RatingResult.txt"); // store the result in the RatingResult.txt
	double max_score = 0;
	for (int i = 0; i < idx; i++){
		Movie[i].calculateAveScore();
		if (Movie[i].getAveScore() > max_score){ // store the movie that has the highest average score
			answer3 = Movie[i].getMovieTitle();
			max_score = Movie[i].getAveScore();
		}
		Movie[i].show(); // display on the screen
		outfile << Movie[i].getMovieTitle() << endl;
		outfile <<  "Total Score: " << Movie[i].getTotalScore() << ", Average Score: " << Movie[i].getAveScore() << ", Number of Rating: " << Movie[i].getNumRating() << endl;
		outfile << endl;
	}
	outfile.close();
	return 0;
}
