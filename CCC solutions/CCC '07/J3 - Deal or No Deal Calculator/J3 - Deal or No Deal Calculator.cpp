#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int breifCase[10] = { 100,500,1000,5000,10000,25000,50000,100000,500000,1000000 };

	int a,bank;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		breifCase[a - 1] = 0;
	}
	int average = 0;
	for (int i = 0; i < 10; i++) {
		average += breifCase[i];
	}
	std::cin >> bank;
	average = average / (10-n);
	if (average > bank)
		std::cout << "no deal";
	else
		std::cout << "deal";
}