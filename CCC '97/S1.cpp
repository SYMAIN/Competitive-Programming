#include <iostream>
#include <string>

int main() {
	int n, a, b, c;
	std::cin >> n;
	for (int z = 0; z < n; z++) {
		std::cin >> a >> b >> c;
		std::cin.ignore();
		std::string subject[20] = {};
		std::string verb[20] = {};
		std::string obj[20] = {};
		for (int i = 0; i < a; i++) {
			std::getline(std::cin, subject[i]);
		}
		for (int i = 0; i < b; i++) {
			std::getline(std::cin, verb[i]);
		}
		for (int i = 0; i < c; i++) {
			std::getline(std::cin, obj[i]);
		}


		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					std::cout << subject[i] << " " << verb[j] << " " << obj[k] << ".\n";
				}
			}
		}std::cout << "\n";
	}
}