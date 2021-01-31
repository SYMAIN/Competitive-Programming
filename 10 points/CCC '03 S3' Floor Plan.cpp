#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// CCC '03S3' Floor Plan

typedef std::pair<int, int> PII;

int r, c;

PII getNode(std::map<PII, bool> visited) {
	for (auto vis : visited) {
		if (vis.second == false) {
			return vis.first;
		}
	}return { -1,-1 };
}

int max(std::vector<std::vector<PII>>& room, std::vector<int>& used) {
	int n = 0, idx=0;
	for (int i = 0; i < room.size(); i++) {
		if (n < room[i].size() && std::find(used.begin(), used.end(), i) == used.end()) {
			idx = i;
			n = room[i].size();
		}
	}used.push_back(idx);
	return idx;
}

void bfs(std::map<PII, char> graph, std::map <PII, int>& roomsPtr, std::map<PII, bool>& visitedPtr, PII NODE, int n) {
	std::vector<PII> qu = { NODE };

	while (!qu.empty()) {
		PII node = qu[0];
		qu.erase(qu.begin());
		visitedPtr[node] = true;
		roomsPtr[node] = n;

		int dir[8] = { -1,0, 1,0, 0,1, 0,-1 };
		for (int d = 0; d < 8; d += 2) {
			int y = dir[d], x = dir[d + 1];
			PII child = { node.first + y, node.second + x };
			if (child.first >= 0 && child.first < r && child.second >= 0 && child.second < c && graph[child]== '.') {
				if (!visitedPtr[child]) {
					qu.push_back(child);
				}
			}
		}
	}return;
}

int _bfs(std::map <PII, char> graph, std::map <PII, int>& roomsPtr) {
	std::map<PII, bool> visited;
	for (auto r : roomsPtr) {
		visited[r.first] = false;
	}
	int n = 1;

	while (true) { // visit all the nodes and mark your rooms
		PII node = getNode(visited);
		if (node.first == -1 && node.second == -1)
			return n; // no more rooms
		else {
			bfs(graph, roomsPtr, visited, node, n);
			n++;
		}
	}return n;
}

int main() {
	int floor;
	std::string a;
	std::map <PII, char> graph;
	std::map <PII, int> rooms;
	std::cin >> floor >> r >> c;

	for (int row = 0; row < r; row++) {
		std::cin >> a;
		for (int col = 0; col < c; col++) {
			graph[{row, col}] = a[col];  //save room layout
			if (a[col] == '.')
				rooms[{row, col}] = -1; // default init
		}
	}
	int m = _bfs(graph, rooms);

	//synchronize the rooms
	std::vector<std::vector<PII>> room(m);  // {{{1,1},{1,2},{1,3}}}
	for (auto r : rooms) {
		room[r.second].push_back(r.first); // saving cor base on room id
	}
	int rn = 0;
	std::vector<int> used;
	while (rn != m - 1) {
		int idx = max(room, used);
		int remain = floor - room[idx].size();
		if (remain >= 0) {
			floor = remain;
			rn++;
		}else
			break;
	}if (rn == 1) {
		std::cout << rn << " room, " << floor << " square metre(s) left over";
	}
	else {
		std::cout << rn << " rooms, " << floor << " square metre(s) left over";
	}

}
