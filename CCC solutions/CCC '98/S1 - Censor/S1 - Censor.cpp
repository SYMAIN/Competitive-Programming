/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc98s1
Explanation
-------------------------------------------
In this problem, we are asked to censor or replace all 4 letter words with '*'s. We can acomplish this by
spliting the inputs by spaces, while also keeping track of each word. Then we replace anywords that are
4 letters long.
*/

//CODE
//-----------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>

int main() {
	int n;
	std::string a;
	std::cin >> n;
	std::cin.ignore();

	// loop through test cases
	for (int i = 0; i < n; i++) {
		// get the entire line 
		getline(std::cin, a);
		std::string word = "";

		// loop through the line count words by finding spaces
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == ' ') {

				// check if word is 4 letters long 
				if (word.length() == 4)
					a = a.substr(0, j - 4) + "**** " + a.substr(j + 1);  // replace word in the line
				word = "";
				continue;
			}word += a[j];
		}
		// replace word at the end
		if (word.length() == 4)
			a = a.substr(0, a.size() - 4) + "****";

		std::cout << a << " \n";
	}
}