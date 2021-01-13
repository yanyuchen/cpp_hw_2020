//================================================================
//  PROGRAMMER : yanyu chen
//  DATE       : 2021-01-06
//  FILENAME   : HW07CB05303134.CPP 
//  DESCRIPTION: This is a program to use the K-means algorithm 
//				 to label the data and saved them into a new text
//				 file named Iris.out with three labels
//================================================================

#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<string>
#include<time.h>
#define k 3 // predefine the number of clusters k = 3
using namespace std;

int answer1; // store the number of data in cluster A
int answer2; // store the number of data in cluster B
int answer3; // store the number of data in cluster C

struct Tuple { // store the data from the file Iris.data
	int attr0;
	double attr1, attr2;
	string attr3;
};
 
double getDisXY(Tuple t1, Tuple t2) { // calculate the distance
	double dis = sqrt((t1.attr1 - t2.attr1)*(t1.attr1 - t2.attr1) + (t1.attr2 - t2.attr2)*(t1.attr2 - t2.attr2));
	return dis;
}

int clusterOfTuple(Tuple means[], Tuple tuple) { // label the cluster based on the given means[]
	double dis = getDisXY(means[0], tuple);
	int label = 0; // indicate the label
	for (int i = 1; i < k; i++) {
		double tmp = getDisXY(means[i], tuple);
		if (tmp < dis) { // choose the closest one
			label = i;
			dis = tmp;
		}
	}
	return label;
}

double getVar(Tuple means[], vector<Tuple> cluster[]) { // get the square loss in the cluster
	double var = 0;
	for (int i = 0; i < k; i++) {
		vector<Tuple> t = cluster[i];
		for (int j = 0; j < int(t.size()); j++) {
			var = var + getDisXY(means[i], t[j]);
		}
	}
	return var;
}
 
Tuple getMeans(vector<Tuple> cluster){ // get the mean of the cluster
	double means1 = 0, means2 = 0;
	int num = cluster.size();
	Tuple t;
	for (int i = 0; i < num; i++) {
		means1 += cluster[i].attr1;
		means2 += cluster[i].attr2;
	}
	t.attr1 = means1/num; 
	t.attr2 = means2/num;
	return t;
}
 

void KMeans(vector<Tuple> tuples){
	vector<Tuple> clusters[k];
	Tuple means[k];
	int rand_num[3];
	for (int i = 0; i < k; i++) { // initialize the cluster centers at random
		rand_num[i] = rand() % tuples.size();
		means[i] = tuples[rand_num[i]];
	}
	int label = 0;
	for (int i = 0; i < int(tuples.size()); i++) { // the initial labels based on the means
		label = clusterOfTuple(means, tuples[i]);
		clusters[label].push_back(tuples[i]);
		tuples[i].attr0 = label;
	} 
	double oldVar = -1, newVar = getVar(means, clusters);
	while (abs(oldVar - newVar) >= 0.0001) { // terminal condition for the kmeans algorithm
		for (int i = 0; i < k; i++) {
			means[i] = getMeans(clusters[i]);
		}
		oldVar = newVar;
		newVar = getVar(means, clusters); // calculate the new error loss
		for (int i = 0; i < k; i++) {
			clusters[i].clear();
		}
		for (int i = 0; i< int(tuples.size()); i++) { // relabel the data based on the new menas
			label = clusterOfTuple(means, tuples[i]);
			clusters[label].push_back(tuples[i]);
			tuples[i].attr0 = label;
		}
	}
	ofstream outfile;
    outfile.open("iris.out"); // output the data in the file iris.out
	cout << "Display the label for the data: " << endl;
	for (int i = 0; i < int(tuples.size()); i++){
		if (tuples[i].attr0 == 0){
			cout << "A" << endl;
			outfile << "A" << endl;
		} else if (tuples[i].attr0 == 1){
			cout << "B" << endl;
			outfile << "B" << endl;
		} else if (tuples[i].attr0 == 2){
			cout << "C" << endl;
			outfile << "C" << endl;
		}
	}
	cout << endl;
	outfile << endl;
	cout << "Centroids: " << endl;
	for (int i = 0; i < k; i++){
		vector<Tuple> t = clusters[i];
		if(i == 0){
        	answer1 = t.size();
        	cout << "A: ";
        	outfile << "A: ";
		} else if (i == 1){
			answer2 = t.size();
			cout << "B: ";
			outfile << "B: ";
		} else if (i == 2){
			answer3 = t.size();
			cout << "C: ";
			outfile << "C: ";
		}
		cout << means[i].attr1 << " " << means[i].attr2 << endl;
		outfile << means[i].attr1 << " " << means[i].attr2 << endl;
	}
	cout << endl;
	outfile << endl;
	cout << "The number of data in each cluster: " << endl;
	outfile << "The number of data in each cluster: " << endl;
	cout << "A: " << answer1 << ", B: " << answer2 << ", C: " << answer3;
	outfile << "A: " << answer1 << ", B: " << answer2 << ", C: " << answer3;
	outfile.close();
}
 
int main() {
	srand(time(NULL));
 	ifstream infile;
	infile.open("iris.data");
	int count = 0;
	vector<Tuple> tuples;
	Tuple tuple;
	while (!infile.eof()) { // read the data from the file iris.data
		count++;
		if (count % 3 == 1){
			infile >> tuple.attr3;
		} else if (count % 3 == 2){
			infile >> tuple.attr1;
		} 
		else {
			infile >> tuple.attr2;
			tuples.push_back(tuple);
		}
	}
	infile.close();
	KMeans(tuples); // implement the kmeans algorithm
	return 0;
} 
