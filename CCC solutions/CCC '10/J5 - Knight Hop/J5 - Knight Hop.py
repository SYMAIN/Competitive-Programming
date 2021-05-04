from collections import deque

change = [(1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1), (-2, 1), (-1, 2)]
start = tuple(map(int, input().split(" ")))
end = tuple(map(int, input().split(" ")))
grid = {}


def graph(current):
    temp = []
    for i in range(1, 9):
        if current[0] + change[i - 1][0] > 8 or current[0] + change[i - 1][0] <= 0 or current[1] + change[i - 1][
            1] > 8 or current[1] + change[i - 1][1] <= 0:
            continue
        temp.append((current[0] + change[i - 1][0], current[1] + change[i - 1][1]))
    grid[current] = temp


def solve(start):
    qu = deque()
    qu.append(start)

    visited = {}
    prev = {}
    for x in range(1, 9):
        for y in range(1, 9):
            visited[(x, y)] = False
            prev[(x, y)] = None

    while len(qu) != 0:
        node = qu.popleft()
        neighbours = grid.get(node)

        for i in neighbours:
            if not visited[i]:
                graph(i)
                visited[i] = True
                qu.append(i)
                prev[i] = node
    return prev


def reconstructPath(start, end, prev):
    path = []
    currNode = prev[end]
    while currNode != start:
        path.append(currNode)
        currNode = prev[currNode]
    path.reverse()
    return path


def BFS(start, end):
    if start == end:
        return 0
    graph(start)
    prev = solve(start)
    return len(reconstructPath(start, end, prev)) + 1


print(BFS(start, end))