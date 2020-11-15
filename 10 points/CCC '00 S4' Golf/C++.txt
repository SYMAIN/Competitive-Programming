#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// CCC '00 S4' Golf

std::unordered_map<int, int> dp; // the faster/least amount of clubs needed for a distance
std::vector<int> clubs;

int bfs(int total, int nclubs) {
	std::vector<int> qu = { 0 };
	std::unordered_map<int, int> level;

	while (!qu.empty()) {
		int node = qu[0];
		int currentLevel = dp[node];
		qu.erase(qu.begin());

		if (node == total) {
			return level[node];
		}
		if (dp.find(total - node) != dp.end()) { // remaining distance in save
			dp[total] = dp[total - node] + dp[node];
			return dp[total];
		}
		for (int i = 0; i < nclubs; i++) {
			int newDistance = node + clubs[i];
			if (newDistance > total) {
				continue;
			}
			else {
				if (dp.find(newDistance) != dp.end()) { // newDistance in dp
					if (dp[newDistance] > currentLevel + 1) {
						dp[newDistance] = currentLevel + 1;
					}continue;
				}
				else {
					qu.push_back(newDistance);
					dp[newDistance] = currentLevel + 1;
				}
			}
		}
	}return -1;
}

int main() {
	int dis, nclub, a;
	std::cin >> dis >> nclub;
	for (int i = 0; i < nclub; i++) {
		std::cin >> a;
		clubs.push_back(a);
	}
	std::sort(clubs.begin(), clubs.end(), std::greater<>());
	int stroke = bfs(dis, nclub);
	if (stroke != -1) {
		std::cout << "Roberta wins in " << stroke << " strokes.";
	}
	else {
		std::cout << "Roberta acknowledges defeat.";
	}
}
