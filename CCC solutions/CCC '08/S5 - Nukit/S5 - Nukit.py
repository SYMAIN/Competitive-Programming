reactions = [(2, 1, 0, 2), (1, 1, 1, 1), (0, 0, 2, 1), (0, 3, 0, 0), (1, 0, 0, 1)]
dict = {}


def check(current, idx):
    temp = [current[j[0]] - j[1] for j in enumerate(reactions[idx]) if current[j[0]] - j[1] >= 0]
    if len(temp) == 4: return [True, tuple(temp)]
    else: return [False, tuple(temp)]


def dfs(current):
    if current in dict: return not dict[current]
    else:
        dict[current] = False
        for i in range(5):
            temp = check(current,i)
            if temp[0]: dict[current] = dfs(temp[1])
            if dict[current]: return not dict[current]
    return not dict[current]

particles = [tuple(map(int, input().split())) for i in range(int(input()))]
for i in particles:
    print("Patrick") if not dfs(i) else print("Roland")