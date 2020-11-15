#include<iostream>
#include<vector>
#include <climits>

bool checkIn(std::vector<int> seq, int n) {
	for (int i = 1; i < seq.size(); i++) {
		if (seq[i] == n)
			return 1;
	}return 0;
}

std::vector<int> findPattern(int pattern[20],int size) {
	std::vector<int> seq;
	for (int i = 0; i < size - 1; i++) {
		int diff = pattern[i + 1] - pattern[i];
		seq.push_back(diff);
	}

	int end = 0;
	for (int j = end + 1; j < seq.size(); j++) {
		int dex = j % (end + 1);
		if (seq[dex] != seq[j]) {
			end = j;
			continue;
		}if (j == seq.size() - 1) {
			std::vector<int> temp;
			for (int i = 0; i < end + 1; i++)
				temp.push_back(seq[i]);
			return temp;
		}
	}return seq;
}

int main() {
	int pattern[20];
	for (auto& i : pattern)
		i = INT_MAX;
	int a,b;
	std::cin >> a;
 	while (a != 0) {
		for (int i = 0; i < a; i++) {
			std::cin >> b;
			pattern[i] = b;
		}
		std::vector<int> seq = findPattern(pattern, a);
		std::cout << seq.size() << " ";
		std::cout << "\n";
		for (auto &i : pattern)
			i = INT_MAX;
		std::cin >> a;
	}
}