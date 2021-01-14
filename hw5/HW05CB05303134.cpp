//================================================================
//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05CB05303134.CPP 
//  DESCRIPTION: This is a program to  find the shortest tour of 
//				 the assigned 4-city case
//================================================================

#include<iostream>
#include<map>
using namespace std;

int answer1;

int main(){
	map<string, int> dist; // references for pairs of cities
	char city[] = "ABCD";
	int dist_sum, min= 10*4;
	// distances 3, 5, 2, 9, 10, 1 for "AB", "AC", "AD", "BC", "BD", "CD", respectively
	dist["AB"] = dist["BA"] = 3;
	dist["AC"] = dist["CA"] = 5;
	dist["AD"] = dist["DA"] = 2;
	dist["BC"] = dist["CB"] = 9;
	dist["BD"] = dist["DB"] = 10;
	dist["CD"] = dist["DC"] = 1;
	
	cout << "All the possible tours and their distance: " << endl;
	for (int i = 0; i< 4; i++){
		for (int j = 0; j < 4; j++){
			if (i != j){
				for (int k = 0; k < 4; k++){
					if (i != k && j != k){
						for (int l = 0; l < 4; l++){
							if (l != i && l != j && l != k){
								char tour[6] = {city[i], city[j], city[k], city[l], city[i]}; // each tour
								dist_sum = 0;
								for (int m = 0; m < 5; m++){
									char pth[3] = {tour[m], tour[m+1]}; // path between the city in the tour
									dist_sum += dist[pth]; // sum over the distances of each city
								}
								if (min > dist_sum){
									min = dist_sum; // choose the min distance one
								}
								cout << tour << ": " << dist_sum << endl;
							}
						}	
					}
				}	
			}
		}
	}
	cout << "\nThe miniance distance is " << min << " with the tour(s): " << endl;;
	for (int i = 0; i< 4; i++){
		for (int j = 0; j < 4; j++){
			if (i != j){
				for (int k = 0; k < 4; k++){
					if (i != k && j != k){
						for (int l = 0; l < 4; l++){
							if (l != i && l != j && l != k){
								char tour[6] = {city[i], city[j], city[k], city[l], city[i]}; // each tour
								dist_sum = 0;
								for (int m = 0; m < 5; m++){
									char pth[3] = {tour[m], tour[m+1]}; // path between the city in the tour
									dist_sum += dist[pth]; // sum over the distances of each city
								}
								if (min == dist_sum){
									cout << tour << " "; // choose the min distance one
								}
							}
						}	
					}
				}	
			}
		}
	}
	answer1 = min;
	return 0;
}
