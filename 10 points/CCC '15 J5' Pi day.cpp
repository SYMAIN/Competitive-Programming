#include <iostream>
#include <map>

// CCC '15 J5' Pi day

std::map<std::tuple<int, int, int>, int> dp;

int dfs(int nPie, int kPeopleLeft, int pieLeft) {

	if (dp[std::make_tuple(nPie, kPeopleLeft, pieLeft)] != 0) {
		return dp[std::make_tuple(nPie, kPeopleLeft, pieLeft)];
	}

	if (kPeopleLeft == 0 || pieLeft == 0) {
		return 1;
	}

	int ways = 0;
	int a = pieLeft - kPeopleLeft + 1, b = nPie;
	int max = (a < b) ? a : b;
	int min = pieLeft / kPeopleLeft;

	for (int i = max; i > min - 1; i--) {
		ways += dfs(i, kPeopleLeft - 1, pieLeft - i);
	}
	dp[std::make_tuple(nPie, kPeopleLeft, pieLeft)] = ways;
	return ways;
}


int main() {
	int n, k;
	std::cin >> n >> k;

	std::cout << dfs(n, k, n);
}
