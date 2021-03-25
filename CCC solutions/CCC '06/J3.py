list = []
time_needed_to_press = 0
totallist = []
consecutive = {"a": "abc",
               "b": "abc",
               "c": "abc",
               "d": "def",
               "e": "def",
               "f": "def",
               "g": "ghi",
               "h": "ghi",
               "i": "ghi",
               "j": "jkl",
               "k": "jkl",
               "l": "jkl",
               "m": "mno",
               "n": "mno",
               "o": "mno",
               "p": "pqrs",
               "q": "pqrs",
               "r": "pqrs",
               "s": "pqrs",
               "t": "tuv",
               "u": "tuv",
               "v": "tuv",
               "w": "wxyz",
               "x": "wxyz",
               "y": "wxyz",
               "z": "wxyz"}
num = {"a": 1,
       "b": 2,
       "c": 3,
       "d": 1,
       "e": 2,
       "f": 3,
       "g": 1,
       "h": 2,
       "i": 3,
       "j": 1,
       "k": 2,
       "l": 3,
       "m": 1,
       "n": 2,
       "o": 3,
       "p": 1,
       "q": 2,
       "r": 3,
       "s": 4,
       "t": 1,
       "u": 2,
       "v": 3,
       "w": 1,
       "x": 2,
       "y": 3,
       "z": 4}
while True:
    a = input()
    if a == "halt":
        break
    list.append(a)

for i in range(len(list)):
    for j in range(len(list[i])):
        time_needed_to_press += num[list[i][j]]
        for k in range(len(list[i])):
            if j + 1 > len(list[i])-1:
                break
            elif list[i][j] in consecutive[list[i][j]] and list[i][j + 1] in consecutive[list[i][j]]:
                time_needed_to_press += 2
                break
    totallist.append(time_needed_to_press)
    time_needed_to_press = 0

for i in range(len(totallist)):
    print(totallist[i])