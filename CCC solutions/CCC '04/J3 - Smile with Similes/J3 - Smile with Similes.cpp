#include <iostream>
#include <vector>

int main()
{
	int a, n;
	std::vector<std::string> adjs;
	std::vector<std::string> nouns;
	std::string temp;
	std::cin >> a;
	std::cin >> n;

	for (int i = 0; i < a; ++i) {
		std::cin >> temp;
		adjs.push_back(temp);
	}

	for (int i = 0; i < n; ++i) {
		std::cin >> temp;
		nouns.push_back(temp);
	}
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout <<adjs[i] + " as " + nouns[j]<<std::endl;
		}
	}

	std::cin.get();

}