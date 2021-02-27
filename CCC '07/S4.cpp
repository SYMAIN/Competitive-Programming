def dfs(current):
    if nodePaths[current] != 0:
        return nodePaths[current]
    elif current == n:
        return 1
    path, neighbors = 0, dict.get(current)
    for i in neighbors:
        paths = dfs(i)
        nodePaths[i] = paths
        path += paths
    return path


n = int(input())
dict, nodePaths = {}, {}
while 1:
    a, b = map(int, input().split())
    if a == 0 == b: break
    nodePaths[a], nodePaths[b] = 0, 0
    try:
        dict[a] = dict[a] + [b]
    except KeyError:
        dict[a] = [b]

try:
    print(dfs(1))
except KeyError:
    print(0)