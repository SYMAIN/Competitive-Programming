from collections import deque


def graph(current, currentPos):
    if current == "-" and (currentPos[0] - 1 >= 1 or currentPos[0] + 1 <= column):
        dict[currentPos] = (currentPos[0], currentPos[1] - 1), (currentPos[0], currentPos[1] + 1)

    elif current == "|" and (currentPos[1] - 1 >= 1 or currentPos[1] + 1 <= row):
        dict[currentPos] = (currentPos[0] - 1, currentPos[1]), (currentPos[0] + 1, currentPos[1])

    elif current == "+" and (currentPos[1] - 1 >= 1 or currentPos[1] + 1 <= row or currentPos[0] - 1 >= 1 or \
                             currentPos[0] + 1 <= column):
        dict[currentPos] = (currentPos[0] - 1, currentPos[1]), (currentPos[0] + 1, currentPos[1]), (
            currentPos[0], currentPos[1] - 1), (currentPos[0], currentPos[1] + 1)


def bfs(start, startPos, end, endPos):
    qu = deque()
    qu.append(startPos)
    graph(start, startPos)

    visited = {}
    prev = {}
    for i in range(1, row + 1):
        for j in range(1, column + 1):
            visited[(i, j)] = False
            prev[(i, j)] = None

    visited[startPos] = True

    while len(qu) != 0:
        node = qu.popleft()
        neighbours = dict.get(node)
        if neighbours is None:
            continue
        for i in neighbours:
            if i[0] <= 0 or i[0] > row or i[1] <= 0 or i[1] > column:
                continue
            if not visited[i]:
                graph(maze[i[0] - 1][i[1] - 1], i)
                visited[i] = True
                qu.append(i)
                prev[i] = node
    return prev


def reconstructPath(startPos, endPos, prev):
    path = []
    currentNode = prev[endPos]

    while currentNode is not None:
        path.append(currentNode)
        currentNode = prev[currentNode]

    return path


for _ in range(int(input())):
    maze = []
    dict = {}
    row, column = int(input()), int(input())
    for i in range(row):
        maze.append(list(map(str, input())))
    prev = bfs(maze[0][0], (1, 1), maze[row - 1][column - 1], (row, column))
    temp = len(reconstructPath((1, 1), (row, column), prev)) + 1
    if temp == 1 and (row, column) != (1, 1) or maze[row - 1][column - 1] == "*":
        print(-1)
    else:
        print(temp)