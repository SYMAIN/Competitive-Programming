/*
Author: Simon Yang
Problem: https://dmoj.ca/problem/ccc96s1

Explanation
-------------------------------------------
For each number, loop through all the numbers from 1 to n and sum up all the of divisor of a number.
print out the answer according to the sum

*/

#include <bits/stdc++.h>

void getDivisors(int& n) {
	int cnt = 0;  // init a variable to sum up all the divisor
	for (int i = 1; i < n; i++) {
		if (n % i == 0) // check if the number is a factor
			cnt += i; // add up the divisor
	}
	// compare and print out the answer
	if (cnt == n) 
		std::cout << n << " is a perfect number.\n";
	else if (cnt > n) 
		std::cout << n << " is an abundant number.\n";
	else 
		std::cout << n << " is a deficient number.\n";
}

int main() {
	int n,a; // init number of test cases and the dividend
	std::cin >> n;  // get the number of test cases
	for (int i = 0; i < n; i++) { // loop through the number of test cases
		std::cin >> a;  // get the dividend
		getDivisors(a); // call function
	}
}