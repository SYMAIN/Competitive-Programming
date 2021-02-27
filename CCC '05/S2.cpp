#include<iostream>

int main() {
	int x, y, sx=0, sy=0;
	int bx, by;
	std::cin >> bx >> by;
	std::cin >> x >> y;
	while (x != 0 || y != 0) {
		if (sx + x >= bx) x = bx - sx;
		if (sx + x <= 0) x = -sx;
		if (sy + y >= by) y = by - sy;
		if (sy + y <= 0) y = -sy;

		sx += x; sy += y;
		std::cout << sx << " " << sy << "\n";
		std::cin >> x >> y;
	}
}