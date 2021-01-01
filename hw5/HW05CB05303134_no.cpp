//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05CB05303134.CPP 
//  DESCRIPTION: This is a program to  find the shortest tour of 
//				 the assigned 4-city case
//================================================================

#include<iostream>
using namespace std;

int answer1;

int main(){
	char tour[][5] = {"ABCDA", "ABDCA", "ACBDA", "ACDBA", "ADBCA", "ADCBA",
						"BACDB", "BADCB", "BCADB", "BDACB",
						"CABDC", "CBADC"};
	int dist[] = {3, 5, 2, 9, 10, 1}; //"AB", "AC", "AD", "BC", "BD", "CD"
	
	int tour_dist[12]={0};
	tour_dist[0] = dist[0] + dist[3] + dist[5] + ;
	tour_dist[1] = dist[0] + dist[4] + dist[5];
	tour_dist[2] = dist[1] + dist[3] + dist[4];
	tour_dist[3] = dist[1] + dist[5] + dist[4];
	tour_dist[4] = dist[2] + dist[4] + dist[3];
	tour_dist[5] = dist[2] + dist[5] + dist[3];
	tour_dist[6] = dist[0] + dist[1] + dist[3];
	tour_dist[7] = dist[0] + dist[2] + dist[5];
	tour_dist[8] = dist[3] + dist[1] + dist[2];
	tour_dist[9] = dist[4] + dist[2] + dist[1];
	tour_dist[10] = dist[1] + dist[0] + dist[4];
	tour_dist[11] = dist[3] + dist[0] + dist[2];
	
	int min = 30;
	for (int i = 0; i < 11; i++){
		cout << tour[i] << ": " << tour_dist[i] << endl;
		if (tour_dist[i]< min){
			min = tour_dist[i];
		}
	}
	cout << min;
	answer1 = min;
	
	return 0;
}
