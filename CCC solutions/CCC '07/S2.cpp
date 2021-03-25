#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<int>> boxes;
std::vector<std::vector<int>> items;

void premu(std::vector<int> a, int l, int r, std::vector<std::vector<int>>& all) {
	if (l == r) {
		all.push_back(a);
	}
	for (int i = l; i <= r; i++) {
		std::swap(a[l], a[i]);
		premu(a, l+1, r, all);
		std::swap(a[l], a[i]);
	}
}

void solve() {
	for (int i = 0; i < items.size(); i++) {
		int l = items[i][0];
		int w = items[i][1];
		int h = items[i][2];
		std::vector<std::vector<int>> all;
		std::vector<int> a = { l,w,h };
		std::vector<long long> save;
		premu(a, 0, 2, all);

		for (int j = 0; j < boxes.size(); j++) {
			int l1 = boxes[j][0];
			int w1 = boxes[j][1];
			int h1 = boxes[j][2];

			for (int k = 0; k < all.size(); k++) {
				int l2 = all[k][0];
				int w2 = all[k][1];
				int h2 = all[k][2];

				if (l2 <= l1 && w2 <= w1 && h2 <= h1) {
					save.push_back(l1 * w1 * h1);
				}
			}
		}
		if (save.size() == 0) {
			std::cout << "Item does not fit.\n";
		}
		else {
			long long m = LLONG_MAX;
			for (int j = 0; j < save.size(); j++) {
				if (save[j] < m) {
					m = save[j];
				}
			}std::cout << m << "\n";
		}
	}
}

int main() {
	int n,m;
	std::cin >> n;

	int h, w, l;
	for (int i = 0; i < n; i++) {
		std::cin >> l >> w >> h;
		boxes.push_back({l, w, h});
	}
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> l >> w >> h;
		items.push_back({l, w, h});
	}
	solve();
}