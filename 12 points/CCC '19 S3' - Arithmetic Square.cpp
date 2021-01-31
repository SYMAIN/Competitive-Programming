#include <iostream>

std::string s[3][3];
int grid[3][3];

void PrintArr () {
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void OneXs () {
	int T = 2;
	while (T--) {
		// Do rows
		for (int i=0; i<3; i++) {
			int countX = 0, col = 0;
			for (int j=0; j<3; j++) {
				if (s[i][j] == "X") {
					countX++;
					col = j;
				}
			}
			if (countX == 1) {
				if (col == 0) grid[i][0] = 2 * grid[i][1] - grid[i][2];
				else if (col == 1) grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
				else if (col == 2) grid[i][2] = 2 * grid[i][1] - grid[i][0];
				s[i][col] = "$";
			}
		}
		// Do columns
		for (int i=0; i<3; i++) {
			int countX = 0, row = 0;
			for (int j=0; j<3; j++) {
				if (s[j][i] == "X") {
					++countX;
					row = j;
				}
			}
			if (countX == 1) {
				if (row == 0) grid[0][i] = 2 * grid[1][i] - grid[2][i];
				if (row == 1) grid[1][i] = (grid[0][i] + grid[2][i]) / 2;
				if (row == 2) grid[2][i] = 2 * grid[1][i] - grid[0][i];
				s[row][i] = "$";
			}
		}
		// PrintArr();
	}
}

void MoreXs (int row) {
	int countX = 0, notXcol = 0;
	for (int i=0; i<3; i++) {
		if (s[row][i] == "X") ++countX;
		else notXcol = i;
	}
	if (countX == 2) {
		for (int i=0; i<3; i++) {
			grid[row][i] = grid[row][notXcol];
			s[row][i] = "$";
		}
	}
	if (countX == 3) {
		for (int i=0; i<3; i++) {
			grid[row][i] = 0;
			s[row][i] = "$";
		}
	}
	// PrintArr();
}

int main () {
	int countX = 0, notX = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			std::cin >> s[i][j];
			if (s[i][j] == "X") {
				++countX;
				continue;
			}
			notX = stoi(s[i][j]);
			grid[i][j] = stoi(s[i][j]);
		}
	}
	if (countX == 9) { // 1st edge case
		countX = 0;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				grid[i][j] = 1;
			}
		}
		PrintArr();
		return 0;
	}
	if (countX == 8) { // 2nd edge case
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				grid[i][j] = notX;
			}
		}
		PrintArr();
		return 0;
	}
	OneXs();
	MoreXs(1);
	OneXs();
	MoreXs(0);
	OneXs();
	PrintArr();
	return 0;
}