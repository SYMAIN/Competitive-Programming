word = input()
keypad = [["A", "B", "C", "D", "E", "F"],
          ["G", "H", "I", "J", "K", "L"],
          ["M", "N", "O", "P", "Q", "R"],
          ["S", "T", "U", "V", "W", "X"],
          ["Y", "Z", " ", "-", ".", "enter"]]


def findIdx(node):
    for i in range(len(keypad)):
        for j in range(len(keypad[i])):
            if keypad[i][j] == node:
                return (i, j)


def subtract(p1, p2):
    return abs(p1[0] - p2[0]), abs(p1[1] - p2[1])


def main():
    current = (0, 0)
    distance = 0
    for i in word:
        pos = findIdx(i)
        value = subtract(current, pos)
        distance += (value[0] + value[1])
        current = pos
    pos = findIdx("enter")
    value = subtract(current, pos)
    distance += (value[0] + value[1])
    return distance


print(main())