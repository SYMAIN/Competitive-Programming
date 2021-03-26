#include <iostream>

int main() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	int N, n;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::string lydia;
		std::cin >> n;
		std::cin >> lydia;

		std::string current = "";
		for (int j = 0; j < lydia.size(); j++) {
			if (lydia[j] == 'E') {
				current += 'S';
			}
			else if (lydia[j] == 'S') {
				current += 'E';
			}
		}std::cout << "Case #" << i + 1 << ": " << current << "\n";
	}
}