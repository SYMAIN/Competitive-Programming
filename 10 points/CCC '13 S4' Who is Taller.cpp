#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<int, std::vector<int>> tallToShort;
std::unordered_map<int, std::vector<int>> shortToTall;

std::string bfs(int start, int end) {
	std::vector<int> qu = { start };
	std::unordered_map<int, bool> visited;

	while (!qu.empty()) {
		int node = qu[0];
		qu.erase(qu.begin());

		if (node == end) {
			return "yes";
		}
		std::vector<int> neighbor = tallToShort[node];
		for (auto child : neighbor) {
			if (!visited[child]) {
				qu.push_back(child);
				visited[child] = 1;
			}
		}

	}
	qu = { start };
	visited.clear();
	while (!qu.empty()) {
		int node = qu[0];
		qu.erase(qu.begin());

		if (node == end) {
			return "no";
		}
		std::vector<int> neighbor = shortToTall[node];
		for (auto child : neighbor) {
			if (!visited[child]) {
				qu.push_back(child);
				visited[child] = 1;
			}
		}
	}
	return "unknown";
}


int main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;

		tallToShort[x].push_back(y);
		shortToTall[y].push_back(x);
	}int p, q;
	std::cin >> p >> q;

	std::cout << bfs(p, q);
}