#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> p;
typedef std::vector<p> VEC;

VEC getNeighbors(p node)
{
	int dir[16] = { -2,1,  -1,2,  1,2,  2,1,  2,-1,  -1,-2,  -1,-2,  -2,-1 };
	VEC neighbors;
	for (int i = 0; i < 16; i += 2)
	{
		int x = node.second + dir[i + 1];
		int y = node.first + dir[i];
		if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
			neighbors.push_back({ y,x });
	}return neighbors;
}

bool checkIn(std::vector<std::pair<p, bool>> arry, p child)
{
	for (auto a:arry)
		if (a.first == child)
			return true;
	return false;
}

VEC bfs(p start, p end)
{
	VEC qu = { start };
	std::vector<std::pair<p, p>> prev;
	std::vector<std::pair<p, bool>> visited;

	while (qu.size() != 0)
	{
		p node = qu[0];
		qu.erase(qu.begin());

		if (node == end)
		{
			p current = node;
			VEC path;
			while (current != start)
			{
				path.push_back(current);
				for (auto p: prev)
				{
					if (p.second == current)
					{
						current = p.first;
						break;
					}
				}
			}return path;
		}
		VEC neighbors = getNeighbors(node);

		for (auto child : neighbors)
		{
			if (!checkIn(visited, child))
			{
				visited.push_back({ child, true });
				qu.push_back(child);
				prev.push_back({ node,child });
			}
		}
	}
}

int main()
{
	p start;
	p end;

	std::cin >> start.first >> start.second;
	std::cin >> end.first >> end.second;

	VEC path = bfs(start, end);
	std::cout << path.size();
}