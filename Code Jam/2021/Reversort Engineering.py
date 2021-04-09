"""
Did not solve last test case
"""


from itertools import permutations
def reverse(s,i,j):
    newList = []
    for k in range(0,i):
        newList.append(s[k])
    for k in range(j,i-1,-1):
        newList.append(s[k])
    for k in range(j+1,len(s)):
        newList.append(s[k])
    return newList

def reversort(s):
    cnt = 0
    for i in range(0, len(s)-1):
        j = 0
        MIN = 1000000000000
        for k in range(i, len(s)):
            if (s[k] < MIN):
                MIN = s[k]
                j = k
        s = reverse(s,i,j)
        cnt += j-i+1
    return cnt

def solve(s,n):
    for i in permutations(s):
        if (reversort(i) == n):
            return i
    return "IMPOSSIBLE"


for i in range(int(input())):
    n,cnt = map(int,input().split())
    s = [i for i in range(1,n+1)]
    res = solve(s,cnt)
    print(f"Case #{i + 1}: ",end="")
    if res != "IMPOSSIBLE":
        for i in res:
            print(i,end=" ")
    else:
        print(res,end="")
    print()

