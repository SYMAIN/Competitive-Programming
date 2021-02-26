#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

std::unordered_map<int,int> t = { {1,1},
	{6,9},
	{8,8},
	{9,6},
	{0,0}
};

bool check(int n) {
	std::stringstream s;
	s << n;
	std::string str;
	s >> str;

	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		int a = str[i]-48;
		for (auto j : t)
			if (j.first == a) {
				str[i] = j.second + 48;
				count++;
				break;
			}
	}
	std::reverse(str.begin(), str.end());
	std::stringstream in(str);
	int x = 0;
	in >> x;
	if (count == str.size() && x == n) return true;
	else return false;
}

int main() {
	int a, b, count=0;
	std::cin >> a >> b;
	for (int i = a; i <= b; i++)
		if (check(i))
			count++;
	std::cout << count;
}