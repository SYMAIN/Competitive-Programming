#include <iostream>
#include <vector>

int main() {
	int n, a, b, p;
	std::cin >> n;
	std::vector<float> stream;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		stream.push_back(a);
	} std::cin >> b;
	while (b != 77) {
		if (b == 99) {
			std::cin >> n >> p;
			float save = stream[n - 1];
			float tmp = (float)stream[n-1] * ((float)p / 100);
			stream[n - 1] = tmp;
			stream.insert(stream.begin() + n, save - tmp);
		} else if (b == 88) {
			std::cin >> n;
			stream[n-1] += stream[n];
			stream.erase(stream.begin() + n);
		}
		std::cin >> b;
	}
	for (auto s : stream)
		std::cout << s << " ";
}