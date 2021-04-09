#include <iostream>
#include <climits>

typedef long long ll;

ll N,P,W,D,C;
ll upper=0, lower=LLONG_MAX;
ll arr[200000][3];

ll calTime(ll c) {
	ll t = 0;
	for (int i = 0; i < N; i++) {
		P = arr[i][0], W = arr[i][1], D = arr[i][2];

		ll left = c - D;
		ll right = c + D;

		if (P >= left && P <= right) {
			continue;
		}
		ll distance = std::min(abs(P - left), abs(P - right));
		t += distance * W;
	}return t;
}

int main() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	std::cin >> N;
	for (ll i = 0; i < N; i++) {
		std::cin >> P >> W >> D;
		arr[i][0] = P, arr[i][1] = W, arr[i][2] = D;

		if (P > upper) {
			upper = P;
		}
		if (P < lower) {
			lower = P;
		}
	}

	while (1) {
		ll c = (upper + lower) / 2;
		ll cTime = calTime(c);
		C = cTime;

		if (calTime(c - 1) < cTime) {
			upper = c;
		}
		else if (calTime(c + 1) < cTime) {
			lower = c;
		}
		else {
			break;
		}
	}std::cout << C;
}