#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

typedef long long ll;

ll N, A, B;
std::vector<ll> motels = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
std::unordered_map<ll, ll> dp;
ll solve(ll current) {
	if (dp[current] != 0) {
		return dp[current];
	}
	if (current == 7000) {
		return 1;
	}
	ll lower = current + A;
	ll upper = current + B;

	ll cnt = 0;
	for (int i = 0; i < motels.size(); i++) {
		if (motels[i] >= lower && motels[i] <= upper) {
			cnt += solve(motels[i]);
		}if (motels[i] > upper) {
			break;
		}
	}
	dp[current] = cnt;
	return cnt;
}

int main() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	std::cin >> A >> B >> N;
	ll n;

	for (ll i = 0; i < N; i++) {
		std::cin >> n;
		motels.push_back(n);
	}
	std::sort(motels.begin(), motels.end());
	
	std::cout << solve(0) << "\n";
}