#include <bits/stdc++.h>

void getDivisors(int& n) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) cnt += i;
	}if (cnt == n) std::cout << n << " is a perfect number.\n";
	else if (cnt > n) std::cout << n << " is an abundant number.\n";
	else std::cout << n << " is a deficient number.\n";
}

int main() {
	int n,a;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		getDivisors(a);
	}
}