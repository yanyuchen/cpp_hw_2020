//  PROGRAMMER : Yan-Yu Chen
//  DATE       : 2020-12-09
//  FILENAME   : HW05EB05303134.CPP 
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
	char tour[6];
	int dist_sum, min_dist, min = 4*10;
	int J, K, L;
	// distances 3, 5, 2, 9, 10, 1 for "AB", "AC", "AD", "BC", "BD", "CD", respectively
	dist["AB"] = dist["BA"] = 3;
	dist["AC"] = dist["CA"] = 5;
	dist["AD"] = dist["DA"] = 2;
	dist["BC"] = dist["CB"] = 9;
	dist["BD"] = dist["DB"] = 10;
	dist["CD"] = dist["DC"] = 1;
	
	cout << "The four nearest visiting tours and their distance are as follows: " << endl;
	for (int i = 0; i< 4; i++){ // the first city that starts in each iteration
		min_dist = 10;
		dist_sum = 0;
		for (int j = 0; j < 4; j++){ // the second city that is nearest to the first one
			if (i != j){
				char pth[3] = {city[i], city[j]};
				if (dist[pth] < min_dist){
					J = j;
					tour[0] = tour[4] = city[i];
					tour[1] = city[j];
					min_dist = dist[pth];
				}
			}
		}
		dist_sum += min_dist; // sum over the distances of each city
		min_dist = 10;
		for (int k = 0; k < 4; k++){ // the third city that is nearest to the second one
			if (i != k && J != k){
				char pth[3] = {city[J], city[k]};
				
				if (dist[pth] < min_dist){
					K = k;
					tour[2] = city[k];
					min_dist = dist[pth];
				}
			}
		}
		dist_sum += min_dist; // sum over the distances of each city
		min_dist = 10;
		for (int l = 0; l < 4; l++){ // the last city that is nearest to the third one
			if (l != i && l != J && l != K){
				char pth[3] = {city[K], city[l]};
				if (dist[pth] < min_dist){
					L = l;
					tour[3] = city[l];
					min_dist = dist[pth];
				}						
			}
		}
		dist_sum += min_dist; // sum over the distances of each city
		
		char pth[3] = {city[L], city[i]};
		dist_sum += dist[pth]; // the distance from the last city to the first one
		tour[5] = '\0';
		cout << tour << ": " << dist_sum << endl;
		if (dist_sum < min){ // choose the min distance one
			min = dist_sum;
		}
	}
	cout << "\nThe shortest distance is: " << min;
	answer1 = min;
	return 0;
}
