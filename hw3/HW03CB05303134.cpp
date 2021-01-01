//=================================================================
//  PROGRAMMER : yan-yu chen
//  DATE       : 2020-10-25
//  FILENAME   : HW03CB05303134.CPP 
//  DESCRIPTION: This is a program that finds the longest recurring 
// 				 cycle in the decimal fraction part of 1/d for 
//				 d < 5000
//=================================================================

#include <iostream>

using namespace std;

int answer1; // store the number that has the max length of the cycle

int main()
{	
	int max_n = 0; // store the max length of the cycle
	
	for (int i = 2; i < 5000; i++){
		int q = 1, cnt2 = 0, cnt5 = 0, P, n = 0;
		
		// facteroize the factor 2 and 5 from each i
		P = i;
    	while(P % 2 == 0 && P != 0){
       		P /= 2;
			cnt2 += 1;
		}
    	while(P % 5 == 0 && P != 0){
       		P /= 5;
       		cnt5 += 1;
		}
		
		// calculate the remainder of the non-recurring digit
		for(int j = 0; j < max(cnt2, cnt5); j++){
        	q *= 10;
        	q %= i;
    	}
    
    	// if the remainder is not zero, find the length of the recurring cycle.
    	P = q;
    	if (q != 0){
    		do {
    			q *= 10;
    			q %= i;
    			n += 1;
			} while (q != P);
		}
		
		// compare the length with the previous max_n
		max_n = n > max_n ? n : max_n;
		if (max_n == n){
			answer1 = i;
		}	
	}
	
	cout << "The number " << answer1 <<" has the longest recurring circle of 1/i for i from 2 to 4999." << endl;
	cout << "Its length is " << max_n << ".";
	return 0;
}
