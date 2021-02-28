#include <iostream>

int l1[1000];
int l2[1000];

int solve(int x) {
	int max = 0;
	for (int i = 0; i < x; i++) {
		for (int j = x-1; j >= 0; j--) {
			if (l2[j] >= l1[i]) {
				if (j-i > max) {
					max = j-i;
				}
			}
		}
	}return max;
}

int main() {
	int N,x;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> x;
		for (int j = 0; j < x; j++) {
			std::cin >> l1[j];
		}
		for (int j = 0; j < x; j++) {
			std::cin >> l2[j];
		}
		std::cout << "The maximum distance is " << solve(x) << "\n\n";
	}
}