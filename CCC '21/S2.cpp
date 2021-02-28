#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <string>

int solve(std::vector<int> row, std::vector<int> col, std::vector<int> grid, int R, int C) {
	int gold = 0;

	// find dup
	std::unordered_map<int, int> ROW;
	std::unordered_map<int, int> COL;
	for (int i = 0; i < row.size(); i++) {
		ROW[row[i]]++;
	}
	for (int i = 0; i < col.size(); i++) {
		COL[col[i]]++;
	}


	// col
	for (auto col : COL){
		if (col.second % 2 == 0) {
			continue;
		}
		else {
			for (int j = col.first - 1; j < R * C; j += C) {
				if (grid[j] == 0) {
					grid[j] = 1;
					gold++;
				}
				else if (grid[j] == 1) {
					grid[j] = 0;
					gold--;
				}
			}
		}
	}
	//row
	for (auto row : ROW) {
		if (row.second % 2 == 0) {
			continue;
		}
		int cnt = 0; // loop only C time 
		for (int j = (row.first - 1) * C; j < R * C; j++) {
			if (grid[j] == 0) {
				grid[j] = 1;
				gold++;
			}
			else if (grid[j] == 1) {
				grid[j] = 0;
				gold--;
			}
			if (++cnt == C) {
				break;
			}
		}
	}
	return gold;
}


int main() {
	int R, C, K;
	std::cin >> R >> C >> K;
	std::vector<int> row;
	std::vector<int> col;
	std::vector<int> grid(R*C);
	char a;
	int b;
	for (int i = 0; i < K; i++) {
		std::cin >> a >> b;
		if (a == 'R') {
			row.push_back(b);
		}
		if (a == 'C') {
			col.push_back(b);
		}
	}
	std::cout << solve(row, col, grid, R, C);
	return 0;
}