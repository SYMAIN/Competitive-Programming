#include <iostream>
#include <unordered_map>
#include <vector>

// CCC '01 S3 - Strategic Bombing

int findIdx(std::vector<char> vec, char element) {
	for (auto i = 0; i < vec.size(); i++) {
		if (vec[i] == element) {
			return i;
		}
	}return -1;
}

bool bfs(std::unordered_map<char, std::vector<char>> edges, char edge1, char edge2) {
	char start = 'A', end = 'B';
	std::vector<char> qu = { start };
	std::unordered_map<char, bool> visited;

	while (!qu.empty()) {
		char node = qu[0];
		qu.erase(qu.begin());
		visited[node] = true;

		if (node == end) {
			return true;
		}

		std::vector<char> neighbors;
		for (auto edge : edges) {
			if (edge.first == node) {
				neighbors = edge.second;
				if (edge.first == edge1) {
					int idx = findIdx(neighbors, edge2);
					if (idx != -1) {
						neighbors.erase(neighbors.begin() + idx);  // erase the edge
					}
				}
				else if (edge.first == edge2) {
					int idx = findIdx(neighbors, edge1);
					if (idx != -1) {
						neighbors.erase(neighbors.begin() + idx);  // erase the edge
					}
				}
				break;
			}
		}

		for (auto child : neighbors) {
			if (visited[child] == 0) { // not visited
				qu.push_back(child);
			}
		}
	}return false;
}

int main() {
	std::string input;
	std::unordered_map<char, std::vector<char>> edges;
	std::vector<std::string> EDGES;
	std::cin >> input;
	while (input != "**") {
		char edge1 = input[0], edge2 = input[1];
		if (edges[edge1].size() != 0 || edges[edge2].size() != 0) {// saving 2 direction
			edges[edge1].push_back(edge2);
			edges[edge2].push_back(edge1);
		}
		else {
			edges[edge1].push_back(edge2);
			edges[edge2].push_back(edge1);
		}

		EDGES.push_back(input);
		std::cin >> input;
	}
	int cnt = 0;
	for (auto edge : EDGES) {
		bool v = bfs(edges, edge[0], edge[1]);
		if (v == 0) {
			std::cout << edge << "\n";
			cnt++;
		}
	}std::cout << "There are " << cnt << " disconnecting roads." << "\n";
}