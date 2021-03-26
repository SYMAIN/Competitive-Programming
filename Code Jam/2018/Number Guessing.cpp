#include <iostream>

int main() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);
	int T,a,b,n, guess;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> a >> b >> n;
		std::string output = "";
		a++;
		while (output != "WRONG_ANSWER") {
			n--;
			guess = (a + b) / 2;
			std::cout << guess << std::endl;

			std::cin >> output;
			if (output == "TOO_SMALL") {
				a = guess + 1;
			}
			else if (output == "TOO_BIG") {
				b = guess - 1;
			}
			if (output == "CORRECT") {
				break;
			}
		}
	}
}