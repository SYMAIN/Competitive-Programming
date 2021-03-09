/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc96s3
Explanation
-------------------------------------------
for each test case, we are require to find all the possible permutations of a number. For example 
ABC.
All possible permutations are
ABC
ACB
BCA
BAC
CAB
CBA

To calculate the permutation of a given set, we can perform a recursion until we have found
all the possible solutions. In our recursion, we must check if our current set has already 
been visited, if not we save our current set for future reference to check. Next, we must 
iterate through the set starting at index 1(because we do not want to swap itself) until 
the end of the set. For every iteration, we would create a copy of the set and swap out 
the first element of the set(index 0) and the current index of set(define by the loop). 
For example ABC, if the current index is 2, we would swap the first element and the 2 index
of set, giving us CBA.
Lastly, we recur the function again, passing our new set as a parameter.

In our inputs we given a certain numbers of 1s, 0s and the length of the set. 
We first construct an array holding all the numbers such that we satisfied the requirement. 
Next, we calculate all the possible permutations using the method explained above and print out the array accordingly.
*/

//CODE
//-----------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

// permutation recursion function 
void solve(std::vector<int> arry, std::vector<std::vector<int>>& save) {
	// check for reoccurrences of the current set
	if (std::find(save.begin(), save.end(), arry) == save.end()) {
		save.push_back(arry); // not in set, save it

		for (int i = 1; i < arry.size(); i++) { // iterate through the set
			std::vector<int> refine(arry); // create a copy of the set

			// swap the first element and index element
			int temp = refine[0];
			refine[0] = refine[i];
			refine[i] = temp;

			// call the function again
			solve(refine, save);
		}
	}
}

int main() {
	int A,n,k; // init variables for test cases, length and number of 1s
	std::cin >> A; // get the number of test cases

	for (int i = 0; i < A; i++) { // loop through the number of test cases
		std::cin >> n >> k; // get the length and the number of 1s

		// contrust an array with the require amounts
		std::vector<int> arry(n);
		for (int i = 0; i < k; i++) {
			arry[i] = 1;
		}for (int i = k; i < n - k; i++) {
			arry[i] = 0;
		}
		
		std::vector<std::vector<int>> save; // array to save all the possible solution
		solve(arry, save); // call function
		
		// -------------------------------------------------
		// converting all the possible solution to a string and sorting it from greatest to smallest
		std::vector<std::string> a;
		for (int i = 0; i < save.size(); i++) {
			std::string t;
			for (int j = 0; j < save[i].size(); j++) {
				t += std::to_string(save[i][j]);
			}
			a.push_back(t);
		}
		std::sort(a.begin(), a.end(),std::greater<std::string>());
		// -------------------------------------------------

		// print out the patterns
		std::cout << "The bit patterns are" << "\n";
		for (int i = 0; i < a.size(); i++) {
			std::cout << a[i] << "\n";
		}

		std::cout << "\n";
	}
}