/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc97s1
Explanation
-------------------------------------------
We have to create all the possible sentences starting with a subject, follow by a verb and an object.
We can solve this by having 3 neted loop with the subject being the first loop, the verb being the
second loop and the object being the last loop. We can then print out the sentences accordingly with each iteration.

NOTE: The problem did say to put them into alphabetical order,
however there is no such problem where you are require to put the sentences into alphabetical order. 
Hence I did not implement the alg and stil AC.  
*/

//CODE
//-----------------------------------------------
#include <iostream>
#include <string>

int main() {
	// init # of test cases, # of subjects,# of vers,# of objects
	int n, a, b, c;

	std::cin >> n; 

	for (int z = 0; z < n; z++) {
		std::cin >> a >> b >> c;

		std::cin.ignore();  // ignore all the white spaces left behind

		// init lists
		std::string subject[20] = {};
		std::string verb[20] = {};
		std::string obj[20] = {};

		// save into list
		for (int i = 0; i < a; i++) {
			std::getline(std::cin, subject[i]);
		}
		for (int i = 0; i < b; i++) {
			std::getline(std::cin, verb[i]);
		}
		for (int i = 0; i < c; i++) {
			std::getline(std::cin, obj[i]);
		}

		// nested loop to iterate all the subjects,verb and objects
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					std::cout << subject[i] << " " << verb[j] << " " << obj[k] << ".\n";
				}
			}
		}std::cout << "\n";
	}
}