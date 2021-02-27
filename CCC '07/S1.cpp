#include <iostream>

bool solve(int y, int m, int d) {
	int currentY = 2007;
	int currentM = 02;
	int currentD = 27;

	if (currentY - y > 18) {
		return 1;
	}
	else if (currentY - y == 18) {
		if (m < currentM) {
			return 1;
		}
		else if (m == currentM) {
			if (d < currentD) {
				return 1;
			}
			else if (d == currentD) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}return 0;
}

int main() {
	int N, y, d, m;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> y >> m >> d;
		if (solve(y, m, d)) {
			std::cout << "Yes\n";
		}
		else {
			std::cout << "No\n";
		}
	}
}