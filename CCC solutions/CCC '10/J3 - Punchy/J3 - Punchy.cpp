#include <iostream>
#include <string>
#include <cmath>

int X=0, Y = 0;

void instructions(int instru, char var, char value) {
	if (instru == 1) {
		if (var == 'A') X = value;
		else if (var == 'B') Y = value;
	}
	else if (instru == 2) {
		if (var == 'A') std::cout << X << "\n";
		else if (var == 'B') std::cout << Y << "\n";
	}
	else if (instru == 3) {
		if (var == 'A' && value=='A') X = X + X;
		else if (var == 'A' && value == 'B') X = X + Y;
		else if (var == 'B' && value == 'A') Y = Y + X;
		else if (var == 'B' && value == 'B') Y = Y + Y;
	}
	else if (instru == 4) {
		if (var == 'A' && value == 'A') X = X * X;
		else if (var == 'A' && value == 'B') X = X * Y;
		else if (var == 'B' && value == 'A') Y = Y * X;
		else if (var == 'B' && value == 'B') Y = Y * Y;
	}
	else if (instru == 5) {
		if (var == 'A' && value == 'A') X = X - X;
		else if (var == 'A' && value == 'B') X = X - Y;
		else if (var == 'B' && value == 'A') Y = Y - X;
		else if (var == 'B' && value == 'B') Y = Y - Y;
	}
	else if (instru == 6) {
		if (var == 'A' && value == 'A') X = float(X / X);
		else if (var == 'A' && value == 'B') X = float(X / Y);
		else if (var == 'B' && value == 'A') Y = float(Y / X);
		else if (var == 'B' && value == 'B') Y = float(Y / Y);
	}
}

int main() {
	int instru = 0;
	char var, value;
	int VALUE;
	std::cin >> instru;
	while (instru != 7) {
		if (instru == 2) {
			std::cin >> var;
			instructions(instru, var, value);
		}
		else if (instru == 1) {
			std::cin >> var;
			std::cin >> VALUE;
			value = VALUE;
			instructions(instru, var, value);
		}
		else {
			std::cin >> var;
			std::cin >> value;
			instructions(instru, var, value);
		}
		std::cin >> instru;
	}
}