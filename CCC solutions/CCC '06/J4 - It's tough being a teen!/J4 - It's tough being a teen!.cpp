#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int a, b;
bool cycle = false;
std::vector<std::vector<int>> tasks{ {},{7,4},{1},{4,5},{},{},{},{} };
std::vector<int> inTasks{ 0,1,0,0,2,1,0,1 };

void addTask(int a, int b) {
	tasks[a].push_back(b);
	inTasks[b]++;
}

void solve() {
	std::priority_queue <int, std::vector<int>, std::greater<int> > pq;
	std::queue<int> output;

	for (int i = 1; i < 8; i++) {
		if (inTasks[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int key = pq.top();
		output.push(key);
		pq.pop();

		for (int i = 0; i < tasks[key].size(); i++) {
			int nodeN = tasks[key][i];
			inTasks[nodeN]--;
			if (inTasks[nodeN] == 0) {
				pq.push(nodeN);
			}
		}
	}
	if (output.size() == 7)
	{
		while (!output.empty())
		{
			std::cout << output.front() << " ";
			output.pop();
		}
	}
	else {
		std::cout << "Cannot complete these tasks. Going to bed.";
	}
}

int main() {
	std::cin.tie(0);
	std::cin.sync_with_stdio(0);

	std::cin >> a >> b;
	while (a != 0 && b != 0) {
		addTask(a, b);
		std::cin >> a >> b;
	}
	solve();

}