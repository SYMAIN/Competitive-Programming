#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

void solve(std::vector<int> arry, std::vector<std::vector<int>>& save) {
	if (std::find(save.begin(), save.end(), arry) == save.end()) { // not in save
		save.push_back(arry);
		for (int i = 1; i < arry.size(); i++) {
			std::vector<int> refine(arry);
			int temp = refine[0];
			refine[0] = refine[i];
			refine[i] = temp;
			solve(refine, save);
		}
	}
}

int main() {
	int A,n,k;
	std::cin >> A;
	for (int i = 0; i < A; i++) {
		std::cin >> n >> k;

		std::vector<int> arry(n);
		for (int i = 0; i < k; i++) {
			arry[i] = 1;
		}for (int i = k; i < n - k; i++) {
			arry[i] = 0;
		}
		std::cout << "The bit patterns are" << "\n";
		std::vector<std::vector<int>> save;
		std::unordered_map<int, std::string> temp;
		std::vector<int> a;
		solve(arry, save);

		for (int i = 0; i < save.size(); i++) {
			std::string t;
			for (int j = 0; j < save[i].size(); j++) {
				t += std::to_string(save[i][j]);
			}
			temp[std::stoi(t, 0, 2)] = t;
			a.push_back(std::stoi(t, 0, 2));
		}
		std::sort(a.begin(), a.end(),std::greater<int>());

		for (int i = 0; i < a.size(); i++) {
			std::cout << temp[a[i]] << "\n";
		}

		std::cout << "\n";
	}
}