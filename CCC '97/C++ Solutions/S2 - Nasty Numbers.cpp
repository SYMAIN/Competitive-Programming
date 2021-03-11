/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc97s2
Explanation
-------------------------------------------
The problem is asking to find 2 pairs of factors such that the differences of one pair is equal to the sum
of the other pair. We can solve this by finding all the factors of a number using a loop, chcking up to n. Next we can have a nested loop to check all the factors to see if they are a nasty number of not.
*/

//CODE
//-----------------------------------------------
#include <iostream>
#include <vector>

void solve(int n) {
	// find factors and save into a array
	std::vector<std::pair<int, int>> save;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			int f1 = n / i;
			int f2 = i;
			if (f1 > f2) {
				save.push_back({ f1,f2 });
			}
		}
	}

	// nested loop to iterate all the factors and print out answers accordingly
	for (int i = 0; i < save.size(); i++) {
		for (int j = i + 1; j < save.size(); j++) {
			if (save[i].first - save[i].second == save[j].first + save[j].second) {
				std::cout << n << " is nasty\n";
				return;
			}
		}
	}std::cout << n << " is not nasty\n";
}

int main() {
	// get inputs
	int n, a;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> a;
		solve(a);
	}
}