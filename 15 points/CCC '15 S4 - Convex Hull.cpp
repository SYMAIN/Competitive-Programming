#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

typedef std::pair<int, int> PII;
typedef std::array<int, 3> arry3;

struct edge {
	int b, t, k;
	edge(int B, int T, int K) {
		b = B;
		t = T;
		k = K;
	}
};

std::vector<edge> graph[2001];
std::vector<PII> goodPair(2001);  // { {time, hull} }

bool check(std::array<int, 3> newNode, int K, int end) {
	int child = newNode[2];
	PII currPair = std::make_pair(newNode[0], newNode[1]);
	if (newNode[1] >= K) {
		return 0;
	}

	if (child == end) {
		if (newNode[0] < goodPair[child].first) {
			goodPair[child] = currPair;
			return 1;
		}return 0;
	}

	if (currPair == goodPair[child]) {
		return 1;
	}

	if (newNode[0] < goodPair[child].first || newNode[1] < goodPair[child].second) {
		goodPair[child] = currPair;
		return 1;
	}
	return 0;
}

int dijkstra(int start, int end, int K) {
	std::priority_queue<arry3, std::vector<arry3 >, std::greater<arry3 >> qu;  // { {time, hull, int} }
	qu.push({ 0,0, start });
	arry3 node;
	arry3 newNode;

	while (!qu.empty()) {
		node = qu.top();
		qu.pop();

		if (!check(node, K, end)) {
			continue;
		}

		for (edge currEdge : graph[node[2]]) {
			newNode[0] = node[0] + currEdge.t;
			newNode[1] = node[1] + currEdge.k;
			newNode[2] = currEdge.b;

			if (check(newNode, K, end)) {
				qu.push(newNode);
			}
		}
	}
	return goodPair[end].first != INT_MAX ? goodPair[end].first : -1;
}

int main() {
	int K, N, M;
	int a, b, k, t;
	int start, end;

	std::cin >> K >> N >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b >> t >> k;

		graph[a].push_back(edge(b, t, k));
		graph[b].push_back(edge(a, t, k));
	}std::cin >> start >> end;

	for (int i = 1; i <= N; i++) {
		goodPair[i] = { INT_MAX,INT_MAX };
	}

	std::cout << dijkstra(start, end, K);
}