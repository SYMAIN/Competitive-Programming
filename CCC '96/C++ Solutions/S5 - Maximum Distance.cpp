
/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc96s5
Explanation
-------------------------------------------
Given 2 set of numbers, we must find the maxiumum distance between two elements such that the larger
index must contain a value larger or equal to the value of the index. For example if we have a list X
with an index of i and list Y with the index of j, then the maximum distance would be j - i with y[j] 
bigger than or equal to X[i].
*/

//CODE
//-----------------------------------------------
#include <iostream>

// init 2 array to store the 2 list
int l1[1000];
int l2[1000];

int solve(int x) {
	
	int max = 0; // init maximum distance to 0

	for (int i = 0; i < x; i++) { // loop through list 1
		for (int j = x-1; j >= 0; j--) { // loop through list 2
			if (l2[j] >= l1[i]) {  // check constraints
				if (j-i > max) { // check if current differences is greater than greatest 
					max = j-i;  // set differences to greatest
				}
			}
		}
	}return max; // return greatest
}

int main() {
	int N,x; // init number of test cases,and length of list
	std::cin >> N; // get number of test cases
	for (int i = 0; i < N; i++) { // loop through number of test cases
		std::cin >> x; // get length of list
		
		// store values to the list
		for (int j = 0; j < x; j++) { 
			std::cin >> l1[j];
		}
		for (int j = 0; j < x; j++) {
			std::cin >> l2[j];
		}
			
		// print out the maximum distance
		std::cout << "The maximum distance is " << solve(x) << "\n\n";
	}
}