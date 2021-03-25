#include <iostream>
#include <string>

bool check(int n) {
	std::string strn = std::to_string(n);

	for (int i = 0; i < strn.size(); i++) {
		if (strn[i] == '4') {
			return 0;
		}
	}return 1;
}

std::pair<int, int> split(int n) {
	for (int f1 = 0; f1 < n; f1++) {
		int f2 = n - f1;
		if (check(f1) && check(f2)) {
			return { f1,f2 };
		}
	}return { 0,0 };
}

int main() {
	int N;
	std::string n;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string a = "", b = "";
		std::cin >> n;
		
		for (int i = 0; i < n.size(); i++) {
			int digit = n[i] - 48; // convert char to int

			std::pair<int, int> pair = split(digit);
			a += std::to_string(pair.first);
			b += std::to_string(pair.second);
		}std::cout << "Case #" << i + 1 << ": " << a << " " << b << "\n";
	}
}